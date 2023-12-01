/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:21:55 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/09/26 17:21:58 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

/*
int main(void)
{
	char str[20] = "Life is good.";
	ft_putendl_fd(str, 1);
	return (0);
}
*/
