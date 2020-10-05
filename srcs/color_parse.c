/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:26:33 by jalvaro           #+#    #+#             */
/*   Updated: 2020/06/20 13:42:57 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_draw.h"

int		color_get(char *tmp)
{
	int		i;
	int		j;
	int		arr[4];

	i = 2;
	j = -1;
	while (tmp[i] == ' ' && tmp[i])
		i++;
	if (!ft_isdigit(tmp[i]))
		return (-1);
	while (++j < 3)
	{
		arr[j] = ft_atoi(&tmp[i]);
		if (arr[j] < 0 || arr[j] > 255)
			return (-1);
		i += ft_skip_nbr(&tmp[i]);
		if (j < 2 && (tmp[i] != ',' || !ft_isdigit(tmp[++i])))
			return (-1);
	}
	if (tmp[i])
		return (-1);
	return ((arr[0] << 16) + (arr[1] << 8) + arr[2]);
}

int		color_pars(t_map *data, char *tmp)
{
	if (ft_strnstr(tmp, "F ", 2))
	{
		if ((data->fl_c = color_get(tmp)) == -1 || data->fl_flag)
			return (-1);
		else
			data->fl_flag = 1;
	}
	else
	{
		if ((data->cl_c = color_get(tmp)) == -1 || data->cl_flag)
			return (-1);
		else
			data->cl_flag = 1;
	}
	return (1);
}
