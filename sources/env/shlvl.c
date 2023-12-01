/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:02:21 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/11 15:12:39 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_env_index(t_shell *sh, char **env_split, int i)
{
	char	**split;

	while (sh->env[i])
	{
		split = ft_split(sh->env[i], '=');
		if (ft_strcmp(split[0], env_split[0]) == 0)
		{
			free_arr(split);
			return (i);
		}
		i++;
		free_arr(split);
	}
	return (-1);
}

void	replace_o_create_env(t_shell *s, char *env_variable)
{
	int		i;
	char	**env_split;

	i = 0;
	env_split = ft_split(env_variable, '=');
	i = find_env_index(s, env_split, i);
	if (i == -1)
	{
		s->env = add_line_to_matrix(s->env, env_variable);
		free_arr(env_split);
		return ;
	}
	free(s->env[i]);
	env_variable = ft_strdup(env_variable);
	s->env[i] = env_variable;
	free_arr(env_split);
}

char	**add_line_to_matrix(char **old_matrix, char *line)
{
	int		i;
	char	**n;

	i = 0;
	while (old_matrix[i])
		i++;
	n = malloc(sizeof(char *) * (i + 2));
	if (!n)
		return (NULL);
	i = 0;
	while (old_matrix[i])
	{
		n[i] = ft_strdup(old_matrix[i]);
		i++;
	}
	n[i++] = ft_strdup(line);
	n[i] = NULL;
	free_arr(old_matrix);
	return (n);
}

char	*find_env(t_shell *sh, char *env_key)
{
	int		i;
	char	**key_value;

	i = 0;
	while (sh->env[i])
	{
		key_value = ft_split(sh->env[i], '=');
		if (ft_strcmp(key_value[0], env_key) == 0)
		{
			free_arr(key_value);
			break ;
		}
		else
			i++;
		free_arr(key_value);
	}
	if (!sh->env[i])
		return (NULL);
	return (sh->env[i]);
}

void	update_shlvl(t_shell *sh)
{
	char	*shlvl;
	char	*new_shlvl;
	int		value;
	char	**split;

	shlvl = find_env(sh, "SHLVL");
	if (!shlvl)
	{
		sh->env = add_line_to_matrix(sh->env, "SHLVL=1");
		return ;
	}
	split = ft_split(shlvl, '=');
	value = ft_atoi(split[1]);
	value++;
	shlvl = ft_itoa(value);
	new_shlvl = ft_strjoin("SHLVL=", shlvl);
	replace_o_create_env(sh, new_shlvl);
	free(shlvl);
	free(new_shlvl);
	free_arr(split);
}
