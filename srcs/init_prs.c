/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:48:42 by jalvaro           #+#    #+#             */
/*   Updated: 2020/06/21 12:35:10 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_draw.h"

int		res_parse(t_mlx *mlx, char *tmp)
{
	int		i;

	i = 2;
	if (mlx->win_x > 0)
		return (-1);
	while (tmp[i] == ' ' && tmp[i])
		i++;
	if ((mlx->win_x = ft_atoi(&tmp[i])) < 1)
		return (-1);
	i += ft_skip_nbr(&tmp[i]);
	while (tmp[i] == ' ' && tmp[i])
		i++;
	if ((mlx->win_y = ft_atoi(&tmp[i])) < 1)
		return (-1);
	return (1);
}

int		parse_check(t_data *data, char *tmp)
{
	if (!(tmp - ft_strnstr(tmp, "R ", 2)))
		return (res_parse(&data->mlx, tmp));
	else if (ft_strnstr(tmp, "NO ", 3) ||
			ft_strnstr(tmp, "SO ", 3) ||
			ft_strnstr(tmp, "WE ", 3) ||
			ft_strnstr(tmp, "EA ", 3) ||
			ft_strnstr(tmp, "S ", 2))
		return (tex_parse(data, tmp));
	else if (ft_strnstr(tmp, "C ", 2) ||
			ft_strnstr(tmp, "F ", 2))
		return (color_pars(&data->map, tmp));
	else if (!tmp[0])
		return (0);
	else
		return (-1);
}

int		parse_init(t_data *data, int fd)
{
	int		ret;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (i < 8 && (ret = get_next_line(fd, &tmp)) > 0)
	{
		if ((j = parse_check(data, tmp)) == -1)
			return (parse_free_ret(&data->map, tmp, fd));
		i += j;
		free(tmp);
	}
	if (ret <= 0)
		return (parse_free_ret(&data->map, tmp, fd));
	while (((ret = get_next_line(fd, &tmp)) > 0) && !*tmp)
		free(tmp);
	if (ret <= 0)
		return (parse_free_ret(&data->map, tmp, fd));
	if (map_parse(fd, tmp, &data->map) == -1)
	{
		tmp = 0;
		return (parse_free_ret(&data->map, tmp, fd));
	}
	return (1);
}
