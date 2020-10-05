/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 21:41:36 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/22 23:17:11 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memsub(void *arr, size_t start, size_t end)
{
	unsigned char	*dest;
	unsigned char	*tmp;
	size_t			i;

	if (!arr)
		return (0);
	if ((end - start) == 0)
		return (ft_calloc(1, 1));
	i = 0;
	tmp = arr;
	dest = (unsigned char *)malloc(1 * end - start);
	while (start < end)
	{
		dest[i] = tmp[start];
		i++;
		start++;
	}
	return (dest);
}
