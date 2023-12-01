/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:06:39 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 18:07:11 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_data(t_shell *sh, bool clearhistory)
{
	if (sh && sh->line)
	{
		free_ptr(sh->line);
		sh->line = NULL;
	}
	if (sh && sh->token)
		lstclear_token(&sh->token, &free_ptr);
	if (sh && sh->cmd)
		lst_clear_cmd(&sh->cmd, &free_ptr);
	if (clearhistory == true)
	{
		if (sh && sh->pwd)
			free_ptr(sh->pwd);
		if (sh && sh->old_pwd)
			free_ptr(sh->old_pwd);
		if (sh && sh->env)
			free_ptr_arr(sh->env);
		clear_history();
	}
}

void	close_fds(t_command *cmds, bool close_backups)
{
	if (cmds->fds)
	{
		if (cmds->fds->fd_in != -1)
			close(cmds->fds->fd_in);
		if (cmds->fds->fd_out != -1)
			close(cmds->fds->fd_out);
		if (close_backups)
			restore_io(cmds->fds);
	}
	close_pipe_fds(cmds, NULL);
}

void	free_io(t_fds *io)
{
	if (!io)
		return ;
	restore_io(io);
	if (io->heredoc_del)
	{
		unlink(io->infile);
		free_ptr(io->heredoc_del);
	}
	if (io->infile)
		free_ptr(io->infile);
	if (io->outfile)
		free_ptr(io->outfile);
	if (io)
		free_ptr(io);
}

void	free_ptr_arr(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i])
			{
				free_ptr(tab[i]);
				tab[i] = NULL;
			}
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

void	free_ptr(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}
