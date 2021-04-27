/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savescreen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akezanna <akezanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:48:14 by akezanna          #+#    #+#             */
/*   Updated: 2021/03/21 18:20:59 by akezanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/includes.h"

t_screenshot	*ft_init_shot(t_game *game)
{
	t_screenshot	*screenshot;

	screenshot = malloc(sizeof(t_screenshot));
	screenshot->width = game->parsedata.win_width;
	screenshot->height = game->parsedata.win_height;
	screenshot->bitcount = 24;
	screenshot->blue = 255;
	screenshot->green = 0;
	screenshot->red = 0;
	screenshot->winb = ((screenshot->width *
			screenshot->bitcount + 31) / 32) * 4;
	screenshot->imagesize = screenshot->winb * screenshot->height;
	screenshot->buf = malloc(screenshot->imagesize);
	return (screenshot);
}

void			ft_fill_shot(t_game *game, unsigned char *buf)
{
	int x;
	int	row;
	int	col;

	row = game->shot->height;
	x = 0;
	while (--row >= 0)
	{
		col = -1;
		while (++col < game->shot->width)
		{
			game->shot->red = (game->img.texture[x * game->parsedata.win_width +
				col] >> 16) & 0xFF;
			game->shot->green = (game->img.texture[x * game->parsedata.win_width
				+ col] >> 8) & 0xFF;
			game->shot->blue = game->img.texture[x * game->parsedata.win_width +
				col] & 0xFF;
			buf[row * game->shot->winb + col * 3 + 0] = game->shot->blue;
			buf[row * game->shot->winb + col * 3 + 1] = game->shot->green;
			buf[row * game->shot->winb + col * 3 + 2] = game->shot->red;
		}
		x++;
	}
}

void			ft_screen_meta(t_game *game)
{
	t_bitmapfile	fileheader;
	t_bitmapinfo	infoheader;
	int				fd;

	fd = open("screenshot.bmp", O_CREAT | O_RDWR, S_IRWXU);
	fileheader = (t_bitmapfile){ 0 };
	infoheader = (t_bitmapinfo){ 0 };
	ft_memcpy(&fileheader, "BM", 2);
	fileheader.file_size = 54 + game->shot->imagesize;
	fileheader.pixel_offset = 54;
	infoheader.header_size = 40;
	infoheader.num_planes = 1;
	infoheader.bmp_width = game->shot->width;
	infoheader.bmp_height = game->shot->height;
	infoheader.bits_per_pixel = game->shot->bitcount;
	infoheader.image_size = game->shot->imagesize;
	ft_fill_shot(game, game->shot->buf);
	write(fd, &fileheader, sizeof(fileheader));
	write(fd, &infoheader, sizeof(infoheader));
	write(fd, (char *)game->shot->buf, game->shot->imagesize);
	close(fd);
	free(game->shot->buf);
}

void			ft_screenshot(t_game *game)
{
	if (sizeof(t_bitmapfile) != 14 && sizeof(t_bitmapinfo) != 40)
		printf("BITmap not setup\n");
	game->shot = ft_init_shot(game);
	ft_screen_meta(game);
	printf("the screenshot in 'screenshot.bmp'.\n");
	exit(0);
}
