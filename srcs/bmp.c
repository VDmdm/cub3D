/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 15:53:01 by jalvaro           #+#    #+#             */
/*   Updated: 2020/06/23 21:29:28 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_draw.h"

int		header_write(t_data *data, int fd)
{
	unsigned char	bmpfileheader[54];
	unsigned int	filesize;

	filesize = 54 + (data->img_main.x * data->img_main.y) * 4;
	ft_bzero(bmpfileheader, 54);
	*(short int *)bmpfileheader = (short)0x4d42;
	bmpfileheader[2] = (unsigned char)(filesize);
	bmpfileheader[3] = (unsigned char)(filesize >> 8);
	bmpfileheader[4] = (unsigned char)(filesize >> 16);
	bmpfileheader[5] = (unsigned char)(filesize >> 24);
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	bmpfileheader[18] = (unsigned char)(data->mlx.win_x);
	bmpfileheader[19] = (unsigned char)(data->mlx.win_x >> 8);
	bmpfileheader[20] = (unsigned char)(data->mlx.win_x >> 16);
	bmpfileheader[21] = (unsigned char)(data->mlx.win_x >> 24);
	bmpfileheader[22] = (unsigned char)(-data->mlx.win_y);
	bmpfileheader[23] = (unsigned char)(-data->mlx.win_y >> 8);
	bmpfileheader[24] = (unsigned char)(-data->mlx.win_y >> 16);
	bmpfileheader[25] = (unsigned char)(-data->mlx.win_y >> 24);
	bmpfileheader[26] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(32);
	if (write(fd, bmpfileheader, 54) == -1)
		return (-1);
	return (1);
}

int		screenshot_saver(t_data *data)
{
	int	data_size;
	int	fd;

	data_size = data->mlx.win_x * data->mlx.win_y * 4;
	if ((fd = open("screenshot.bmp", O_RDWR | O_CREAT | O_TRUNC | 0666)) < 0)
	{
		ft_putstr("Error!\nCant open screenshot.bmp\n");
		destroy(data);
		return (-1);
	}
	if (header_write(data, fd) == -1)
	{
		close(fd);
		destroy(data);
		return (error_ret("Error!\nCant write data in screenshot.bmp\n"));
	}
	if (write(fd, data->img_main.addr, data_size) == -1)
	{
		close(fd);
		destroy(data);
		return (error_ret("Error!\nCant write data in screenshot.bmp\n"));
	}
	close(fd);
	destroy(data);
	return (1);
}
