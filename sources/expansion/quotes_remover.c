/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_remover.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 06:01:40 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/14 10:49:04 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_q_status(t_token **node, int *pos)
{
	if ((*node)->content[*pos] == '\'')
		(*node)->q_status = SQ;
	if ((*node)->content[*pos] == '\"')
		(*node)->q_status = DQ;
	(*pos)++;
}

static bool	is_quote_and_qok(t_token **node, int pos)
{
	if (((*node)->content[pos] == '\'' || (*node)->content[pos] == '\"')
		&& (*node)->q_status == QOK)
		return (true);
	else
		return (false);
}

static bool	is_quote_updt_to_qok(t_token **node, int *pos)
{
	if (((*node)->content[*pos] == '\'' && (*node)->q_status == SQ)
		|| ((*node)->content[*pos] == '\"' && (*node)->q_status == DQ))
	{
		(*node)->q_status = QOK;
		(*pos)++;
		return (true);
	}
	else
		return (false);
}

int	remove_quotes(t_token **node)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * count_len_without_q((*node)->content, i, i));
	if (!new)
		return (FAILURE);
	while ((*node)->content[i])
	{
		if (is_quote_and_qok(node, i) == true)
		{
			update_q_status(node, &i);
			continue ;
		}
		else if (is_quote_updt_to_qok(node, &i) == true)
			continue ;
		new[j++] = (*node)->content[i++];
	}
	new[j] = '\0';
	free_ptr((*node)->content);
	(*node)->content = new;
	(*node)->has_quotes = true;
	return (OK);
}
