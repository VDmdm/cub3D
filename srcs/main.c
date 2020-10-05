/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 19:08:19 by jalvaro           #+#    #+#             */
/*   Updated: 2020/06/21 18:15:20 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_draw.h"

int		render(t_data *data)
{
	if (data->var.close)
		return (-1);
	raycast_init(data);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
							data->img_main.ptr, 0, 0);
	return (1);
}

int		data_parse(t_data *data, char *filename)
{
	int		ret;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (error_ret("Error!\nCan't open .cub file.\n"));
	map_data_null(data);
	if ((ret = parse_init(data, fd)) == -1)
		return (error_ret("Error!\nError data parse from .cub.\n"));
	close(fd);
	if (data_init(data) == -1)
		return (destroy(data));
	if (main_img_get(data) == -1)
	{
		destroy(data);
		return (error_ret("Error!\nError mlx image get.\n"));
	}
	data->var.close = 0;
	return (1);
}

int		main(int ac, char **av)
{
	t_data	data;

	if (check_args(ac, av, &data) == -1)
		exit(-1);
	if (data_parse(&data, av[1]) == -1)
		exit(-1);
	if (data.mlx.save == 1)
	{
		raycast_init(&data);
		screenshot_saver(&data);
		exit(-1);
	}
	mlx_do_key_autorepeaton(data.mlx.mlx_ptr);
	mlx_hook(data.mlx.win_ptr, 17, 1L << 17, destroy, &data);
	mlx_key_hook(data.mlx.win_ptr, pad, &data);
	mlx_loop_hook(data.mlx.mlx_ptr, render, &data);
	mlx_loop(data.mlx.mlx_ptr);
	return (1);
}
