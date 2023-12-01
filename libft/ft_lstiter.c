/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:47:37 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/10/03 19:47:38 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/*
void f(void *s)
{
	((char *)s)[0] = 'W';
}



int main(void)
{
	t_list *lst;
	
	lst = ft_lstnew(strdup("word1"));
	lst->next = ft_lstnew(strdup("word2"));
	lst->next->next = ft_lstnew(strdup("word3"));
	lst->next->next->next = ft_lstnew(strdup("word4"));
	ft_lstiter(lst, f);
	while (lst)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
}
*/