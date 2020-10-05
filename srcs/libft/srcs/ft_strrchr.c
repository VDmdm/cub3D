/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:10:01 by jalvaro           #+#    #+#             */
/*   Updated: 2020/04/30 19:42:36 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		len;

	len = ft_strlen(str);
	while (len >= 0 && str)
	{
		if (str[len] == ch)
			return ((char *)&str[len]);
		len--;
	}
	return (0);
}
