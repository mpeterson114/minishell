/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:50:26 by ilzhabur          #+#    #+#             */
/*   Updated: 2022/09/26 16:50:29 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(long long nb, int fd)
{
	if (nb < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-nb, fd);
	}
	else if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
	{
		nb += '0';
		write(fd, &nb, 1);
	}
}

/*
#include <unistd.h>

int main(void)
{
    ft_putnbr(2147483647, 1);
    write(1, "\n", 1);
    ft_putnbr(0, 1);
    write(1, "\n", 1);
    ft_putnbr(-2147483648, 1);
    write(1, "\n", 1);
    return (0);
}
*/