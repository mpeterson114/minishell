/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilzhabur <ilzhabur@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:25:50 by ilzhabur          #+#    #+#             */
/*   Updated: 2023/11/12 18:55:06 by ilzhabur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, const char *sep)
{
	static char	*ptr;
	char		*token;

	if (str)
		ptr = str;
	if (!ptr || !*ptr)
		return (NULL);
	token = ptr;
	while (*ptr && !ft_strchr(sep, *ptr))
		ptr++;
	if (*ptr)
	{
		*ptr++ = 0;
		while (*ptr && ft_strchr(sep, *ptr))
			ptr++;
	}
	return (token);
}

// int main(void)
// {
// 	char cadena[] = "Esto es un texto. Puede ir separado por 
// puntos, espacios o comas.";
// 	char delimitador[] = ",. ";
// 	char *token;

// 	token = ft_strtok(cadena, delimitador);
// 	if (token)
// 	{
// 		while (token)
// 		{
// 			printf("Token: %s\n", token);
// 			token = ft_strtok(NULL, delimitador);
// 		}
// 	}
// }