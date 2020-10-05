/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_prs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:48:42 by jalvaro           #+#    #+#             */
/*   Updated: 2020/06/25 01:42:11 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_draw.h"

int		path_tx_check(t_map *map, char *tmp, char *tmp_dup)
{
	if (*tmp == 'N')
	{
		if (map->path_tx_no)
			return (-1);
		map->path_tx_no = tmp_dup;
	}
	else if (*tmp == 'S' && *(tmp + 1) == 'O')
	{
		if (map->path_tx_so)
			return (-1);
		map->path_tx_so = tmp_dup;
	}
	else if (*tmp == 'W')
	{
		if (map->path_tx_we)
			return (-1);
		map->path_tx_we = tmp_dup;
	}
	else if (*tmp == 'E')
	{
		if (map->path_tx_ea)
			return (-1);
		map->path_tx_ea = tmp_dup;
	}
	return (1);
}

int		spr_txt_get(t_map *data, char *tmp)
{
	int		i;

	if (!ft_strnstr(tmp, "S ", 2))
		return (-1);
	if (data->path_tx_s)
		return (-1);
	i = 2;
	while (tmp[i] == ' ' && tmp[i])
		i++;
	if (!(data->path_tx_s = ft_strdup(&tmp[2])))
		return (-1);
	return (1);
}

int		tex_get(t_map *map, char *str, char *tmp)
{
	char	*tmp_dup;
	int		i;

	i = 0;
	while (tmp[i] == str[i])
		i++;
	if (!tmp[i] || str[i])
		return (-1);
	while (tmp[i] == ' ')
		i++;
	if (!(tmp_dup = ft_strdup(&tmp[i])))
		return (-1);
	if (path_tx_check(map, tmp, tmp_dup) == -1)
	{
		free(tmp_dup);
		return (-1);
	}
	return (1);
}

int		tex_parse(t_data *data, char *tmp)
{
	if ((tex_get(&data->map, "NO ", tmp) == -1 &&
		tex_get(&data->map, "SO ", tmp) == -1 &&
		tex_get(&data->map, "WE ", tmp) == -1 &&
		tex_get(&data->map, "EA ", tmp) == -1) &&
		spr_txt_get(&data->map, tmp) == -1)
		return (-1);
	return (1);
}
