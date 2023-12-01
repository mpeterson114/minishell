/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:03:05 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/06/08 11:01:26 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft.h"

typedef struct s_flags
{
	char		*fspec;
	char		fchar;
	int			lenght;
	int			minus;
	int			zero;
	int			width;
	int			dot;
	int			precision;
}				t_flags;

int				ft_printf(const char *s, ...);
int				parse_string(char *s, va_list ap);

void			handle_percent(t_flags *f);
void			handle_char(t_flags *f, va_list ap);
void			handle_string(t_flags *f, va_list ap);
void			handle_integer(t_flags *f, va_list ap, int isunsigned);
void			handle_hex(t_flags *f, va_list ap);
void			handle_pointer(t_flags *f, va_list ap);

void			print_zero(t_flags *f, int len);
void			print_width(t_flags *f);
void			handel_int_flags(t_flags *f, long long num, int numlen);
void			print_int_zero(t_flags *f, long long num);
void			print_integer(t_flags *f, va_list ap);
void			print_u(t_flags *f, va_list ap);
char			*find_cspdiux(char *s);

#endif
