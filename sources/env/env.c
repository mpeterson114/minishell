/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 09:59:03 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/11 15:11:38 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	copy_envp(t_shell *sh, char **envp)
{
	int		i;

	if (*envp)
		sh->env = matrixdup(envp);
	update_shlvl(sh);
	update_pwd(sh);
	if (!sh->env)
		return (false);
	i = 0;
	while (sh->env[i])
	{
		if (!sh->env[i])
			return (false);
		i++;
	}
	return (true);
}

void	add_or_updt_env(t_shell *sh, char *line)
{
	int		i;
	char	**split_line;
	char	**split_env;

	split_line = ft_split(line, '=');
	i = 0;
	while (sh->env[i])
	{
		split_env = ft_split(sh->env[i], '=');
		if (strcmp(split_line[0], split_env[0]) == 0)
		{
			free_arr(split_env);
			free_arr(split_line);
			break ;
		}
		i++;
	}
	free(sh->env[i]);
	line = ft_strdup(line);
	sh->env[i] = line;
}

void	update_pwd(t_shell *sh)
{
	char	*pwd;
	char	*str;

	pwd = find_env(sh, "PWD");
	if (!pwd)
	{
		str = getcwd(NULL, 0);
		sh->env = add_line_to_matrix(sh->env, str);
		free(str);
		return ;
	}
}
