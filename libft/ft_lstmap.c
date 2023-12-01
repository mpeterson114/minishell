/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:31:01 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/10/03 20:31:02 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	char	*tmp;
	t_list	*elem;
	t_list	*lst1;

	lst1 = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		tmp = f(lst->content);
		elem = ft_lstnew(tmp);
		if (!elem)
		{
			del(tmp);
			ft_lstclear(&lst1, del);
			return (NULL);
		}
		else
		{
			ft_lstadd_back(&lst1, elem);
			lst = lst->next;
		}
	}	
	return (lst1);
}

/*
#include <stdio.h>

void	*f(void	*ptr)  // receive content and makes it upper
{
	size_t	i = 0;
	char	*str = ptr;
	if (!ptr)
		return (NULL);
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return ((void *)str);
}
void	del(void *tmp) // clean content
{
	free(tmp);
}
void	printList(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
}

int main(int argc, char const *argv[])
{
	t_list	*a;
	t_list	*b;
	t_list	*c;
	t_list	*res;
	
	a = ft_lstnew(ft_strdup("list1"));
	b = ft_lstnew(ft_strdup("list2"));
	c = ft_lstnew(ft_strdup("list3"));
	ft_lstadd_back(&a, b);
	ft_lstadd_back(&a, c);
	printf("Original:\n");
	printLista(a);
	res = ft_lstmap(a, f, del);
	printf("---------------------\n");
	printf("Despues de ft_lstmap\n");
	printLista(res);
	return 0;
}
*/