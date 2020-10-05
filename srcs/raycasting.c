/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 12:44:22 by jalvaro           #+#    #+#             */
/*   Updated: 2020/06/22 21:46:31 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_draw.h"

void	dest_draw(t_data *data, double x, double y, int i)
{
	if ((int)data->var.x_prev_dev != (int)data->var.x_dev_scale &&
		(int)data->var.y_prev_dev != (int)data->var.y_dev_scale)
	{
		data->var.dist = hypot(data->plr.plr_x - round(x + .5),
				data->plr.plr_y - round(y + .5)) * data->var.c_tab[i];
		draw(data, y);
	}
	else if ((int)data->var.x_prev_dev != (int)data->var.x_dev_scale)
	{
		data->var.dist = hypot(data->plr.plr_x - round(x + .5),
				data->plr.plr_y - y) * data->var.c_tab[i];
		draw(data, y);
	}
	else if (((int)data->var.x_prev_dev == (int)data->var.x_dev_scale))
	{
		data->var.dist = hypot(data->plr.plr_x - x,
				data->plr.plr_y - round(y + .5)) * data->var.c_tab[i];
		draw(data, x);
	}
}

void	dest_tex(t_data *data, int y, int s)
{
	if (data->var.flag == 0)
		my_mlx_pixel_put_text(data, &data->tex_no, y, s);
	if (data->var.flag == 2)
		my_mlx_pixel_put_text(data, &data->tex_so, y, s);
	if (data->var.flag == 3)
		my_mlx_pixel_put_text(data, &data->tex_ea, y, s);
	if (data->var.flag == 4)
		my_mlx_pixel_put_text(data, &data->tex_we, y, s);
}

int		draw(t_data *data, int s)
{
	int		i;

	i = 0;
	data->var.w_hight = (double)(SCALE) / round(data->var.dist - 0.5) *
										data->plr.proj_plan;
	data->var.y00 = -1;
	data->var.y0 = data->plr.h_vis - (data->var.w_hight / 2);
	data->var.y1 = data->plr.h_vis + (data->var.w_hight / 2);
	while (++data->var.y00 < data->var.y0 && data->var.y0 > 0)
		my_mlx_pixel_put(data, (int)data->var.y00, data->map.cl_c);
	while (data->var.y0 < data->var.y1 && data->var.y0 < data->mlx.win_y)
	{
		if (data->var.y0 >= 0)
			dest_tex(data, i, s);
		data->var.y0++;
		i++;
	}
	while (data->var.y0 < data->mlx.win_y)
	{
		if (data->var.y0 >= 0)
			my_mlx_pixel_put(data, data->var.y0, data->map.fl_c);
		data->var.y0++;
	}
	return (1);
}

void	cast_ray(t_data *data, double k, int i)
{
	double		x;
	double		y;

	x = data->plr.plr_x;
	y = data->plr.plr_y;
	data->var.sin_k = sin(k);
	data->var.cos_k = cos(k);
	while (data->map.web[(int)(y) >> 8][(int)(x) >> 8] != '1' &&
			data->map.web[(int)(y) >> 8][(int)(x) >> 8] != ' ')
	{
		x += data->var.cos_k;
		y += data->var.sin_k;
	}
	data->var.ray_x = x;
	data->var.ray_y = y;
	x_y_vars_calc(data);
	v_h_calc(data);
	data->var.prev_flag = data->var.flag;
	dest_draw(data, x, y, i);
}

int		raycast_init(t_data *data)
{
	int		i;
	double	dist[data->mlx.win_x];

	i = 0;
	data->var.k = data->plr.r_pov - data->plr.half_fov;
	while (i < data->mlx.win_x)
	{
		data->var.x0 = i;
		cast_ray(data, data->var.k, i);
		dist[i] = data->var.dist;
		data->var.k = data->var.k + data->var.b_row;
		i++;
	}
	calculate_sprite(data, dist);
	return (1);
}
