/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:30:53 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/09/19 17:31:58 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[50] = "12345678912345678123456789";
    char str2[50] = "12345678912345678123456789";

    printf("\nBefore bzero: %s\n", str1);
    bzero(str1 + 9, 8 * sizeof(char));
    printf("After bzero:  %s", str1);

    printf("\nBefore ft_bzero: %s\n", str2);
    ft_bzero(str2 + 9, 8 * sizeof(char));
    printf("After ft_bezro: %s", str2);

    return 0;
}
*/