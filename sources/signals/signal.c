/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 21:00:11 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 18:05:04 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_replace_ctrl_c(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_sig = 1;
}

void	ignore_ctrl_backslash(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
}

void	signals_awaiting_input(void)
{
	struct sigaction	sa;

	ignore_ctrl_backslash();
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &signal_replace_ctrl_c;
	sigaction(SIGINT, &sa, NULL);
}

void	signal_heredoc_int(int signum)
{
	if (signum != SIGINT)
		return ;
	g_sig = 1;
	write(1, "\n", 1);
}

void	signals_awaiting_heredoc(void)
{
	struct sigaction	sa;

	ignore_ctrl_backslash();
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &signal_heredoc_int;
	sigaction(SIGINT, &sa, NULL);
}
