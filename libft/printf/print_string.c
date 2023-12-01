/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:40:38 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/11/27 19:30:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_flags(t_flags *f, int strlen)
{
	if (!(f->dot))
	{
		if (f->width < strlen)
			f->width = strlen;
		f->precision = strlen;
	}
	else
	{
		if (f->precision >= strlen)
		{
			f->precision = strlen;
			if (f->width < strlen)
				f->width = strlen;
		}
	}
}

static void	print_string(t_flags *f, va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	handle_flags(f, ft_strlen(str));
	if (f->minus)
	{
		ft_putnstr(str, f->precision);
		print_width(f);
	}
	else
	{
		print_width(f);
		ft_putnstr(str, f->precision);
	}
	f->lenght += f->precision;
}

void	handle_string(t_flags *f, va_list ap)
{
	int	i;

	i = 0;
	while (f->fspec[i])
	{
		if (f->fspec[i] == '-' && !(f->minus))
			f->minus = 1;
		else if (ft_isdigit(f->fspec[i]) && !(f->dot))
			f->width = (f->width) * 10 + (f->fspec[i] - 48);
		else if (f->fspec[i] == '.' && !(f->dot))
			f->dot = 1;
		else if (ft_isdigit(f->fspec[i]) && (f->dot))
			f->precision = (f->precision) * 10 + (f->fspec[i] - 48);
		i++;
	}
	print_string(f, ap);
}
