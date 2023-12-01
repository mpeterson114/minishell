/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_utils_cleanup.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:53:25 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 16:53:28 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lst_delone_cmd(t_command *lst, void (*del)(void *))
{
	if (lst->command)
		(*del)(lst->command);
	if (lst->args)
		free_ptr_arr(lst->args);
	if (lst->pipe_fd)
		(*del)(lst->pipe_fd);
	if (lst->fds)
		free_io(lst->fds);
	(*del)(lst);
}

void	lst_clear_cmd(t_command **lst, void (*del)(void *))
{
	t_command	*temp;

	temp = NULL;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		lst_delone_cmd(*lst, del);
		*lst = temp;
	}
}
