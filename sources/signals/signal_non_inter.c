/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_non_inter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:55:18 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 18:06:10 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_sigint(int signal)
{
	if (signal != SIGINT)
		return ;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
}

void	signal_sigquit(int signal)
{
	(void)signal;
	write(1, "Quit: 3\n", 8);
	rl_on_new_line();
}

void	sigint_non_interactive(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &signal_sigint;
	sigaction(SIGINT, &sa, NULL);
}

void	sigquit_non_interactive(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &signal_sigquit;
	sigaction(SIGQUIT, &sa, NULL);
}
