/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:07:14 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/01 13:15:50 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		buff;
	int		count;
	char	*str;

	buff = n;
	count = 1;
	while ((buff = buff / 10))
		count++;
	if (!(str = ft_calloc(1, count + (n < 0 ? 2 : 1))))
		return (0);
	if (n < 0)
		str[0] = '-';
	while (count)
	{
		buff = (n % 10);
		n = n / 10;
		str[count - (*str == '-' ? 0 : 1)] = (buff >= 0) ? buff + 48 :
		(buff * -1) + 48;
		count--;
	}
	return (str);
}
