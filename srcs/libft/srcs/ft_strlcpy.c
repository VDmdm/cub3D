/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:09:35 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/01 17:03:11 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	int		i;

	if (!dst || !src)
		return (0);
	i = 0;
	len = ft_strlen(src);
	if (size)
	{
		while (--size && len - i)
			*dst++ = src[i++];
		*dst = '\0';
	}
	return (len);
}
