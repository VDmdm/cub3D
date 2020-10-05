/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:09:14 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/01 22:07:00 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*str;
	size_t	len;
	size_t	str_len;

	if (!(str_len = ft_strlen(src) + 1))
		return (0);
	if (!(str = (char *)malloc(sizeof(char) * str_len)))
		return (0);
	len = 0;
	while (src[len] != '\0')
	{
		str[len] = src[len];
		len++;
	}
	str[len] = '\0';
	return (str);
}
