/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:00:30 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 18:00:39 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	remove_old_file_ref(t_fds *io, bool infile)
{
	if (infile == true && io->infile)
	{
		if (io->fd_in == -1 || (io->outfile && io->fd_out == -1))
			return (false);
		if (io->heredoc_del != NULL)
		{
			free_ptr(io->heredoc_del);
			io->heredoc_del = NULL;
			unlink(io->infile);
		}
		free_ptr(io->infile);
		close(io->fd_in);
	}
	else if (infile == false && io->outfile)
	{
		if (io->fd_out == -1 || (io->infile && io->fd_in == -1))
			return (false);
		free_ptr(io->outfile);
		close(io->fd_out);
	}
	return (true);
}

static void	open_infile(t_fds *io, char *file, char *original_filename)
{
	if (!remove_old_file_ref(io, true))
		return ;
	io->infile = ft_strdup(file);
	if (io->infile && io->infile[0] == '\0')
	{
		cmd_error_message(original_filename, NULL, "ambiguous redirect", false);
		io->error_msg = true;
		return ;
	}
	io->fd_in = open(io->infile, O_RDONLY);
	if (io->fd_in == -1 && io->error_msg == false)
	{
		cmd_error_message(io->infile, NULL, strerror(errno), false);
		io->error_msg = true;
	}
}

void	parse_input(t_command **last_cmd, t_token **token_lst)
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
	open_infile(cmd->fds, temp->next->content, temp->next->cc);
	if (temp->next->next)
		temp = temp->next->next;
	else
		temp = temp->next;
	*token_lst = temp;
}
