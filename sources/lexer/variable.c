/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:23:33 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 16:51:59 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	assign_var_type(t_token **node)
{
	int	i;

	i = 0;
	while ((*node)->content[i])
	{
		if ((*node)->content[i] == '$')
		{	
			if ((*node)->prev && (*node)->prev->type == HEREDOC)
				break ;
			(*node)->type = VAR;
			return ;
		}
		i++;
	}
}

int	check_variable(t_token **tokens)
{
	t_token	*tmp;

	tmp = *tokens;
	while (tmp)
	{
		assign_var_type(&tmp);
		tmp = tmp->next;
	}
	return (OK);
}
