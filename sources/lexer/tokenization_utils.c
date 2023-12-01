/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 12:51:12 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 16:51:28 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Ilona
*/
int	add_delim(t_token **tokens, char *line, int pos, int delim_type)
{
	int		i;
	char	*delim;

	i = 0;
	if (delim_type == APPEND || delim_type == HEREDOC)
	{
		delim = malloc(sizeof(char) * 3);
		if (!delim)
			return (FAILURE);
		while (i < 2)
			delim[i++] = line[pos++];
		delim[i] = '\0';
		add_back_tok_lst(tokens, new_token_lst(delim, NULL, delim_type, QOK));
	}
	else
	{
		delim = malloc(sizeof(char) * 2);
		if (!delim)
			return (FAILURE);
		while (i < 1)
			delim[i++] = line[pos++];
		delim[i] = '\0';
		add_back_tok_lst(tokens, new_token_lst(delim, NULL, delim_type, QOK));
	}
	return (OK);
}

/**
 * Ilona
*/
int	add_word(t_token **tokens, char *line, int pos, int start)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (pos - start + 1));
	if (!word)
		return (FAILURE);
	while (start < pos)
	{
		word[i] = line[start];
		start++;
		i++;
	}
	word[i] = '\0';
	add_back_tok_lst(tokens, \
			new_token_lst(word, ft_strdup(word), WORD, QOK));
	return (OK);
}

int	is_delimiter(char *line, int pos)
{
	if (((line[pos] > 8 && line[pos] < 14) || line[pos] == 32))
		return (SPACES);
	else if (line[pos] == '|')
		return (PIPE);
	else if (line[pos] == '<' && line[pos + 1] == '<')
		return (HEREDOC);
	else if (line[pos] == '>' && line[pos + 1] == '>')
		return (APPEND);
	else if (line[pos] == '<')
		return (INPUT);
	else if (line[pos] == '>')
		return (TRUNC);
	else if (line[pos] == '\0')
		return (END);
	else
		return (0);
}

int	updt_quote_status(int status, char *line, int pos)
{
	if (line[pos] == '\'' && status == QOK)
		status = SQ;
	else if (line[pos] == '\"' && status == QOK)
		status = DQ;
	else if (line[pos] == '\'' && status == SQ)
		status = QOK;
	else if (line[pos] == '\"' && status == DQ)
		status = QOK;
	return (status);
}

/**
 * 
 * Ilona
*/
int	add_word_or_delim(int *i, char *line, int start, t_shell *sh)
{
	int	is_delim;

	is_delim = is_delimiter(line, (*i));
	if (is_delim)
	{
		if ((*i) != 0 && !is_delimiter(line, (*i) - 1))
			add_word(&sh->token, line, (*i), start);
		if (is_delim && is_delim != SPACES)
		{
			add_delim(&sh->token, line, (*i), is_delim);
			if (is_delim == APPEND || is_delim == HEREDOC)
				(*i)++;
		}
		start = (*i) + 1;
	}
	return (start);
}
