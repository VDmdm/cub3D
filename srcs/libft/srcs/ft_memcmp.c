/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:08:27 by jalvaro           #+#    #+#             */
/*   Updated: 2020/04/30 19:41:27 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	const unsigned char *str1;
	const unsigned char *str2;

	str1 = arr1;
	str2 = arr2;
	while (n--)
	{
		if (*str1 - *str2 != 0)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}
