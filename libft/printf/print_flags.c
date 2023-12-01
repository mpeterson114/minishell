/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:26:18 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/11/27 19:33:07 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_zero(t_flags *f, int len)
{
	int		i;
	int		zerolen;

	i = 0;
	zerolen = 0;
	if ((f->fchar == 'c') || f->fchar == '%')
		zerolen = f->width - 1;
	else if (((f->fchar == 'd') || (f->fchar == 'i')
			|| (f->fchar == 'u')) && (f->width != 0 || f->precision > 0))
		zerolen = f->precision - len;
	else if ((f->fchar == 'x') || (f->fchar == 'X'))
		zerolen = f->precision - len;
	else if ((f->fchar == 'p') && (len != 2))
		zerolen = f->precision - len;
	while (i++ < zerolen)
		ft_putchar_fd('0', 1);
	f->lenght += zerolen;
}

void	print_width(t_flags *f)
{
	int		i;
	int		spacelen;

	i = 0;
	spacelen = 0;
	if (f->width && (f->fchar == 'c' || f->fchar == '%'))
		spacelen = f->width - 1;
	else if (f->width && (f->fchar == 's'))
	{
		if (f->width < f->precision)
			spacelen = 0;
		else
			spacelen = f->width - f->precision;
	}
	else if (f->width && ((f->fchar == 'd') || (f->fchar == 'i')
			|| (f->fchar == 'u')))
		spacelen = f->width - f->precision;
	else if (f->width && ((f->fchar == 'x') || (f->fchar == 'X')))
		spacelen = f->width - f->precision;
	else if (f->width && (f->fchar == 'p'))
		spacelen = f->width - f->precision;
	while (i++ < spacelen)
		ft_putchar_fd(' ', 1);
	f->lenght += spacelen;
}
