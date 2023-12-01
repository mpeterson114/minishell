/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 09:50:28 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 16:41:02 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/**
 * if the last token is a redirection prints syntax error near unexpected token 
 * `newline', example: echo >
 * if the last token is a pipe prints syntax error near unexpected token `|',
 * example: echo |
 * all other cases: prints syntax error near unexpected token `<<',
 * example, echo > <<
*/
int	check_syntax2(t_token **tokens)
{
	t_token	*tmp;

	tmp = *tokens;
	while (tmp)
	{
		if (syntax_errors(tmp) == true)
		{
			if (tmp->type == END && tmp->prev && tmp->prev->type > PIPE)
				syntax_errmsg("syntax error near unexpected token", \
				"newline", true);
			else if (tmp->type == END && tmp->prev && tmp->prev->type == PIPE)
				syntax_errmsg("syntax error near unexpected token",
					tmp->prev->content, true);
			else
				syntax_errmsg("syntax error near unexpected token", \
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
		syntax_errmsg("syntax error near unexpected token", tmp->content, true);
		g_sig = 258;
		return (FAILURE);
	}
	while (tmp)
	{
		if (check_syntax2(&tmp) == FAILURE)
			return (FAILURE);
		tmp = tmp->next;
	}
	return (OK);
}
