#include "minishell.h"

static bool	syntax_errors(t_token *node)
{
	if (node->prev)
	{
		if (node->type == PIPE && node->prev->type >= PIPE)
		{
			g_sig = 258;
			return (true);
		}
		if (node->type > PIPE && node->prev->type > PIPE)
		{
			g_sig = 258;
			return (true);
		}
		if (node->type == END && node->prev->type >= PIPE)
		{
			g_sig = 258;
			return (true);
		}
	}
	return (false);
}

/*
 * If the last token is a redirection, prints syntax error near unexpected token 
 * `newline', example: echo >
 * 
 * If the last token is a pipe prints syntax error near unexpected token `|',
 * example: echo |
 * 
 * In all other cases: prints syntax error near unexpected token `<<',
 * example, echo > <<
*/
int	valid_syntax(t_token **tokens)
{
	t_token	*tmp;

	tmp = *tokens;
	while (tmp)
	{
		if (syntax_errors(tmp) == true)
		{
			if (tmp->type == END && tmp->prev && tmp->prev->type > PIPE)
				syntax_err_msg("syntax error near unexpected token", \
				"newline", true);
			else if (tmp->type == END && tmp->prev && tmp->prev->type == PIPE)
				syntax_err_msg("syntax error near unexpected token",
					tmp->prev->content, true);
			else
				syntax_err_msg("syntax error near unexpected token", \
				tmp->content, true);
			return (FAILURE);
		}
		tmp = tmp->next;
	}
	return (OK);
}

int	check_syntax(t_token **tokens)
{
	t_token	*tmp;

	tmp = *tokens;
	if (tmp->type == PIPE)
	{
		syntax_err_msg("syntax error near unexpected token", tmp->content, true);
		g_sig = 258;
		return (FAILURE);
	}
	while (tmp)
	{
		if (valid_syntax(&tmp) == FAILURE)
			return (FAILURE);
		tmp = tmp->next;
	}
	return (OK);
}
