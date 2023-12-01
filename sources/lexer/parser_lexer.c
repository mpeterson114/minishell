/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lexer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:56:48 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 16:39:31 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_index(t_token **tokens)
{
	t_token			*lst;
	unsigned int	i;

	i = 0;
	lst = (*tokens);
	while (lst->next)
	{
		lst->index += i;
		i++;
		lst = lst->next;
	}
}

static bool	line_is_space(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_space(line[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	lexer_and_parser(t_shell *sh)
{
	if (!sh->line)
		exit_builtin(sh, NULL);
	else if (line_is_space(sh->line))
		return (true);
	add_history(sh->line);
	if (tokenization(sh, sh->line) == FAILURE)
		return (false);
	if (check_syntax(&sh->token) == FAILURE)
		return (false);
	check_variable(&sh->token);
	expander(sh, &sh->token);
	quotes_handler(sh);
	add_index(&sh->token);
	create_commands(sh, sh->token);
	return (true);
}
