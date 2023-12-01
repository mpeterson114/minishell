/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:43:30 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/11/16 10:43:32 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_percent(t_flags *f)
{
	if (f->minus)
	{
		ft_putchar_fd('%', 1);
		print_width(f);
	}
	else
	{
		if (f->zero)
		{
			print_zero(f, 0);
			ft_putchar_fd('%', 1);
		}
		else
		{
			print_width(f);
			ft_putchar_fd('%', 1);
		}
	}
	f->lenght++;
}

void	handle_percent(t_flags *f)
{
	int	i;

	i = 0;
	while (f->fspec[i])
	{
		if (f->fspec[i] == '-' && !(f->minus))
			f->minus = 1;
		else if (f->fspec[i] == '0' && !(f->zero)
			&& (f->width == 0) && !(f->minus) && !(f->precision))
			f->zero = 1;
		else if (ft_isdigit(f->fspec[i]))
			f->width = (f->width) * 10 + (f->fspec[i] - 48);
		i++;
	}
	print_percent(f);
}
