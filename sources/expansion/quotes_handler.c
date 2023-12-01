/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 23:33:33 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 16:38:21 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_len_without_q(char *content, int cnt, int i)
{
	int	status;

	status = QOK;
	while (content[i])
	{
		if ((content[i] == '\'' || content[i] == '\"') && status == QOK)
		{
			if (content[i] == '\'')
				status = SQ;
			if (content[i] == '\"')
				status = DQ;
			i++;
			continue ;
		}
		else if ((content[i] == '\'' && status == SQ)
			|| (content[i] == '\"' && status == DQ))
		{
			status = QOK;
			i++;
			continue ;
		}
		cnt++;
		i++;
	}
	return (cnt + 1);
}

bool	quotes_are_found(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (true);
		i++;
	}
	return (false);
}

int	quotes_handler(t_shell *sh)
{
	t_token	*tmp;

	tmp = sh->token;
	while (tmp)
	{
		if (quotes_are_found(tmp->content) == true
			&& (!tmp->prev || (tmp->prev && tmp->prev->type != HEREDOC)))
			remove_quotes(&tmp);
		tmp = tmp->next;
	}
	return (0);
}
