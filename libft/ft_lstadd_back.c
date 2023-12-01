/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:24:03 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/09/30 16:24:05 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

/*
int main(void)
{
	t_list *lst = ft_lstnew("World");
	t_list *lst2 = ft_lstnew("Hello");
	t_list *lst3 = ft_lstnew("!");
    t_list *lst4 = ft_lstnew("Added back!");
	ft_lstadd_front(&lst, lst2);
	ft_lstadd_front(&lst, lst3);
    ft_lstadd_back(&lst, lst4);
	
	while (lst != NULL)
	{
		printf("%s\n", lst->content);
		// сдвигаем указатель на следующий элемент связного списка
		lst = lst -> next; 
	}
		
	return (0);
}
*/