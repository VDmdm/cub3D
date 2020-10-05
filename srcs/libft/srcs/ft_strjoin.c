/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 17:09:21 by jalvaro           #+#    #+#             */
/*   Updated: 2020/05/01 18:34:29 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		len_s;

	if (!s1)
		return (0);
	len_s = ft_strlen(s1) + ft_strlen(s2);
	if ((str = (char *)ft_calloc(1, len_s + 1)))
	{
		ft_strlcat(str, s1, len_s + 1);
		ft_strlcat(str, s2, len_s + 1);
		return (str);
	}
	return (0);
}
