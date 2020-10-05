/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 19:16:32 by jalvaro           #+#    #+#             */
/*   Updated: 2020/06/20 15:05:21 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_draw.h"

void	forvard_n_back(int keycode, t_data *data, double i, double j)
{
	if (keycode == W &&
		data->map.web
		[(int)(i + (data->var.sin_pov * 2)) / SCALE]
		[(int)(j + (data->var.cos_pov * 2)) / SCALE]
		== '.')
	{
		data->plr.plr_y += data->var.sin_pov;
		data->plr.plr_x += data->var.cos_pov;
	}
	if (keycode == S &&
		data->map.web\
		[(int)(i - (data->var.sin_pov * 2)) / SCALE]\
		[(int)(j - (data->var.cos_pov * 2)) / SCALE]\
		== '.')
	{
		data->plr.plr_y -= data->var.sin_pov;
		data->plr.plr_x -= data->var.cos_pov;
	}
}

void	by_side(int keycode, t_data *data, double i, double j)
{
	if (keycode == A &&
	data->map.web
	[(int)(i - (data->var.cos_pov * 2)) / SCALE]
	[(int)(j + (data->var.sin_pov * 2)) / SCALE]
	== '.')
	{
		data->plr.plr_x += data->var.sin_pov;
		data->plr.plr_y -= data->var.cos_pov;
	}
	if (keycode == D &&
	data->map.web
	[(int)(i + (data->var.cos_pov * 2)) / SCALE]
	[(int)(j - (data->var.sin_pov * 2)) / SCALE]
	== '.')
	{
		data->plr.plr_x -= data->var.sin_pov;
		data->plr.plr_y += data->var.cos_pov;
	}
}

void	left_n_right(int keycode, t_data *data)
{
	if (keycode == L)
		data->plr.r_pov = fmod(data->plr.r_pov - 0.035, 2 * M_PI);
	if (keycode == R)
		data->plr.r_pov = fmod(data->plr.r_pov + 0.035, 2 * M_PI);
}

int		pad(int keycode, t_data *data)
{
	double i;
	double j;

	i = data->plr.plr_y;
	j = data->plr.plr_x;
	data->var.cos_pov = cos(data->plr.r_pov) * (SCALE / 5);
	data->var.sin_pov = sin(data->plr.r_pov) * (SCALE / 5);
	if (keycode == W || keycode == S)
		forvard_n_back(keycode, data, i, j);
	if (keycode == A || keycode == D)
		by_side(keycode, data, i, j);
	if (keycode == L || keycode == R)
		left_n_right(keycode, data);
	if (keycode == 0xff1b)
		destroy(data);
	if (keycode == DOWN && data->plr.h_vis > data->var.half_y / 2)
		data->plr.h_vis -= 10;
	if (keycode == UP && data->plr.h_vis < data->var.half_y +
										data->var.half_y / 2)
		data->plr.h_vis += 10;
	return (1);
}
