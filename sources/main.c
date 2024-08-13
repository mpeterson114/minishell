#include "minishell.h"

/* Runs parsing and execution in interactive mode, i.e. when minishell
*	is started without arguments and provides a prompt for user input. */

void	minishell(t_shell *sh)
{
	while (1)
	{
		signals_awaiting_input();
		sh->line = readline(PROMPT);
		sigquit_interactive();
		sigint_interactive();
		if (run_lexer_parser(sh))
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
		ft_putendl_fd(R "Error: Invalid argument input.\n" N, 2);
		ft_putendl_fd(P"Example: \n▶ ./minishell"N, 2);
		exit_minishell(NULL, EXIT_FAILURE);
	}
	if (!init_data(&sh, env))
		exit_minishell(NULL, EXIT_FAILURE);
	minishell(&sh);
	exit_minishell(&sh, g_sig);
	return (0);
}
