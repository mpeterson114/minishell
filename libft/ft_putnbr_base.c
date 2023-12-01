/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:09:40 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/10/28 09:09:47 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long long num, int base, int is_upper)
{
	char	*dec;
	char	*hex;
	char	*hex_up;

	dec = "0123456789";
	hex = "0123456789abcdef";
	hex_up = "0123456789ABCDEF";
	if (num < 0)
		num = -num;
	if (num >= base)
	{
		ft_putnbr_base(num / base, base, is_upper);
		ft_putnbr_base(num % base, base, is_upper);
	}
	else
	{
		if (base == 10)
			write(1, &dec[num], 1);
		else if (base == 16 && is_upper)
			write(1, &hex_up[num], 1);
		else if (base == 16)
			write(1, &hex[num], 1);
	}
}
