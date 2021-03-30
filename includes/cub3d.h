/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:27:36 by omillan           #+#    #+#             */
/*   Updated: 2021/03/30 11:52:10 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "./mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# define MOVE 0.15

typedef struct			s_mlx_win
{
	void				*mlx;
	void				*win;
	int					win_x;
	int					win_y;
	int					x_max;
	int					y_max;
	int					bmp_x;
	int					bmp_y;
}						t_mlx_win;

typedef struct			s_data_img
{
	void				*img;
	void				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_data_img;

typedef struct			s_f_c_colors
{
	int					f_color;
	int					c_color;
}						t_f_c_colors;

typedef struct			s_tex_to_img
{
	void				*img;
	void				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					width;
	int					higth;
}						t_tex_to_img;

typedef struct			s_textures
{
	char				*no_path;
	char				*so_path;
	char				*we_path;
	char				*ea_path;
	char				*sprite;
}						t_textures;

typedef struct			s_flags
{
	int f;
	int c;
	int n;
	int w;
	int e;
	int so;
	int s;
	int r;
	int m;
}						t_flags;

typedef struct			s_plr
{
	double				x;
	double				y;
	double				dir;
	double				dir_x;
	double				dir_y;
	double				plan_x;
	double				plan_y;
	double				start;
	double				end;
}						t_plr;

typedef struct			s_lodev
{
	double				cam_x;
	double				ray_d_x;
	double				ray_dir_y;
	int					map_x;
	int					map_y;
	double				side_dst_x;
	double				side_dst_y;
	double				del_dst_x;
	double				del_dst_y;
	double				per_wal_dst;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	int					line_h;
	int					drow_start;
	int					drow_end;
	double				wal_x;
	int					text_x;
	double				step;
	double				text_pos;
	int					text_y;
	int					color;
}						t_lodev;

typedef struct			s_sprite
{
	double				x;
	double				y;
	int					count;
	t_tex_to_img		*spr_tex;
}						t_sprite;

typedef struct			s_pair
{
	double				f;
	int					sec;
}						t_pair;

typedef struct			s_all
{
	t_mlx_win			*mlx_win;
	t_data_img			*img_data;
	t_f_c_colors		*f_c_color;
	t_textures			*text;
	t_tex_to_img		*n;
	t_tex_to_img		*s;
	t_tex_to_img		*w;
	t_tex_to_img		*e;
	t_tex_to_img		*sprite;
	t_flags				*f;
	t_plr				*plr;
	t_sprite			*spr;
	t_lodev				*l;
	char				**map;
	int					conf_x;
	int					conf_y;
}						t_all;

typedef struct			s_draw_spr
{
	int					z;
	double				spr_x;
	double				spr_y;
	double				inv;
	double				trans_x;
	double				trans_y;
	int					spr_screen_x;
	int					spr_height;
	int					drow_start_y;
	int					drow_end_y;
	int					spr_width;
	int					drow_start_x;
	int					drow_end_x;
	int					color;
	int					tex_y;
	int					tex_x;
}						t_draw_spr;

int						create_trgb(int t, int r, int g, int b);
void					my_mlx_pixel_put(t_all *all, int x, int y, int color);
void					make_rect_buf(t_all *all, int color);
int						key_hook(int keycode, t_all *all);
void					put_rect(t_all *all, int x, int y, int color);
void					put_error(int i);
char					**check_map(int argc, char **argv, t_all *all);
t_list					*parser(int fd, t_all *all);
t_data_img				*make_img_data(void);
t_f_c_colors			*make_f_c_color(void);
t_mlx_win				*make_mlx_win(void);
t_textures				*make_text(void);
t_all					*make_all(void);
int						map_elements(char *s, t_all *all, int tr);
int						get_r(char *line, t_all *all);
int						get_f_c_color(char *line, t_all *all, char f_c);
int						get_path(char *line, t_all *all, char c);
int						trim(char *s, t_all *all);
int						put_str(char *s);
t_flags					*make_flags(void);
int						check_flags(t_all *all);
int						check_file(char *s);
int						num_str_free_arr(char **ar, int k);
void					get_path_help(char **arr, t_all *all, char c);
int						chek_minus(char **arr);
char					**get_map(t_list *head, t_all *all);
void					drow_map(t_all *all);
t_plr					*make_plr(void);
int						put_map(t_all *all);
void					plr_bihevior(t_all *all);
void					ft_cast_ray(t_all *all);
void					ft_load_cub(t_all *all);
int						krest(t_all *all);
t_lodev					*make_l(t_all *all, int i);
t_tex_to_img			*make_tex_to_img(void);
void					load_textures(t_all *all);
int						flood_fill(int x, int y, char n, char **map);
int						count_colomn(char **ar);
char					**copy_map(char **map);
int						count_point(char *s);
void					if_s(t_all *all);
void					if_n(t_all *all);
void					if_w(t_all *all);
void					if_e(t_all *all);
void					exit_all(t_all *all, int i);
int						ft_flood(char **map, int k, int j);
int						count_point(char *s);
int						plr_num(t_all *all, char **map);
void					ft_return(int i, t_all *all);
int						check_file(char *s);
t_sprite				*make_sprite(void);
void					sort_order(t_pair *orders, int count);
void					sprite_array(t_sprite s_pr[], t_all *all,
											int spr_order[], double spr_dist[]);
void					drow_sprites(t_all *all, t_tex_to_img *t, double buf[]);
t_draw_spr				*make_dr(void);
t_sprite				*make_sprite(void);
void					sprite_array(t_sprite s_pr[], t_all *all,
											int spr_order[], double spr_dist[]);
void					sort_order(t_pair *orders, int count);
int						count_alph(char *l);
void					free_else(t_all *all);
void					free_tex(t_all *all);
int						if_no_digit(char **ar);
int						count_zpt(char *l);
int						count_dig(char *l);
int						count_alph(char *l);
int						is_minus(char *s);
int						save_bmp(t_all *all);
void					nul_buf(char *buf, char *buffer);
int						check_plr_out(char *l);
int						max_len(char **ar);
int						plr_pos(char **map, int x, int y);
void					int_to_char(int i, char *buf);
int						another_char(char **map);

#endif
