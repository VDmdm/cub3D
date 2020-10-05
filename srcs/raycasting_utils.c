/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 17:40:39 by jalvaro           #+#    #+#             */
/*   Updated: 2020/06/20 13:44:36 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_draw.h"

void	v_h_calc(t_data *data)
{
	if ((int)data->var.y_prev_dev > (int)data->var.y_dev_scale)
		data->var.flag = 0;
	else if ((int)data->var.y_prev_dev < (int)data->var.y_dev_scale)
		data->var.flag = 2;
	else if ((int)data->var.x_prev_dev < (int)data->var.x_dev_scale)
		data->var.flag = 4;
	else if ((int)data->var.x_prev_dev > (int)data->var.x_dev_scale)
		data->var.flag = 3;
	if ((int)data->var.x_prev_dev != (int)data->var.x_dev_scale &&
		(int)data->var.y_prev_dev != (int)data->var.y_dev_scale)
		data->var.flag = data->var.prev_flag;
}

void	x_y_vars_calc(t_data *data)
{
	data->var.x_prev = data->var.ray_x - data->var.cos_k;
	data->var.y_prev = data->var.ray_y - data->var.sin_k;
	data->var.x_dev_scale = data->var.ray_x / SCALE;
	data->var.y_dev_scale = data->var.ray_y / SCALE;
	data->var.x_prev_dev = data->var.x_prev / SCALE;
	data->var.y_prev_dev = data->var.y_prev / SCALE;
	data->var.flag = 0;
}

void	my_mlx_pixel_put(t_data *data, int y, int color)
{
	char	*dst;

	dst = data->img_main.addr + (y * data->img_main.size_line + data->var.x0 *
		(data->img_main.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_mlx_pixel_put_text(t_data *data, t_img *tex, int y, int s)
{
	char	*dst;
	char	*str;
	int		y_s;
	int		x_s;

	y_s = (int)(y / (data->var.w_hight / tex->y));
	if (data->var.flag == 2 || data->var.flag == 3)
		x_s = (int)(((SCALE - 1) - (s % SCALE)) /
				((double)SCALE / (double)tex->x));
	else
		x_s = (int)((s % SCALE) / ((double)SCALE / (double)tex->x));
	if (x_s > tex->x)
		x_s = tex->x;
	if (x_s < 0)
		x_s = 0;
	str = tex->addr + (y_s * tex->size_line +
						(x_s * (tex->bits_per_pixel / 8)));
	dst = data->img_main.addr + (data->var.y0 * data->img_main.size_line +
		data->var.x0 * (data->img_main.bits_per_pixel / 8));
	*(unsigned int*)dst = *(unsigned int*)str;
}
