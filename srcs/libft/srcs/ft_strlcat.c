/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:09:29 by jalvaro           #+#    #+#             */
/*   Updated: 2020/04/30 19:42:12 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t len_s;
	size_t len_d;

	i = 0;
	len_d = ft_strlen(dest);
	len_s = ft_strlen(src);
	if (size > len_d)
	{
		while (*src != '\0' && ((len_d + i) != (size - 1)))
			dest[len_d + i++] = *src++;
	}
	if (size)
		dest[len_d + i] = '\0';
	return (len_s + (size < len_d ? size : len_d));
}
