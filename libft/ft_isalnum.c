/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:10:28 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/09/19 17:30:18 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}

/*
int main(void)
{
    char a;
    char b;
    char c;
    char d;

    a = 'a';
    b = 'B';
    c = '4';
    d = '-';

    printf("Official:\n");
    printf("a : %d\n", isalnum(a));
    printf("b : %d\n", isalnum(b));
    printf("c : %d\n", isalnum(c));
    printf("d : %d\n", isalnum(d));
    printf("Mine:\n");
    printf("a : %d\n", ft_isalnum(a));
    printf("b : %d\n", ft_isalnum(b));
    printf("c : %d\n", ft_isalnum(c));
    printf("d : %d\n", ft_isalnum(d));

    return (0);
}
*/