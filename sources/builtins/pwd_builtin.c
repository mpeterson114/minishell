/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 01:17:09 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/11 14:39:22 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd_builtin(t_shell *sh, char **args)
{
	char	buf[PATH_MAX];
	char	*cwd;

	(void)args;
	if (sh->pwd)
	{
		ft_putendl_fd(sh->pwd, STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}
	cwd = getcwd(buf, PATH_MAX);
	if (cwd)
	{
		ft_putendl_fd(cwd, STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}
	cmd_error_message("pwd", NULL, strerror(errno), errno);
	return (EXIT_FAILURE);
}
