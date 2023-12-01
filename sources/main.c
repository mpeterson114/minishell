/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:56:44 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/19 11:19:52 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(t_shell *sh)
{
	while (1)
	{
		signals_awaiting_input();
		sh->line = readline(PROMPT);
		sigquit_non_interactive();
		sigint_non_interactive();
		if (lexer_and_parser(sh))
			g_sig = execute(sh);
		free_data(sh, false);
	}
}

int	main(int ac, char **av, char **env)
{
	t_shell	sh;

	(void) av;
	ft_memset(&sh, 0, sizeof(t_shell));
	if (ac != 1)
	{
		ft_putendl_fd(R"Error: Invalid argument input.\n"N, 2);
		ft_putendl_fd(P"Example: \n▶ ./minishell"N, 2);
		exit_minishell(NULL, EXIT_FAILURE);
	}
	if (!init_data(&sh, env))
		exit_minishell(NULL, EXIT_FAILURE);
	minishell(&sh);
	exit_minishell(&sh, g_sig);
	return (0);
}
