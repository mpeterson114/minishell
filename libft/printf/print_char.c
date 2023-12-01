/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:34:48 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/11/27 19:35:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_char(t_flags *f, va_list ap)
{
	if (f->minus)
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		print_width(f);
	}
	else
	{
		print_width(f);
		ft_putchar_fd(va_arg(ap, int), 1);
	}
	f->lenght++;
}

void	handle_char(t_flags *f, va_list ap)
{
	int	i;

	i = 0;
	while (f->fspec[i])
	{
		if (f->fspec[i] == '-' && !(f->minus))
			f->minus = 1;
		else if (ft_isdigit(f->fspec[i]))
			f->width = (f->width) * 10 + (f->fspec[i] - 48);
		i++;
	}
	print_char(f, ap);
}
