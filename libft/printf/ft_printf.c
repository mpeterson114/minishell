/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur  <ilzhabur@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:04:20 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/11/28 19:04:40 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		len;

	if (!s)
		return (-1);
	va_start(ap, s);
	len = parse_string((char *)s, ap);
	va_end(ap);
	return (len);
}
