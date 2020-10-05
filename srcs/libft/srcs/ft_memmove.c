/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:08:37 by jalvaro           #+#    #+#             */
/*   Updated: 2020/04/30 19:41:34 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char *str_s;
	unsigned char		*str_d;
	size_t				i;

	i = 0;
	str_d = dest;
	str_s = src;
	if (str_s < str_d)
		while (++i <= n)
			str_d[n - i] = str_s[n - i];
	else
		ft_memcpy(str_d, str_s, n);
	return (dest);
}
