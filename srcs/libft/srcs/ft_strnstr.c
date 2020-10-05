/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:09:56 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/01 22:08:56 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t i;

	if (*str2 == 0)
		return ((char *)str1);
	while (len && *str1 != '\0')
	{
		i = 0;
		while (str1[i] == str2[i] && i < len && str1[i] != '\0')
			i++;
		if (str2[i] == '\0')
			return ((char *)str1);
		str1++;
		len--;
	}
	return (0);
}
