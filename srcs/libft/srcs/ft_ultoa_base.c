/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 21:11:24 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/24 15:41:14 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_lh_str(int base, long long int nbr, size_t count)
{
	unsigned long long int	tmp;
	unsigned long long int	buff;
	char					*str;

	tmp = nbr;
	buff = 0;
	if (!(str = ft_calloc(1, (count + 1))))
		return (0);
	while (count)
	{
		buff = (tmp % base);
		tmp = tmp / base;
		str[--count] = (buff >= 10) ? buff - 10 + 97 : buff + 48;
	}
	return (str);
}

char		*ft_ultoa_base(long long int nbr, int base)
{
	unsigned long long int	buff;
	size_t					count;

	buff = nbr;
	count = 1;
	while ((buff = buff / base))
		count++;
	return (ft_lh_str(base, nbr, count));
}
