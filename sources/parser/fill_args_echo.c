/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_args_echo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:59:50 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/14 11:54:41 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_empty_var_args(t_token **tokens)
{
	t_token	*temp;

	temp = *tokens;
	while (temp->type == WORD || temp->type == VAR)
	{
		if (temp->type == VAR && temp->content[0] == '\0' && \
		temp->is_var == 0 && temp->has_quotes == 0)
		{
			temp = temp->next;
			if (temp == (*tokens)->next)
				(*tokens) = (*tokens)->next;
			lstdelone_token(temp->prev, free_ptr);
		}
		else if (temp->type == VAR && temp->content[0] == '\0' && \
		temp->has_quotes == false)
		{
			temp = temp->next;
			if (temp == (*tokens)->next)
				(*tokens) = (*tokens)->next;
			lstdelone_token(temp->prev, free_ptr);
		}
		else
			temp = temp->next;
	}
}

int	create_args_echo_mode(t_token **token_node, t_command *last_cmd)
{
	int		nb_args;
	t_token	*temp;
	int		i;

	remove_empty_var_args(token_node);
	temp = *token_node;
	nb_args = count_arguments(temp);
	last_cmd->args = malloc(sizeof(char *) * (nb_args + 2));
	if (!last_cmd->args)
		return (FAILURE);
	i = 0;
	last_cmd->args[i] = ft_strdup(last_cmd->command);
	i++;
	while (temp->type == WORD || temp->type == VAR)
	{
		last_cmd->args[i] = ft_strdup(temp->content);
		i++;
		temp = temp->next;
	}
	last_cmd->args[i] = NULL;
	*token_node = temp;
	return (OK);
}

int	add_args_echo_mode(t_token **token_node, t_command *last_cmd)
{
	int		len;
	int		nb_args;
	char	**new_tab;
	t_token	*temp;

	remove_empty_var_args(token_node);
	temp = *token_node;
	nb_args = count_arguments(temp);
	len = 0;
	while (last_cmd->args[len])
		len++;
	new_tab = malloc(sizeof(char *) * (nb_args + len + 1));
	if (!new_tab)
		return (FAILURE);
	new_tab = copy_in_new_tab(len, new_tab, last_cmd, token_node);
	free(last_cmd->args);
	last_cmd->args = new_tab;
	len = 0;
	while (temp->type == WORD || temp->type == VAR)
		temp = temp->next;
	*token_node = temp;
	return (OK);
}
