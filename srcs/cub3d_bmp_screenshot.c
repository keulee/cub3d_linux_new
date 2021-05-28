/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bmp_screenshot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:30:16 by keulee            #+#    #+#             */
/*   Updated: 2021/05/19 23:26:30 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	make_bmp_screenshot(t_game *game)
{
	int	file_size;
	int	fd;

	ray_processing(game);
	sprite_ray_processing(game);
	file_size = 14 + 40 + 4 * (game->info.win_width * game->info.win_height);
	fd = open(BMP_NAME, O_RDWR | O_TRUNC | O_CREAT, 00755);
	if (fd < 0)
		error_msg("ERROR: Bmp file create failed");
	ft_putstr("Creating Bmp file...\n");
	set_bmp_header(game, file_size, fd);
	write_bmp_data(game, fd);
	printf("Bmp file saved with a file name: %s\n", BMP_NAME);
	exit(0);
}

void	set_bmp_header(t_game *game, int file_size, int fd)
{
	int	off;

	off = 54;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	file_size = 0;
	write(fd, &file_size, 4);
	write(fd, &off, 4);
	set_bmp_info(game, fd);
}

void	set_bmp_info(t_game *game, int fd)
{
	int	header;
	int	plane;
	int	size;

	size = game->info.win_width * game->info.win_height;
	plane = 1;
	header = 40;
	write(fd, &header, 4);
	write(fd, &game->info.win_width, 4);
	write(fd, &game->info.win_height, 4);
	write(fd, &plane, 2);
	write(fd, &game->img.bpp, 2);
	size = 0;
	write(fd, &size, 4);
	write(fd, &size, 4);
	write(fd, &size, 4);
	write(fd, &size, 4);
	write(fd, &size, 4);
	write(fd, &size, 4);
	write(fd, &size, 4);
}

void	write_bmp_data(t_game *game, int fd)
{
	int	y;
	int	x;

	y = game->info.win_height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < game->info.win_width)
		{
			write(fd, &game->buf[y][x], 4);
			x++;
		}
		y--;
	}
}
