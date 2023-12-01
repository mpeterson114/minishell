/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:09:42 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/11/27 19:23:58 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_hex_flags(t_flags *f, long long hex, int hexlen)
{	
	if (f->dot)
	{
		if (f->precision == 0 && hex == 0)
			return ;
		if (f->precision <= hexlen)
			f->precision = hexlen;
	}
	if (f->width > 0)
	{
		if (f->precision == 0)
			f->precision = hexlen;
		if (f->width < f->precision)
			f->width = f->precision;
		if (f->zero && !(f->dot))
			f->precision = f->width;
	}
}

static void	print_hex(t_flags *f, va_list ap, int isupcase)
{
	long long	num;

	num = va_arg(ap, unsigned int);
	handle_hex_flags(f, num, ft_hexlen(num));
	if (f->minus)
	{
		if (f->zero || f->dot)
			print_zero(f, ft_hexlen(num));
		if (!(f->dot && f->precision == 0))
			ft_puthex(num, isupcase);
		print_width(f);
	}
	else
	{
		print_width(f);
		if (f->zero || f->dot)
			print_zero(f, ft_hexlen(num));
		if (!(f->dot && f->precision == 0 && num == 0))
			ft_puthex(num, isupcase);
	}
	f->lenght += ft_hexlen(num);
}

static void	handle_hex_isupper(t_flags *f, va_list ap)
{
	int		isupcase;

	if (f->fchar == 'X')
		isupcase = 1;
	else
		isupcase = 0;
	print_hex(f, ap, isupcase);
}

void	handle_hex(t_flags *f, va_list ap)
{
	int		i;

	i = 0;
	while (f->fspec[i])
	{
		if (f->fspec[i] == '-' && !(f->minus))
			f->minus = 1;
		else if (f->fspec[i] == '0' && !(f->zero)
			&& !(f->width) && !(f->minus) && !(f->precision))
			f->zero = 1;
		else if (ft_isdigit(f->fspec[i]) && !(f->dot))
			f->width = (f->width) * 10 + (f->fspec[i] - 48);
		else if (f->fspec[i] == '.' && !(f->dot))
			f->dot = 1;
		else if (ft_isdigit(f->fspec[i]) && (f->dot))
			f->precision = (f->precision) * 10 + (f->fspec[i] - 48);
		i++;
	}
	handle_hex_isupper(f, ap);
}
