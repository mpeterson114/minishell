/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:15:00 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/11 15:15:27 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	cmd_is_dir(char *cmd)
{
	struct stat	cmd_stat;

	ft_memset(&cmd_stat, 0, sizeof(cmd_stat));
	stat(cmd, &cmd_stat);
	return (S_ISDIR(cmd_stat.st_mode));
}

int	check_command_not_found(t_shell *sh, t_command *cmd)
{
	if (ft_strchr(cmd->command, '/') == NULL
		&& find_env_index_by_key(sh->env, "PATH") != -1)
		return (cmd_error_message(cmd->command, NULL, "command not found",
				CMD_NOT_FOUND));
	if (access(cmd->command, F_OK) != 0)
		return (cmd_error_message(cmd->command, NULL, strerror(errno), \
		CMD_NOT_FOUND));
	else if (cmd_is_dir(cmd->command))
		return (cmd_error_message(cmd->command, NULL, "Is a directory",
				CMD_NOT_EXECUTABLE));
	else if (access(cmd->command, F_OK | X_OK) != 0)
		return (cmd_error_message(cmd->command, NULL, strerror(errno),
				CMD_NOT_EXECUTABLE));
	return (EXIT_SUCCESS);
}
