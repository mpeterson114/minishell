/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:23:01 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/09/30 15:23:05 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

/*
int main(void)
{
	t_list *lst = ft_lstnew("World");
	t_list *lst2 = ft_lstnew("Hello");
	t_list *lst3 = ft_lstnew("!");
	ft_lstadd_front(&lst, lst2);
	ft_lstadd_front(&lst, lst3);
	
	printf("%d\n", ft_lstsize(lst));
	
	while (lst != NULL)
	{
		printf("%s\n", lst->content);
		// сдвигаем указатель на следующий элемент связного списка
		lst = lst->next; 
	}
		
	return (0);
}
*/