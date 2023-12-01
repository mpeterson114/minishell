/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:06:06 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/09/30 16:06:08 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
#include <stdio.h>

int main(void)
{
	t_list *lst = ft_lstnew("Lista 1");
	t_list *lst2 = ft_lstnew("Lista 2");
	t_list *lst3 = ft_lstnew("Lista 3");
	ft_lstadd_front(&lst, lst2);
	ft_lstadd_front(&lst, lst3);
	
	printf("%s\n", lst->content);
	lst = ft_lstlast(lst);
	printf("%s\n", lst->content);

	return (0);
}
*/