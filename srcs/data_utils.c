/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 23:13:48 by jalvaro           #+#    #+#             */
/*   Updated: 2020/06/15 13:06:12 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_draw.h"

int		ctable_get(t_data *data)
{
	double	j;
	int		i;

	if (!(data->var.c_tab = (double *)malloc(sizeof(double) * data->mlx.win_x)))
		return (-1);
	i = 0;
	j = -30 * (M_PI / 180);
	while (i < (data->mlx.win_x))
	{
		data->var.c_tab[i] = cos(j);
		i++;
		j += data->var.b_row;
	}
	return (1);
}

int		pov_get(char dir)
{
	if (dir == 'N')
		return (-90);
	else if (dir == 'S')
		return (90);
	else if (dir == 'E')
		return (0);
	else
		return (180);
}
