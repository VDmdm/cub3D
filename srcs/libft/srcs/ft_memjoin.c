/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 20:43:45 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/23 00:27:22 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memjoin(void *arr1, void *arr2, size_t len1, size_t len2)
{
	unsigned char	*dest;
	unsigned char	*src1;
	unsigned char	*src2;
	size_t			j;
	size_t			i;

	if (!arr1 || !arr2)
		return (0);
	i = 0;
	j = 0;
	src1 = (unsigned char *)arr1;
	src2 = (unsigned char *)arr2;
	if (!(dest = (unsigned char *)malloc(len1 + len2)))
		return (0);
	while (i < len1)
	{
		dest[i] = src1[i];
		i++;
	}
	while (j < len2)
		dest[i++] = src2[j++];
	return ((void *)dest);
}
