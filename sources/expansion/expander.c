/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 23:25:37 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 16:36:22 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_q_status(t_token **node, char c)
{
	if (c == '\'' && (*node)->q_status == QOK)
		(*node)->q_status = SQ;
	else if (c == '\"' && (*node)->q_status == QOK)
		(*node)->q_status = DQ;
	else if (c == '\'' && (*node)->q_status == SQ)
		(*node)->q_status = QOK;
	else if (c == '\"' && (*node)->q_status == DQ)
		(*node)->q_status = QOK;
}

static bool	is_next_char_a_div(char next)
{
	if (next == '$' || next == ' ' || next == '=' || next == '\0')
		return (true);
	else
		return (false);
}

static bool	dollar_between_quotes(char *content, int i)
{
	if (i > 0)
	{
		if (content[i - 1] == '\"' && content[i + 1] == '\"')
			return (true);
		else
			return (false);
	}
	return (false);
}

int	expander(t_shell *sh, t_token **tokens)
{
	t_token	*tmp;
	int		i;

	tmp = *tokens;
	while (tmp)
	{
		if (tmp->type == VAR)
		{
			i = 0;
			while (tmp->content[i])
			{
				update_q_status(&tmp, tmp->content[i]);
				if (tmp->content[i] == '$'
					&& is_next_char_a_div(tmp->content[i + 1]) == false
					&& dollar_between_quotes(tmp->content, i) == false
					&& (tmp->q_status == QOK || tmp->q_status == DQ))
					replace_variable(&tmp, \
					find_value(tmp, tmp->content + i, sh), i);
				else
					i++;
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

char	*var_expander_heredoc(t_shell *sh, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$'
			&& is_next_char_a_div(str[i + 1]) == false
			&& dollar_between_quotes(str, i) == false)
			str = replace_str_heredoc(str, find_value(NULL, str + i, sh), i);
		else
			i++;
	}
	return (str);
}
