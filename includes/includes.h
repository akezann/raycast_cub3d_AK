/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 09:34:23 by akezanna          #+#    #+#             */
/*   Updated: 2021/04/27 15:19:42 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _INCLUDES_H
# define _INCLUDES_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <stdint.h>
# include <mlx.h>
# include "./../srcs/parsing/structparse.h"
# include "./..//libft/libft.h"
# define KEY_ESC 53
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_L_ARR 123
# define KEY_R_ARR 124
# define MOVESPEED 0.6
# define ROTSPEED 0.15

typedef struct		s_img
{
	void	*img;
	void	*no_text;
	void	*so_text;
	void	*we_text;
	void	*ea_text;
	void	*sp_text;
	int		*no_addr;
	int		*so_addr;
	int		*we_addr;
	int		*ea_addr;
	int		*s_addr;
	int		*texture;
	int		width;
	int		height;
	int		size_l;
	int		bpp;
	int		endian;
}					t_img;

typedef struct		s_keys
{
	int		key_a;
	int		key_s;
	int		key_d;
	int		key_w;
	int		key_left_arr;
	int		key_right_arr;
}					t_keys;

typedef struct		s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	movespeed;
	double	rotspeed;
	double	oldplane_x;
	double	olddir_x;
}					t_player;

typedef struct		s_ray
{
	int		x;
	int		y;
	int		h;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perpwalldist;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	tex_step;
	double	tex_pos;
	int		color;
}					t_ray;

typedef struct		s_draw_sp
{
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				spritewidth;
	int				drawstartx;
	int				drawstarty;
	int				drawendx;
	int				drawendy;
	int				stripe;
	int				texx;
	int				texy;
	int				y;
	int				d;
	int				color;
}					t_draw_sp;

typedef struct		s_sprite
{
	double			x;
	double			y;
}					t_sprite;

# pragma pack(push, 1)

typedef struct		s_bitmapfile
{
	uint16_t		file_type;
	uint32_t		file_size;
	uint16_t		reserved_1;
	uint16_t		reserved_2;
	uint32_t		pixel_offset;
}					t_bitmapfile;

typedef struct		s_bitmapinfo
{
	uint32_t		header_size;
	int32_t			bmp_width;
	int32_t			bmp_height;
	uint16_t		num_planes;
	uint16_t		bits_per_pixel;
	uint32_t		compression;
	uint32_t		image_size;
	int32_t			xpixelpermeter;
	int32_t			ypixelpermeter;
	uint32_t		total_colors;
	uint32_t		important_colors;
}					t_bitmapinfo;

# pragma pack(pop)

typedef struct		s_screenshot
{
	int				width;
	int				height;
	int				bitcount;
	int				red;
	int				blue;
	int				green;
	int				winb;
	uint32_t		imagesize;
	unsigned char	*buf;
}					t_screenshot;

typedef struct		s_game
{
	void			*mlx;
	void			*win;
	t_img			no_tex;
	t_img			so_tex;
	t_img			we_tex;
	t_img			ea_tex;
	t_img			s_tex;
	t_img			img;
	t_ray			ray;
	t_draw_sp		draw_sp;
	t_sprite		*sprite;
	t_parsedata		parsedata;
	t_player		player;
	int				save;
	int				*sprite_order;
	double			*z_buff;
	t_screenshot	*shot;
}					t_game;

void				camera_left(t_player *player);
void				camera_right(t_player *player);
void				move_forward(t_player *player, t_parsedata *parsedata);
void				move_backward(t_player *player, t_parsedata *parsedata);
void				move_left(t_player *player, t_parsedata *parsedata);
void				move_right(t_player *player, t_parsedata *parsedata);
int					key_hook(int keycode, t_game *game);
void				get_sidedistances(t_ray *ray, t_player *player);
void				dda(t_ray *ray, t_parsedata *parsedata);
void				draw_walls(t_game *game, t_ray *ray, t_player *player,
						t_img *img);
void				text_calculs(t_game *game, t_player *player, t_ray *ray);
void				check_side(t_game *game);
void				get_player_pos(t_player *player, t_parsedata *parsedata);
int					is_dir(char c);
void				ft_sprites(t_game *game);
void				cal_sprite_size(t_game *game);
void				draw_sprite(t_game *game);
t_sprite			*ft_get_sprites(t_game *game);
void				ft_sort_sprites(t_game *game);
void				count_sprite(t_parsedata *parsedata);
t_screenshot		*ft_init_shot(t_game *game);
void				ft_screenshot(t_game *game);
void				ft_fill_shot(t_game *game, unsigned char *buf);
void				ft_screen_meta(t_game *game);
void				free_split(char	**map, int size);
void				check_args(t_game *game, int n, char **ar, int fd);

#endif
