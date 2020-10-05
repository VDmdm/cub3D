/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalvaro <jalvaro@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 18:17:02 by jalvaro           #+#    #+#             */
/*   Updated: 2020/06/25 01:26:52 by jalvaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_DRAW_H
# define MAP_DRAW_H

# define SCALE 256
# define W 0x0077
# define A 0x0061
# define D 0x0064
# define S 0x0073
# define ESC 0x0053
# define L 0xFF51
# define R 0xFF53
# define UP 0xff52
# define DOWN 0xff54

# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/keysymdef.h>

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_x;
	int			win_y;
	int			size_x;
	int			size_y;
	int			save;
}				t_mlx;

typedef struct	s_img
{
	void		*ptr;
	char		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			weight;
	int			heigth;
	int			x;
	int			y;
}				t_img;

typedef struct	s_map
{
	char		*web[10000];
	double		spr[10000][3];
	int			spr_id;
	char		plr_pos_flag;
	int			plr_pos_i;
	int			plr_pos_j;
	char		*path_tx_no;
	char		*path_tx_so;
	char		*path_tx_we;
	char		*path_tx_ea;
	char		*path_tx_s;
	int			fl_flag;
	int			fl_c;
	int			cl_flag;
	int			cl_c;
}				t_map;

typedef struct	s_plr
{
	char		dir;
	double		plr_x;
	double		plr_y;
	double		r_pov;
	double		d_pov;
	double		r_fov;
	double		d_fov;
	double		half_fov;
	double		h_vis;
	double		proj_plan;
}				t_plr;

typedef struct	s_var
{
	double		half_x;
	double		half_y;
	double		ray_x;
	double		ray_y;
	double		*c_tab;
	double		b_row;
	double		cos_pov;
	double		sin_pov;
	int			row_nbr;
	double		k;
	double		y_prev;
	double		x_prev;
	double		y_dev_scale;
	double		x_dev_scale;
	double		y_prev_dev;
	double		x_prev_dev;
	double		y_mod_scale;
	double		x_mod_scale;
	double		dist;
	double		sin_k;
	double		cos_k;
	double		w_hight;
	int			close;
	int			flag;
	int			prev_flag;
	int			x0;
	int			y0;
	int			y1;
	int			y00;
}				t_var;

typedef struct	s_spr
{
	double		spr_dir;
	int			s_scr_size;
	int			h_o;
	int			v_o;
	int			x_o;
	int			y_o;
}				t_spr;

typedef struct	s_data
{
	t_mlx		mlx;
	t_map		map;
	t_img		img_main;
	t_img		tex_no;
	t_img		tex_so;
	t_img		tex_we;
	t_img		tex_ea;
	t_img		tex_s;
	t_img		cat;
	t_plr		plr;
	t_var		var;
	t_spr		spr;
}				t_data;

int				color_pars(t_map *data, char *tmp);
int				color_get(char *tmp);
int				data_init(t_data *data);
int				main_img_get(t_data *data);
int				win_get(t_mlx *mlx);
int				texture_get(t_img *img, char **path, void *mlx_ptr);
int				math_get(t_data *data);
int				free_ctable(double *arr);
int				pov_get(char dir);
int				ctable_get(t_data *data);
int				parse_init(t_data *data, int fd);
int				parse_check(t_data *data, char *tmp);
int				res_parse(t_mlx *mlx, char *tmp);
int				check_args(int ac, char **av, t_data *data);
void			map_data_null(t_data *data);
int				parse_free_ret(t_map *map, char *str, int fd);
int				free_tex(t_map *map);
int				error_ret(char *txt);
int				destroy(t_data *data);
int				destroy_tex(t_data *data);
int				map_parse(int fd, char *tmp, t_map *data);
int				map_read(int fd, t_map *data, char *tmp);
int				correcting_map(char **map, int len);
int				room_validate(char **arr, int y, int x);
int				free_map(char **map);
int				free_tmp_n_map(char *str, char **map);
int				found_max_len(char **map);
int				map_read_check(t_map *data, int i);
int				raycast_init(t_data *data);
void			cast_ray(t_data *data, double k, int i);
int				draw(t_data *data, int s);
void			my_mlx_pixel_put_text(t_data *data, t_img *tex, int y, int s);
void			my_mlx_pixel_put(t_data *data, int y, int color);
void			dest_tex(t_data *data, int y, int s);
void			x_y_vars_calc(t_data *data);
void			v_h_calc(t_data *data);
int				tex_parse(t_data *data, char *tmp);
int				tex_get(t_map *map, char *str, char *tmp);
int				spr_txt_get(t_map *data, char *tmp);
int				path_tx_check(t_map *map, char *tmp, char *tmp_dup);
int				pad(int keycode, t_data *data);
void			left_n_right(int keycode, t_data *data);
void			by_side(int keycode, t_data *data, double i, double j);
void			forvard_n_back(int keycode, t_data *data, double i, double j);
int				render(t_data *data);
int				data_parse(t_data *data, char *filename);
void			dest_draw(t_data *data, double x, double y, int i);
void			calculate_sprite(t_data *data, double *dist);
void			draw_sprite(t_data *data, double *dist, int k);
void			sprite_sort(t_data *data);
void			my_mlx_pixel_put_spr(t_data *data, int y, int x);
void			spr_pos_get(t_map *data, int i, int j);
int				screenshot_saver(t_data *data);
int				header_write(t_data *data, int fd);
void			check_win_size(t_mlx *mlx);

#endif
