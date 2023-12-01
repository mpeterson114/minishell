/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trunc_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:01:12 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 18:01:33 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	open_outfile_trunc(t_fds *io, char *file, char *var_filename)
{
	if (!remove_old_file_ref(io, false))
		return ;
	io->outfile = ft_strdup(file);
	if (io->outfile && io->outfile[0] == '\0' && io->error_msg == false)
	{
		cmd_error_message(var_filename, NULL, "ambiguous redirect", false);
		io->error_msg = true;
		return ;
	}	
	io->fd_out = open(io->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (io->fd_out == -1 && io->error_msg == false)
	{
		cmd_error_message(io->outfile, NULL, strerror(errno), false);
		io->error_msg = true;
	}		
}

void	parse_trunc(t_command **last_cmd, t_token **token_lst)
{
	t_token		*temp;
	t_command	*cmd;

	temp = *token_lst;
	cmd = lst_last_cmd(*last_cmd);
	if (cmd->fds && cmd->fds->error_msg && cmd->fds->error_msg == true)
	{
		if (temp->next->next)
			temp = temp->next->next;
		else
			temp = temp->next;
		*token_lst = temp;
		return ;
	}
	init_input_output(cmd);
	open_outfile_trunc(cmd->fds, temp->next->content, temp->next->cc);
	if (temp->next->next)
		temp = temp->next->next;
	else
		temp = temp->next;
	*token_lst = temp;
}
