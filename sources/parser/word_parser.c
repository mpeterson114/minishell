/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:01:41 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 18:01:53 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	contains_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (true);
		i++;
	}
	return (false);
}

static void	custom_var_cmd_split(t_command *last_cmd, char *cmd_str)
{
	t_token		*new_tokens;
	t_token		*tmp;
	char		**strings;
	int			i;

	new_tokens = NULL;
	strings = ft_split(cmd_str, ' ');
	if (!strings)
		return ;
	last_cmd->command = ft_strdup(strings[0]);
	if (strings[1])
		new_tokens = new_token_lst(ft_strdup(strings[1]), NULL, WORD, QOK);
	tmp = new_tokens;
	i = 1;
	while (strings[++i])
		add_back_tok_lst(&new_tokens,
			new_token_lst(ft_strdup(strings[i]), NULL, WORD, QOK));
	add_back_tok_lst(&new_tokens,
		new_token_lst(NULL, NULL, END, QOK));
	fill_command_args(&new_tokens, last_cmd);
	lstclear_token(&tmp, &free_ptr);
	free_ptr_arr(strings);
}

void	parse_word(t_command **cmd, t_token **token_lst)
{
	t_token		*temp;
	t_command	*last_cmd;

	temp = *token_lst;
	while (temp->type == WORD || temp->type == VAR)
	{
		last_cmd = lst_last_cmd(*cmd);
		if (temp->prev == NULL || (temp->prev && temp->prev->type == PIPE)
			|| last_cmd->command == NULL || last_cmd->command[0] == '\0')
		{
			if (temp->type == VAR && contains_space(temp->content))
				custom_var_cmd_split(last_cmd, temp->content);
			else
				last_cmd->command = ft_strdup(temp->content);
			temp = temp->next;
		}
		else
			fill_command_args(&temp, last_cmd);
	}
	*token_lst = temp;
}
