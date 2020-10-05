/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:08:14 by jalvaro           #+#    #+#             */
/*   Updated: 2020/04/30 23:22:10 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*str_d;
	const unsigned char	*str_s;

	str_d = (unsigned char *)dest;
	str_s = (const unsigned char *)src;
	if (dest == src)
		return (dest);
	while (n--)
	{
		*str_d++ = *str_s++;
		if (*(str_d - 1) == (unsigned char)c)
			return (str_d);
	}
	return (NULL);
}
