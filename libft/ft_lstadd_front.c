/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:12:28 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/09/29 16:12:30 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*
#include  <stdio.h>

int main(void)
{
	t_list *lst = ft_lstnew("World");
	t_list *lst2 = ft_lstnew("Hello");
	t_list *lst3 = ft_lstnew("!");
	ft_lstadd_front(&lst, lst2);
	ft_lstadd_front(&lst, lst3);
	
	while (lst != NULL)
	{
		printf("%s\n", lst->content);
		// сдвигаем указатель на следующий элемент связного списка
		lst = lst -> next; 
	}
		
	return (0);
}
*/