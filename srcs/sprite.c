/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 12:04:36 by jalvaro           #+#    #+#             */
/*   Updated: 2020/06/21 21:48:11 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_draw.h"

void	my_mlx_pixel_put_spr(t_data *data, int y, int x)
{
	char	*dst;
	char	*str;
	int		y_s;
	int		x_s;

	y_s = (int)(data->spr.y_o * data->tex_s.y / data->spr.s_scr_size);
	x_s = (int)(data->spr.x_o * data->tex_s.x / data->spr.s_scr_size);
	str = data->tex_s.addr + (y_s * data->tex_s.size_line + (x_s *
									(data->tex_s.bits_per_pixel / 8)));
	dst = data->img_main.addr + (y * data->img_main.size_line + x *
								(data->img_main.bits_per_pixel / 8));
	if ((unsigned char)str[0] == (unsigned char)0)
		return ;
	*(unsigned int*)dst = *(unsigned int*)str;
}

void	sprite_sort(t_data *data)
{
	double	tmp[3];
	int		i;

	i = 0;
	while (i < data->map.spr_id - 1)
	{
		if (data->map.spr[i][2] < data->map.spr[i + 1][2])
		{
			tmp[0] = data->map.spr[i][0];
			tmp[1] = data->map.spr[i][1];
			tmp[2] = data->map.spr[i][2];
			data->map.spr[i][0] = data->map.spr[i + 1][0];
			data->map.spr[i][1] = data->map.spr[i + 1][1];
			data->map.spr[i][2] = data->map.spr[i + 1][2];
			data->map.spr[i + 1][0] = tmp[0];
			data->map.spr[i + 1][1] = tmp[1];
			data->map.spr[i + 1][2] = tmp[2];
			i = 0;
		}
		i++;
	}
}

void	draw_sprite(t_data *data, double *dist, int k)
{
	data->spr.x_o = 0;
	while (data->spr.x_o < data->spr.s_scr_size)
	{
		data->spr.y_o = 0;
		if (data->spr.h_o + data->spr.x_o >= 0 &&
			data->spr.h_o + data->spr.x_o < data->mlx.win_x &&
			dist[data->spr.h_o + data->spr.x_o] + 100 > data->map.spr[k][2])
		{
			while (data->spr.y_o < data->spr.s_scr_size)
			{
				if (data->spr.v_o + data->spr.y_o >= 0 &&
					data->spr.v_o + data->spr.y_o < data->mlx.win_y)
					my_mlx_pixel_put_spr(data, data->spr.v_o + data->spr.y_o,
												data->spr.h_o + data->spr.x_o);
				data->spr.y_o++;
			}
		}
		data->spr.x_o++;
	}
}

void	calculate_sprite(t_data *data, double *dist)
{
	int k;

	k = -1;
	while (++k < data->map.spr_id)
		data->map.spr[k][2] = hypot(data->plr.plr_x - data->map.spr[k][1],
									data->plr.plr_y - data->map.spr[k][0]);
	sprite_sort(data);
	k = -1;
	while (++k < data->map.spr_id)
	{
		data->spr.spr_dir = atan2(data->map.spr[k][0] - data->plr.plr_y,
									data->map.spr[k][1] - data->plr.plr_x);
		while (data->spr.spr_dir - data->plr.r_pov > M_PI)
			data->spr.spr_dir -= 2 * M_PI;
		while (data->spr.spr_dir - data->plr.r_pov < -M_PI)
			data->spr.spr_dir += 2 * M_PI;
		data->spr.s_scr_size = (data->mlx.win_x / data->map.spr[k][2]) * SCALE;
		if (data->spr.s_scr_size > data->mlx.win_y)
			data->spr.s_scr_size = data->mlx.win_y;
		data->spr.h_o = (data->spr.spr_dir - data->plr.r_pov) *
				(data->mlx.win_x) / (data->plr.r_fov) + (data->mlx.win_x / 2) -
				data->spr.s_scr_size / 2;
		data->spr.v_o = data->plr.h_vis - data->spr.s_scr_size / 2;
		draw_sprite(data, dist, k);
	}
}
