/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:19:58 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/11 15:10:30 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**recreate_env_vars(t_shell *sh, int size)
{
	char	**new_env;
	int		i;

	new_env = ft_calloc(size + 1, sizeof * new_env);
	if (!new_env)
		return (NULL);
	i = 0;
	while (sh->env[i] && i < size)
	{
		new_env[i] = ft_strdup(sh->env[i]);
		free_ptr(sh->env[i]);
		i++;
	}
	free(sh->env);
	return (new_env);
}

bool	add_or_updt_env_var(t_shell *sh, char *key, char *value)
{
	int		i;
	char	*tmp;

	i = find_env_index_by_key(sh->env, key);
	if (value == NULL)
		value = "";
	tmp = ft_strjoin("=", value);
	if (!tmp)
		return (false);
	if (i != -1 && sh->env[i])
	{
		free_ptr(sh->env[i]);
		sh->env[i] = ft_strjoin(key, tmp);
	}
	else
	{
		i = count_env_vars(sh->env);
		sh->env = recreate_env_vars(sh, i + 1);
		if (!sh->env)
			return (false);
		sh->env[i] = ft_strjoin(key, tmp);
	}
	free_ptr(tmp);
	return (true);
}

bool	remove_env_var(t_shell *sh, int pos)
{
	int	i;
	int	count;

	if (pos > count_env_vars(sh->env))
		return (false);
	free_ptr(sh->env[pos]);
	i = pos;
	count = pos;
	while (sh->env[i + 1])
	{
		sh->env[i] = ft_strdup(sh->env[i + 1]);
		free_ptr(sh->env[i + 1]);
		count++;
		i++;
	}
	sh->env = recreate_env_vars(sh, count);
	if (!sh->env)
		return (false);
	return (true);
}
