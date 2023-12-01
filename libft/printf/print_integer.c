/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:50:26 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/11/16 10:50:28 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handel_int_flags(t_flags *f, long long num, int numlen)
{
	if (f->dot)
	{
		if (f->precision == 0 && num == 0)
			return ;
		if (f->precision <= numlen)
			f->precision = numlen;
	}
	if (f->width > 0)
	{
		if (num < 0)
			f->width--;
		if (f->precision == 0)
			f->precision = numlen;
		if (f->width < f->precision)
			f->width = f->precision;
		if (f->zero && !(f->dot))
			f->precision = f->width;
		if (f->zero && f->minus)
			f->zero = 0;
	}
}

void	print_int_zero(t_flags *f, long long num)
{
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num = -num;
		f->lenght++;
	}
	if (f->zero || f->dot)
		print_zero(f, ft_numlen(num));
	if (!(f->dot && f->precision == 0 && num == 0))
		ft_putnbr_fd(num, 1);
}

void	print_integer(t_flags *f, va_list ap)
{
	int	num;

	num = va_arg(ap, int);
	handel_int_flags(f, num, ft_numlen(num));
	if (f->minus)
	{
		print_int_zero(f, num);
		print_width(f);
	}
	else
	{
		print_width(f);
		print_int_zero(f, num);
	}
	if (!(f->width == 0 && f->dot && f->precision == 0))
		f->lenght += ft_numlen(num);
}

static void	is_unsigned(t_flags *f, va_list ap, int isunsigned)
{
	if (isunsigned)
		print_u(f, ap);
	else
		print_integer(f, ap);
}

void	handle_integer(t_flags *f, va_list ap, int isunsigned)
{
	int	i;

	i = 0;
	while (f->fspec[i])
	{
		if (f->fspec[i] == '-' && !(f->minus))
		{
			if (f->zero)
				f->zero = 0;
			f->minus = 1;
		}
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
	is_unsigned(f, ap, isunsigned);
}
