/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:56:57 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/10/03 16:56:59 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*pos;

	pos = *lst;
	while (pos)
	{
		temp = pos->next;
		(*del)(pos->content);
		free(pos);
		pos = temp;
	}
	(*lst) = NULL;
}
