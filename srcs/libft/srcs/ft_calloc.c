/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:39:56 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/03 10:50:47 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void *arr;

	arr = malloc(num * size);
	if (arr == NULL)
		return (NULL);
	else
		ft_bzero(arr, num * size);
	return (arr);
}
