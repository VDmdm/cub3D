/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 20:21:17 by jalvaro           #+#    #+#             */
/*   Updated: 2020/06/25 01:25:19 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_draw.h"

int		math_get(t_data *data)
{
	data->var.half_x = data->mlx.win_x / 2;
	data->var.half_y = data->mlx.win_y / 2;
	data->plr.h_vis = data->var.half_y;
	data->plr.d_pov = pov_get(data->map.plr_pos_flag);
	data->plr.r_pov = data->plr.d_pov * (M_PI / 180);
	data->plr.d_fov = 60.0;
	data->plr.r_fov = data->plr.d_fov * (M_PI / 180);
	data->plr.half_fov = data->plr.r_fov / 2;
	data->plr.proj_plan = data->var.half_x / tan(data->plr.half_fov);
	data->var.b_row = data->plr.r_fov / data->mlx.win_x;
	if (ctable_get(data) == -1)
		return (-1);
	data->var.row_nbr = 0;
	data->plr.plr_x = ((data->map.plr_pos_j * SCALE) + ((double)SCALE / 2));
	data->plr.plr_y = ((data->map.plr_pos_i * SCALE) + ((double)SCALE / 2));
	return (1);
}

void	check_win_size(t_mlx *mlx)
{
	mlx_get_screen_size(mlx->mlx_ptr, &mlx->size_x, &mlx->size_y);
	if (mlx->size_x < mlx->win_x)
		mlx->win_x = mlx->size_x;
	if (mlx->size_y < mlx->win_y)
		mlx->win_y = mlx->size_y;
}

int		win_get(t_mlx *mlx)
{
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_x,
										mlx->win_y, "cube3D");
	if (!mlx->win_ptr)
		return (-1);
	return (1);
}

int		texture_get(t_img *img, char **path, void *mlx_ptr)
{
	img->ptr = mlx_xpm_file_to_image(mlx_ptr, *path, &img->x, &img->y);
	if (!img->ptr)
		return (-1);
	img->addr = mlx_get_data_addr(img->ptr, &img->bits_per_pixel,
								&img->size_line, &img->endian);
	if (!img->addr)
		return (-1);
	free(*path);
	*path = 0;
	return (1);
}

int		data_init(t_data *data)
{
	void *ptr;

	if (!(data->mlx.mlx_ptr = mlx_init()))
		return (error_ret("Error!\nCan't get MLX pointer.\n"));
	ptr = data->mlx.mlx_ptr;
	if (texture_get(&data->tex_no, &data->map.path_tx_no, ptr) == -1 ||
		texture_get(&data->tex_so, &data->map.path_tx_so, ptr) == -1 ||
		texture_get(&data->tex_we, &data->map.path_tx_we, ptr) == -1 ||
		texture_get(&data->tex_ea, &data->map.path_tx_ea, ptr) == -1 ||
		texture_get(&data->tex_s, &data->map.path_tx_s, ptr) == -1)
		return (error_ret("Error!\nCan't open texture file.\n"));
	check_win_size(&data->mlx);
	if (!data->mlx.save)
	{
		if (win_get(&data->mlx) == -1)
			return (error_ret("Error!\nMLX can't create window.\n"));
	}
	if (math_get(data) == -1)
		return (error_ret("Error!\nC_tab badalloc.\n"));
	return (1);
}
