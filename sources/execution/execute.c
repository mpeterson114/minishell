/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:16:28 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/17 17:53:46 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_sig;

static int	get_child_status(t_shell *sh)
{
	pid_t	wpid;
	int		status;
	int		save_status;

	close_fds(sh->cmd, false);
	save_status = 0;
	wpid = 0;
	while (wpid != -1 || errno != ECHILD)
	{
		wpid = waitpid(-1, &status, 0);
		if (wpid == sh->pid)
			save_status = status;
		continue ;
	}
	if (WIFSIGNALED(save_status))
		status = 128 + WTERMSIG(save_status);
	else if (WIFEXITED(save_status))
		status = WEXITSTATUS(save_status);
	else
		status = save_status;
	return (status);
}

static int	create_children(t_shell *sh)
{
	t_command	*cmd;

	cmd = sh->cmd;
	while (sh->pid != 0 && cmd)
	{
		sh->pid = fork();
		if (sh->pid == -1)
			return (cmd_error_message("fork", NULL, strerror(errno), \
			EXIT_FAILURE));
		else if (sh->pid == 0)
			command_exec(sh, cmd);
		cmd = cmd->next;
	}
	return (get_child_status(sh));
}

static int	prep_for_exec(t_shell *sh)
{
	if (sh->cmd && sh->cmd->command == NULL)
		return (EXIT_FAILURE);
	if (!sh || !sh->cmd || (sh->cmd->command[0] == '\0'
			&& sh->token->has_quotes == false))
		return (EXIT_SUCCESS);
	if (!sh->cmd->command)
	{
		if (sh->cmd->fds
			&& !io_check(sh->cmd->fds))
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	if (!create_pipes(sh))
		return (EXIT_FAILURE);
	return (CMD_NOT_FOUND);
}

int	execute(t_shell *sh)
{
	int	ret;

	ret = prep_for_exec(sh);
	if (ret != CMD_NOT_FOUND)
		return (ret);
	if (!sh->cmd->pipe_output && !sh->cmd->prev
		&& io_check(sh->cmd->fds))
	{
		redirect_io(sh->cmd->fds);
		ret = execute_builtin(sh, sh->cmd);
		restore_io(sh->cmd->fds);
	}
	if (ret != CMD_NOT_FOUND)
		return (ret);
	return (create_children(sh));
}
