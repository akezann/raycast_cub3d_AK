/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structparse.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:39:14 by akezanna          #+#    #+#             */
/*   Updated: 2021/03/22 12:31:33 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STRUCTPARSE_H
# define _STRUCTPARSE_H

typedef	struct	s_parsedata
{
	int		win_width;
	int		win_height;
	char	*no_text;
	char	*so_text;
	char	*ea_text;
	char	*we_text;
	char	*s_text;
	int		ceil_color;
	int		floor_color;
	char	**map;
	char	*tmp_map;
	char	dir_type;
	int		dir_count;
	int		map_cols;
	int		map_rows;
	int		ident_count;
	int		sprite_num;
	int		p_posx;
	int		p_posy;
}				t_parsedata;

int				get_resolution(t_parsedata *parsedata, char *line);
void			get_sprite(t_parsedata *parsedata, char *line);
void			get_textures(t_parsedata *parsedata, char *line);
int				map_layout(char **map, int nb_rows, int nb_cols);
int				save_map(t_parsedata *parsedata, int fd);
int				wrong_char_in_map(char c);
int				check_chars(char c);
int				check_chars_line(char *line);
int				check_walls(char *map, int nb);
int				check_dir(char **map, int rows, int cols);
int				check_chars_ok(char c);
int				check_file_extension(char *line, char *ext, int n);
int				is_number(char *number);
int				is_spaces(char *number);
int				ceil_floor_color(t_parsedata *parsedata, char *line, char c);
void			init_map_data(t_parsedata *parsedata);
int				check_ident(char *line);
int				check_chars_valide(char c);
void			add_str_chars(char	*s, char c, int n);
void			set_map(char **map, t_parsedata *data);

#endif
