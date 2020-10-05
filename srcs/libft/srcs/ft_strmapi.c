/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:09:45 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/01 16:57:46 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	len;

	if (!s || !f)
		return (0);
	len = 0;
	if (!(res = ft_calloc(1, (ft_strlen(s) + 1))))
		return (0);
	while (s[len] != '\0')
	{
		res[len] = f(len, s[len]);
		len++;
	}
	res[len] = '\0';
	return (res);
}
