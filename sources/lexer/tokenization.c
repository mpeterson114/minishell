#include "minishell.h"

/*
*	This function divides the given string (user input) into two
*   types of tokens : words or separators (pipes, heredoc , etc)
*	It checks each char of the string and defines if it is a separator or 
*   a word and then saves the token in a linked list.
*   
*	Also checks if there is an unclosed quote error and defines which
*   separators will be evaluated following the single or double quoting rules:
*   
*   -Without quotes, bash tries to evaluate all special characters
*   -Single quotes (') prevent all evaluation
*   -Double quotes (") prevent most evaluation,
*		but notably not the evaluation of variables
*
*/

int	tokenization(t_shell *sh, char *line)
{
	int	i;
	int	end;
	int	start;
	int	q_status;

	i = -1;
	start = 0;
	end = ft_strlen(line);
	q_status = QOK;
	while (++i <= end)
	{
		q_status = update_quote_status(q_status, line, i);
		if (q_status == QOK)
			start = add_word_or_delim(&i, line, start, sh);
	}
	if (q_status != QOK)
	{
		if (q_status == DQ)
			syntax_err_msg("syntax error: unclosed quote:", R "\"" N, true);
		else if (q_status == SQ)
			syntax_err_msg("syntax error: unclosed quote:", R "\'" N, true);
		return (FAILURE);
	}
	return (OK);
}
