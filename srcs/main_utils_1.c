/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 12:40:10 by jalvaro           #+#    #+#             */
/*   Updated: 2020/06/21 17:59:53 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_draw.h"

int		error_ret(char *txt)
{
	ft_putstr(txt);
	return (-1);
}

int		free_tex(t_map *map)
{
	if (map->path_tx_no)
		free(map->path_tx_no);
	if (map->path_tx_so)
		free(map->path_tx_so);
	if (map->path_tx_we)
		free(map->path_tx_we);
	if (map->path_tx_ea)
		free(map->path_tx_ea);
	if (map->path_tx_s)
		free(map->path_tx_s);
	return (-1);
}

int		parse_free_ret(t_map *map, char *str, int fd)
{
	char *tmp;

	tmp = 0;
	free_tex(map);
	if (str)
		free(str);
	while (get_next_line(fd, &tmp) > 0)
		free(tmp);
	if (tmp)
		free(tmp);
	return (-1);
}

void	map_data_null(t_data *data)
{
	data->mlx.win_x = 0;
	data->mlx.win_y = 0;
	data->mlx.mlx_ptr = 0;
	data->mlx.win_ptr = 0;
	data->map.plr_pos_flag = 0;
	data->map.path_tx_no = 0;
	data->map.path_tx_so = 0;
	data->map.path_tx_we = 0;
	data->map.path_tx_ea = 0;
	data->map.path_tx_s = 0;
	data->map.fl_flag = 0;
	data->map.cl_flag = 0;
	data->tex_no.ptr = 0;
	data->tex_so.ptr = 0;
	data->tex_ea.ptr = 0;
	data->tex_we.ptr = 0;
	data->tex_s.ptr = 0;
	data->img_main.ptr = 0;
	data->map.spr_id = 0;
	data->var.c_tab = 0;
}

int		check_args(int ac, char **av, t_data *data)
{
	data->mlx.save = 0;
	if (ac == 1 || ac > 3)
		return (error_ret("Error!\nWrong number of argument.\n"));
	if (ac == 3)
	{
		if (!ft_strnstr(av[2], "--save", 6) || av[2][6])
			return (error_ret("Error!\nWrong second argument.\n"));
		data->mlx.save = 1;
	}
	return (1);
}
