/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:53:54 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 16:54:12 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	prep_commands_list(t_shell *sh)
{
	t_command	*new_cmd;

	if (!sh || !sh->cmd)
		return ;
	new_cmd = sh->cmd;
	while (new_cmd && new_cmd->command)
	{
		if (!new_cmd->args)
		{
			new_cmd->args = malloc(sizeof * new_cmd->args * 2);
			new_cmd->args[0] = ft_strdup(new_cmd->command);
			new_cmd->args[1] = NULL;
		}
		new_cmd = new_cmd->next;
	}
	new_cmd = lst_last_cmd(sh->cmd);
}

void	create_commands(t_shell *sh, t_token *token)
{
	t_token	*temp;

	temp = token;
	if (temp->type == END)
		return ;
	while (temp->next != NULL)
	{
		if (temp == token)
			add_cmd_back(&sh->cmd, lst_new_cmd(false));
		if (temp->type == WORD || temp->type == VAR)
			parse_word(&sh->cmd, &temp);
		else if (temp->type == INPUT)
			parse_input(&sh->cmd, &temp);
		else if (temp->type == TRUNC)
			parse_trunc(&sh->cmd, &temp);
		else if (temp->type == HEREDOC)
			parse_heredoc(sh, &sh->cmd, &temp);
		else if (temp->type == APPEND)
			parse_append(&sh->cmd, &temp);
		else if (temp->type == PIPE)
			parse_pipe(&sh->cmd, &temp);
		else if (temp->type == END)
			break ;
	}
	prep_commands_list(sh);
}
