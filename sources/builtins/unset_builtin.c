/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:00:31 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/11 14:38:52 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unset_builtin(t_shell *sh, char **args)
{
	int	i;
	int	pos;
	int	ret;

	ret = EXIT_SUCCESS;
	i = 1;
	while (args[i])
	{
		if (!is_valid_env_key(args[i]) || ft_strchr(args[i], '=') != NULL)
		{
			cmd_error_message("unset", args[i], "not a valid identifier", \
			false);
			ret = EXIT_FAILURE;
		}
		else
		{
			pos = find_env_index_by_key(sh->env, args[i]);
			if (pos != -1)
				remove_env_var(sh, pos);
		}
		i++;
	}
	return (ret);
}
