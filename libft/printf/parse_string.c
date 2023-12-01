/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:01:47 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/11/28 19:02:19 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	flags_init(t_flags *f, char *fspec, char c)
{
	f->fspec = fspec;
	f->fchar = c;
	f->lenght = 0;
	f->minus = 0;
	f->zero = 0;
	f->width = 0;
	f->dot = 0;
	f->precision = 0;
}

static void	is_cspdiux(t_flags *f, va_list ap)
{
	if (f->fchar == '%')
		handle_percent(f);
	else if (f->fchar == 'c')
		handle_char(f, ap);
	else if (f->fchar == 's')
		handle_string(f, ap);
	else if (f->fchar == 'i' || f->fchar == 'd')
		handle_integer(f, ap, 0);
	else if (f->fchar == 'u')
		handle_integer(f, ap, 1);
	else if (f->fchar == 'x' || f->fchar == 'X')
		handle_hex(f, ap);
	else if (f->fchar == 'p')
		handle_pointer(f, ap);
	free(f->fspec);
}

static int	handle_cspdiux(t_flags *f, char *s, int *i, va_list ap)
{
	char	*cspdiux;

	cspdiux = find_cspdiux(s + *i + 1);
	flags_init(f, ft_strndup((s + *i), (cspdiux + 1) - (s + *i)), *cspdiux);
	is_cspdiux(f, ap);
	*i = *i + ((cspdiux) - (s + *i));
	return (f->lenght);
}

char	*find_cspdiux(char *s)
{
	int		i;
	char	*fspecifier;

	i = 0;
	while (s[i] && (ft_isdigit(s[i]) || s[i] == '-' || s[i] == '.'
			|| s[i] == ' ' ))
		i++;
	if (ft_isprint(s[i]))
	{
		fspecifier = ft_strchr("cspdiuxX%%", s[i]);
		if (fspecifier)
			return ((char *)s + i);
		else
			return (NULL);
	}
	return (NULL);
}

int	parse_string(char *s, va_list ap)
{
	int			i;
	int			len;
	t_flags		*f;

	len = 0;
	f = malloc(sizeof(t_flags));
	if (!f)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (!find_cspdiux(s + i + 1))
				i++;
			else if (find_cspdiux(s + i + 1))
				len += handle_cspdiux(f, s, &i, ap);
		}
		else
			len += ft_putchar_fd(s[i], 1);
		i++;
	}
	free(f);
	return (len);
}
