/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 21:19:34 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 18:07:30 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_minishell(t_shell *sh, int exit_code)
{
	if (sh)
	{
		if (sh->cmd && sh->cmd->fds)
			close_fds(sh->cmd, true);
		free_data(sh, true);
	}
	exit(exit_code);
}
