/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:37:59 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/09/19 17:28:44 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/*
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    char a;
    char b;
    char c;

    a = 'a';
    b = 'B';
    c = '4';

    printf("Official:\n");
    printf("a : %d\n", isalpha(a));
    printf("b : %d\n", isalpha(b));
    printf("c : %d\n", isalpha(c));
    printf("Mine:\n");
    printf("a : %d\n", ft_isalpha(a));
    printf("b : %d\n", ft_isalpha(b));
    printf("c : %d\n", ft_isalpha(c));

    return (0);
}
*/