/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_parser_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:00:57 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 18:39:40 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*make_str_from_tab(char **tab)
{
	char	*str;
	char	*tmp;
	int		i;

	i = -1;
	while (tab[++i])
	{
		tmp = str;
		if (i == 0)
			str = ft_strdup(tab[0]);
		else
		{
			str = ft_strjoin(tmp, tab[i]);
			free_ptr(tmp);
		}
		if (tab[i + 1])
		{
			tmp = str;
			str = ft_strjoin(tmp, " ");
			free_ptr(tmp);
		}
	}
	free_ptr_arr(tab);
	return (str);
}

static char	*get_expanded_var_line(t_shell *sh, char *line)
{
	char	**words;
	int		i;

	words = ft_split(line, ' ');
	if (!words)
		return (NULL);
	i = 0;
	while (words[i])
	{
		if (ft_strchr(words[i], '$'))
		{
			words[i] = var_expander_heredoc(sh, words[i]);
			if (!words[i])
				return (NULL);
		}
		i++;
	}
	return (make_str_from_tab(words));
}

bool	ev_line2(char **line)
{
	bool	ret;

	ret = false;
	if (*line == NULL && g_sig == 1)
	{
		ret = false;
		g_sig = 1;
	}
	else if (*line == NULL)
	{
		ret = true;
		g_sig = 0;
	}
	return (ret);
}

bool	evaluate_line(t_shell *sh, char **line, t_fds *io, bool *ret)
{
	if ((*line == NULL && g_sig == 1) || *line == NULL)
	{
		*ret = ev_line2(line);
		return (false);
	}
	if (ft_strcmp(*line, io->heredoc_del) == 0)
	{
		*ret = true;
		return (false);
	}
	if (io->heredoc_quotes == false && ft_strchr(*line, '$'))
	{
		*line = get_expanded_var_line(sh, *line);
		if (!(*line))
		{
			free_ptr(*line);
			*ret = false;
			return (false);
		}
	}
	return (true);
}

void	remove_last_newline(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}
