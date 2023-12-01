/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:25:30 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/11 14:45:36 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*add_double_quotes(char *no_quotes)
{
	char	**split;
	char	*new_str;
	int		i;

	i = 1;
	split = ft_split(no_quotes, '=');
	new_str = ft_strjoin(split[0], "=\"");
	while (split[i] && split[i + 1])
	{
		new_str = strjoin_free_s1(new_str, split[i++]);
		new_str = strjoin_free_s1(new_str, "=");
	}
	if (split[i])
		new_str = strjoin_free_s1(new_str, split[i]);
	new_str = strjoin_free_s1(new_str, "\"");
	free_arr(split);
	return (new_str);
}

int	exp_builtin(t_shell *sh)
{
	char	*with_quotes;
	int		i;

	i = 0;
	if (!sh->env)
		return (EXIT_FAILURE);
	while (sh->env[i])
	{
		with_quotes = add_double_quotes(sh->env[i]);
		printf("declare -x %s\n", with_quotes);
		i++;
	}
	return (EXIT_SUCCESS);
}

static char	**key_value_arr(char *arg)
{
	char	**arr;
	char	*equal;

	equal = ft_strchr(arg, '=');
	if (!equal)
		return (NULL);
	arr = malloc(sizeof(char *) * 3);
	arr[0] = ft_substr(arg, 0, equal - arg);
	arr[1] = ft_substr(equal, 1, ft_strlen(equal));
	arr[2] = NULL;
	return (arr);
}

int	export_builtin(t_shell *sh, char **args)
{
	int		i;
	char	**arr;
	int		ret;

	ret = EXIT_SUCCESS;
	i = 1;
	if (!args[i])
		return (exp_builtin(sh));
	while (args[i])
	{
		if (!is_valid_env_key(args[i]))
		{
			cmd_error_message("export", args[i], "not a valid identifier", \
			false);
			ret = EXIT_FAILURE;
		}
		else if (ft_strchr(args[i], '=') != NULL)
		{
			arr = key_value_arr(args[i]);
			add_or_updt_env_var(sh, arr[0], arr[1]);
			free_ptr_arr(arr);
		}
		i++;
	}
	return (ret);
}
