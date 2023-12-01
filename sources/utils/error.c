/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:48:02 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 18:07:25 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*strjoin_free_1st_str(char *str1, char *str2)
{
	char	*tmp;

	if (!str2)
		return (str1);
	if (!str1)
		return (ft_strdup(str2));
	tmp = str1;
	str1 = ft_strjoin(tmp, str2);
	free_ptr(tmp);
	return (str1);
}

static bool	is_export_or_unset(char *command)
{
	if (ft_strncmp(command, "export", 7) == 0
		|| ft_strncmp(command, "unset", 6) == 0)
		return (true);
	return (false);
}

int	cmd_error_message(char *cmd, char *detail, char *message, int err_nbr)
{
	char	*output;
	bool	add_detail;

	add_detail = is_export_or_unset(cmd);
	output = ft_strdup("minishell: ");
	if (cmd)
	{
		output = strjoin_free_1st_str(output, cmd);
		output = strjoin_free_1st_str(output, ": ");
	}
	if (detail)
	{
		if (add_detail)
			output = strjoin_free_1st_str(output, "`");
		output = strjoin_free_1st_str(output, detail);
		if (add_detail)
			output = strjoin_free_1st_str(output, "'");
		output = strjoin_free_1st_str(output, ": ");
	}
	output = strjoin_free_1st_str(output, message);
	ft_putendl_fd(output, STDERR_FILENO);
	free_ptr(output);
	return (err_nbr);
}

void	syntax_errmsg(char *message, char *quote, int in_quote)
{
	char	*output;

	output = ft_strdup("minishell: ");
	output = strjoin_free_1st_str(output, message);
	if (in_quote)
		output = strjoin_free_1st_str(output, " `");
	else
		output = strjoin_free_1st_str(output, ": ");
	output = strjoin_free_1st_str(output, quote);
	if (in_quote)
		output = strjoin_free_1st_str(output, "'");
	ft_putendl_fd(output, STDERR_FILENO);
	free_ptr(output);
}
