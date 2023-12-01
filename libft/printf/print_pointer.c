/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:   <ilzhabur@student.42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:42:25 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/11/27 19:29:40 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_p_flags(t_flags *f, int *hexlen)
{
	if (f->dot)
	{
		if (f->precision == 0)
			*hexlen = 2;
		if (f->precision <= *hexlen)
			f->precision = *hexlen;
		else
			f->precision += 2;
	}
	if (f->width > 0)
	{
		if (f->precision == 0)
			f->precision = *hexlen;
		if (f->width < f->precision)
			f->width = f->precision;
		if (f->zero && !(f->dot))
			f->precision = f->width;
	}
}

static void	print_pointer_fminus(t_flags *f, unsigned long long ptr, int ptrlen)
{
	ft_putstr_fd("0x", 1);
	if (f->zero || f->dot)
		print_zero(f, ptrlen);
	if (!(f->dot && f->precision == 2))
		ft_puthex(ptr, 0);
	print_width(f);
}

static void	print_pointer(t_flags *f, va_list ap)
{
	unsigned long long	ptr;
	int					ptrlen;

	ptr = va_arg(ap, unsigned long long);
	if (!ptr)
		ptrlen = 3;
	else
		ptrlen = (ft_hexlen(ptr) + 2);
	handle_p_flags(f, &ptrlen);
	if (f->minus)
		print_pointer_fminus(f, ptr, ptrlen);
	else
	{
		print_width(f);
		ft_putstr_fd("0x", 1);
		if (f->zero || f->dot)
			print_zero(f, ptrlen);
		if (!(f->dot && f->precision == 2))
			ft_puthex(ptr, 0);
	}
	f->lenght += ptrlen;
}

void	handle_pointer(t_flags *f, va_list ap)
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
	print_pointer(f, ap);
}
