/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:32:13 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/11/16 10:32:16 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned long long num, int isupcase)
{
	char	*hexup;
	char	*hexlow;

	hexup = "0123456789ABCDEF";
	hexlow = "0123456789abcdef";
	if (num >= 16)
	{
		ft_puthex(num / 16, isupcase);
		ft_puthex(num % 16, isupcase);
	}
	else
	{
		if (isupcase)
			write(1, &hexup[num], 1);
		else
			write(1, &hexlow[num], 1);
	}
}
