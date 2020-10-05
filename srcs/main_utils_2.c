/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 12:18:11 by jalvaro           #+#    #+#             */
/*   Updated: 2020/07/08 17:45:18 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_draw.h"

int		destroy_tex(t_data *data)
{
	if (data->tex_no.ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->tex_no.ptr);
	if (data->tex_so.ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->tex_so.ptr);
	if (data->tex_ea.ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->tex_ea.ptr);
	if (data->tex_we.ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->tex_we.ptr);
	if (data->tex_s.ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->tex_s.ptr);
	return (free_tex(&data->map));
}

int		destroy(t_data *data)
{
	if (data->img_main.ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->img_main.ptr);
	destroy_tex(data);
	free_map(data->map.web);
	if (data->var.c_tab)
		free(data->var.c_tab);
	if (data->mlx.win_ptr)
		mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	data->var.close = 1;
	exit(0);
}

int		main_img_get(t_data *data)
{
	data->img_main.ptr = mlx_new_image(data->mlx.mlx_ptr, data->mlx.win_x,
										data->mlx.win_y);
	if (!data->img_main.ptr)
		return (-1);
	data->img_main.addr = mlx_get_data_addr(data->img_main.ptr,
											&data->img_main.bits_per_pixel,
											&data->img_main.size_line,
											&data->img_main.endian);
	if (!data->img_main.addr)
		return (-1);
	return (1);
}
