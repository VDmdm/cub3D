/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_prs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 11:17:19 by jalvaro           #+#    #+#             */
/*   Updated: 2020/06/25 01:07:58 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_draw.h"

int		room_validate(char **arr, int y, int x)
{
	int ret_n;
	int ret_s;
	int ret_w;
	int ret_e;

	if (y == -1 || x == -1 || arr[y] == 0 || arr[y][x] == 0)
		return (32);
	if (arr[y][x] != '0' && arr[y][x] != '2')
		return (arr[y][x]);
	arr[y][x] = '.';
	ret_e = room_validate(arr, y, x + 1);
	ret_w = room_validate(arr, y, x - 1);
	ret_n = room_validate(arr, y + 1, x);
	ret_s = room_validate(arr, y - 1, x);
	if (ret_n == 32 || ret_s == 32 || ret_w == 32 || ret_e == 32)
		return (32);
	return (1);
}

int		correcting_map(char **map, int len)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (map[i])
	{
		j = -1;
		if (!(tmp = (char *)malloc(len + 1)))
			return (-1);
		while (map[i][++j])
			tmp[j] = map[i][j];
		while (j < len)
		{
			tmp[j] = ' ';
			j++;
		}
		tmp[j] = 0;
		free(map[i]);
		map[i] = tmp;
		i++;
	}
	map[i] = 0;
	return (1);
}

int		map_read(int fd, t_map *data, char *tmp)
{
	int i;
	int ret;

	i = 0;
	data->web[i] = ft_strdup(tmp);
	free(tmp);
	if (data->web[i] == 0 || map_read_check(data, i) == -1)
		return (-1);
	while ((ret = get_next_line(fd, &data->web[++i])) > 0)
	{
		if (!data->web[i][0] || map_read_check(data, i) == -1)
		{
			data->web[i + 1] = 0;
			return (-1);
		}
	}
	if (ret == -1)
		return (-1);
	if (map_read_check(data, i) == -1)
	{
		data->web[i + 1] = 0;
		return (-1);
	}
	data->web[++i] = 0;
	return (1);
}

int		map_parse(int fd, char *tmp, t_map *data)
{
	int i;
	int j;

	i = 0;
	if (map_read(fd, data, tmp) == -1)
		return (free_map(data->web));
	if (!data->plr_pos_flag)
		return (free_map(data->web));
	if (correcting_map(data->web, found_max_len(data->web)) == -1)
		return (free_map(data->web));
	while (data->web[i])
	{
		j = 0;
		while (data->web[i][j])
		{
			if (data->web[i][j] == '0')
			{
				if (room_validate(data->web, i, j) == 32)
					return (free_map(data->web));
			}
			j++;
		}
		i++;
	}
	return (1);
}
