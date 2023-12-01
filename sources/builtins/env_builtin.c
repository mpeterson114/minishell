/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:05:09 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/05 13:05:49 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_builtin(t_shell *sh, char **args)
{
	int	i;

	if (args && args[1])
		return (cmd_error_message("env", NULL, "too many arguments", 2));
	i = 0;
	if (!sh->env)
		return (EXIT_FAILURE);
	while (sh->env[i])
		ft_putendl_fd(sh->env[i++], STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
