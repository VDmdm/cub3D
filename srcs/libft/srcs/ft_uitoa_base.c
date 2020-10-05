/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 15:38:12 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/24 16:09:59 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_lh_str(int base, int nbr, size_t count)
{
	unsigned int	tmp;
	unsigned int	buff;
	char			*str;

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

char		*ft_uitoa_base(int nbr, int base)
{
	unsigned int	buff;
	size_t			count;

	buff = nbr;
	count = 1;
	while ((buff = buff / base))
		count++;
	return (ft_lh_str(base, nbr, count));
}
