/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:08:32 by jalvaro           #+#    #+#             */
/*   Updated: 2020/04/30 19:41:31 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*str_d;
	const unsigned char	*str_s;

	str_d = dest;
	str_s = src;
	if (dest == src)
		return (dest);
	while (n--)
		*str_d++ = *str_s++;
	return (dest);
}
