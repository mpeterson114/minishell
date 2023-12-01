/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:26:37 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 16:51:37 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tokenization(t_shell *sh, char *line)
{
	int	i;
	int	end;
	int	start;
	int	q_status;

	i = -1;
	start = 0;
	end = ft_strlen(line);
	q_status = QOK;
	while (++i <= end)
	{
		q_status = updt_quote_status(q_status, line, i);
		if (q_status == QOK)
			start = add_word_or_delim(&i, line, start, sh);
	}
	if (q_status != QOK)
	{
		if (q_status == DQ)
			syntax_errmsg("syntax error: unclosed quote:", R"\""N, true);
		else if (q_status == SQ)
			syntax_errmsg("syntax error: unclosed quote:", R"\'"N, true);
		return (FAILURE);
	}
	return (OK);
}
