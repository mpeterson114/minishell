/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:21:06 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/17 17:00:32 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*find_valid_cmd_path(char *cmd, char **paths)
{
	int		i;
	char	*cmd_path;

	cmd_path = NULL;
	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (!cmd_path)
		{
			cmd_error_message("malloc", NULL,
				"an unexpected error occured", EXIT_FAILURE);
			return (NULL);
		}
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free_ptr(cmd_path);
		i++;
	}
	return (NULL);
}

static char	**get_env_paths(t_shell *sh)
{
	char	**env_paths;

	if (find_env_index_by_key(sh->env, "PATH") == -1)
		return (NULL);
	env_paths = ft_split(get_env_value(sh->env, "PATH"), ':');
	if (!env_paths)
		return (NULL);
	return (env_paths);
}

char	*get_cmd_path(t_shell *sh, char *str)
{
	char	**env_paths;
	char	*cmd;
	char	*cmd_path;

	if (!str)
		return (NULL);
	env_paths = get_env_paths(sh);
	if (!env_paths)
		return (NULL);
	cmd = ft_strjoin("/", str);
	if (!cmd)
	{
		free_ptr_arr(env_paths);
		return (NULL);
	}
	cmd_path = find_valid_cmd_path(cmd, env_paths);
	if (!cmd_path)
	{
		free_ptr(cmd);
		free_ptr_arr(env_paths);
		return (NULL);
	}
	return (cmd_path);
}
