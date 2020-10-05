/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_prs_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 14:21:40 by jalvaro           #+#    #+#             */
/*   Updated: 2020/06/21 14:07:48 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_draw.h"

void	spr_pos_get(t_map *data, int i, int j)
{
	data->spr[data->spr_id][0] = (double)(i * SCALE) + (double)(SCALE / 2);
	data->spr[data->spr_id][1] = (double)(j * SCALE) + (double)(SCALE / 2);
	data->spr[data->spr_id][2] = 0;
	data->spr_id += 1;
}

int		map_read_check(t_map *data, int i)
{
	int j;

	j = 0;
	while (data->web[i][j])
	{
		if (data->web[i][j] == 'N' || data->web[i][j] == 'W' ||
			data->web[i][j] == 'S' || data->web[i][j] == 'E')
		{
			if (data->plr_pos_flag)
				return (-1);
			data->plr_pos_flag = data->web[i][j];
			data->plr_pos_i = i;
			data->plr_pos_j = j;
			data->web[i][j] = '0';
		}
		else if (data->web[i][j] == '2')
			spr_pos_get(data, i, j);
		else if (data->web[i][j] != '1' && data->web[i][j] != '0' &&
				data->web[i][j] != 32)
			return (-1);
		j++;
	}
	return (1);
}

int		found_max_len(char **map)
{
	int i;
	int len;
	int len_tmp;

	i = 0;
	len = 0;
	len_tmp = 0;
	while (map[i])
	{
		len_tmp = ft_strlen(map[i]);
		if (len_tmp > len)
			len = len_tmp;
		i++;
	}
	return (len);
}

int		free_tmp_n_map(char *str, char **map)
{
	int i;

	i = 0;
	free(str);
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	return (-1);
}

int		free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	return (-1);
}
