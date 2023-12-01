/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:20:19 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 17:58:36 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	fill_heredoc(t_shell *sh, t_fds *io, int fd)
{
	char	*line;
	bool	ret;

	ret = false;
	line = NULL;
	while (1)
	{
		signals_awaiting_heredoc();
		ft_putstr_fd("> ", 1);
		line = get_next_line(STDIN_FILENO);
		sigquit_non_interactive();
		sigint_non_interactive();
		if (line)
			remove_last_newline(line);
		if (!evaluate_line(sh, &line, io, &ret))
			break ;
		ft_putendl_fd(line, fd);
		free_ptr(line);
	}
	free_ptr(line);
	return (ret);
}

bool	get_heredoc(t_shell *sh, t_fds *io)
{
	int		tmp_fd;
	bool	ret;

	ret = true;
	tmp_fd = open(io->infile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ret = fill_heredoc(sh, io, tmp_fd);
	close(tmp_fd);
	return (ret);
}

static char	*get_heredoc_name(void)
{
	static int	i;
	char		*name;
	char		*number;

	number = ft_itoa(i);
	if (!number)
		return (NULL);
	name = ft_strjoin(HEREDOC_NAME, number);
	free(number);
	i++;
	return (name);
}

static char	*get_delim(char *delim, bool *quotes)
{
	int	len;

	len = ft_strlen(delim) - 1;
	if ((delim[0] == '\"' && delim[len] == '\"')
		|| (delim[0] == '\'' && delim[len] == '\''))
	{
		*quotes = true;
		return (ft_strtrim(delim, "\'\""));
	}
	return (ft_strdup(delim));
}

void	parse_heredoc(t_shell *sh, t_command **last_cmd, t_token **token_lst)
{
	t_token		*temp;
	t_command	*cmd;
	t_fds		*io;

	temp = *token_lst;
	cmd = lst_last_cmd(*last_cmd);
	init_input_output(cmd);
	io = cmd->fds;
	if (!remove_old_file_ref(io, true))
		return ;
	io->infile = get_heredoc_name();
	io->heredoc_del = get_delim(temp->next->content, &(io->heredoc_quotes));
	if (get_heredoc(sh, io))
		io->fd_in = open(io->infile, O_RDONLY);
	else
		io->fd_in = -1;
	if (temp->next->next)
		temp = temp->next->next;
	else
		temp = temp->next;
	*token_lst = temp;
}
