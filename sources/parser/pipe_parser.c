/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:00:48 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 18:00:51 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_pipe(t_command **cmd, t_token **token_lst)
{
	t_command	*last_cmd;

	last_cmd = lst_last_cmd(*cmd);
	last_cmd->pipe_output = true;
	add_cmd_back(&last_cmd, lst_new_cmd(false));
	*token_lst = (*token_lst)->next;
}
