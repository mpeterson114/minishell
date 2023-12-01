/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:44:01 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/09/12 13:55:34 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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
    printf("a : %d\n", isdigit(a));
    printf("b : %d\n", isdigit(b));
    printf("c : %d\n", isdigit(c));
    printf("Mine:\n");
    printf("a : %d\n", ft_isdigit(a));
    printf("b : %d\n", ft_isdigit(b));
    printf("c : %d\n", ft_isdigit(c));

    return (0);
}
*/