/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 04:34:54 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/17 14:03:41 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_pwd_oldpwd(t_shell *sh, char *wd)
{
	add_or_updt_env_var(sh, "OLDPWD", get_env_value(sh->env, "PWD"));
	add_or_updt_env_var(sh, "PWD", wd);
	if (sh->old_pwd)
	{
		free_ptr(sh->old_pwd);
		sh->old_pwd = ft_strdup(sh->pwd);
	}
	if (sh->pwd)
	{
		free_ptr(sh->pwd);
		sh->pwd = ft_strdup(wd);
	}
	free_ptr(wd);
}

static bool	cd(t_shell *sh, char *path)
{
	char	*ret;
	char	*tmp;
	char	cwd[PATH_MAX];

	ret = NULL;
	if (chdir(path) != 0)
	{
		cmd_error_message("cd", path, "No such file or directory", 2);
		return (false);
	}
	ret = getcwd(cwd, PATH_MAX);
	if (!ret)
	{
		cmd_error_message("cd: error retrieving current directory",
			"getcwd: cannot access parent directories",
			strerror(errno), errno);
		ret = ft_strjoin(sh->pwd, "/");
		tmp = ret;
		ret = ft_strjoin(tmp, path);
		free_ptr(tmp);
	}
	else
		ret = ft_strdup(cwd);
	update_pwd_oldpwd(sh, ret);
	return (true);
}

int	cd_builtin(t_shell *sh, char **args)
{
	char	*path;

	if (!args || !args[1] || is_space(args[1][0]) || args[1][0] == '\0')
	{
		path = get_env_value(sh->env, "HOME");
		if (!path || *path == '\0' || is_space(*path))
			return (cmd_error_message("cd", NULL, "HOME not set", \
			EXIT_FAILURE));
		return (!cd(sh, path));
	}
	if (args[2])
		return (cmd_error_message("cd", NULL, "too many arguments", 0));
	if (ft_strncmp(args[1], "-", 2) == 0)
	{
		path = get_env_value(sh->env, "OLDPWD");
		if (!path)
			return (cmd_error_message("cd", NULL, "OLDPWD not set", \
			EXIT_FAILURE));
		ft_putendl_fd(path, 2);
		return (!cd(sh, path));
	}
	return (!cd(sh, args[1]));
}
