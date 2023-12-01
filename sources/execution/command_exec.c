/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 07:12:56 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/17 18:00:10 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_builtin(t_shell *sh, t_command *cmd)
{
	int	ret;

	ret = CMD_NOT_FOUND;
	if (ft_strncmp(cmd->command, "cd", 3) == 0)
		ret = cd_builtin(sh, cmd->args);
	else if (ft_strncmp(cmd->command, "echo", 5) == 0)
		ret = echo_builtin(sh, cmd->args);
	else if (ft_strncmp(cmd->command, "env", 4) == 0)
		ret = env_builtin(sh, cmd->args);
	else if (ft_strncmp(cmd->command, "export", 7) == 0)
		ret = export_builtin(sh, cmd->args);
	else if (ft_strncmp(cmd->command, "pwd", 4) == 0)
		ret = pwd_builtin(sh, cmd->args);
	else if (ft_strncmp(cmd->command, "unset", 6) == 0)
		ret = unset_builtin(sh, cmd->args);
	else if (ft_strncmp(cmd->command, "exit", 5) == 0)
		ret = exit_builtin(sh, cmd->args);
	return (ret);
}

static int	execute_sys_bin(t_shell *sh, t_command *cmd)
{
	if (!cmd->command || cmd->command[0] == '\0')
		return (CMD_NOT_FOUND);
	if (cmd_is_dir(cmd->command))
		return (CMD_NOT_FOUND);
	cmd->path = get_cmd_path(sh, cmd->command);
	if (!cmd->path)
		return (CMD_NOT_FOUND);
	if (execve(cmd->path, cmd->args, sh->env) == -1)
		cmd_error_message("execve", NULL, strerror(errno), errno);
	return (EXIT_FAILURE);
}

static int	execute_local_bin(t_shell *sh, t_command *cmd)
{
	int	ret;

	ret = check_command_not_found(sh, cmd);
	if (ret != 0)
		return (ret);
	if (execve(cmd->command, cmd->args, sh->env) == -1)
		return (cmd_error_message("execve", NULL, strerror(errno), errno));
	return (EXIT_FAILURE);
}

int	command_exec(t_shell *sh, t_command *cmd)
{
	int	ret;

	if (!io_check(cmd->fds))
		exit_minishell(sh, EXIT_FAILURE);
	set_pipe_fds(sh->cmd, cmd);
	redirect_io(cmd->fds);
	close_fds(sh->cmd, false);
	if (ft_strchr(cmd->command, '/') == NULL)
	{
		ret = execute_builtin(sh, cmd);
		if (ret != CMD_NOT_FOUND)
			exit_minishell(sh, ret);
		ret = execute_sys_bin(sh, cmd);
		if (ret != CMD_NOT_FOUND)
			exit_minishell(sh, ret);
	}
	ret = execute_local_bin(sh, cmd);
	exit_minishell(sh, ret);
	return (ret);
}
