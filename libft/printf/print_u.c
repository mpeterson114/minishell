/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:27:42 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/11/12 10:27:45 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_u(t_flags *f, va_list ap)
{
	unsigned int	unum;

	unum = (long long)va_arg(ap, unsigned int);
	handel_int_flags(f, unum, ft_numlen(unum));
	if (f->minus)
	{
		print_int_zero(f, unum);
		print_width(f);
	}
	else
	{
		print_width(f);
		print_int_zero(f, unum);
	}
	if (!(f->width == 0 && f->dot && f->precision == 0))
		f->lenght += ft_numlen(unum);
}
