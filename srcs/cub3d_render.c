/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:30:55 by keulee            #+#    #+#             */
/*   Updated: 2021/05/18 15:31:03 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_ceiling_and_floor(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->info.win_height - 1)
	{
		x = 0;
		while (x < game->info.win_width)
		{
			if (y > game->info.win_height / 2)
				game->buf[y][x] = game->info.floor_color;
			else
				game->buf[y][x] = game->info.ceiling_color;
			x++;
		}
		y++;
	}
}

void	render_screen(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->info.win_height)
	{
		x = 0;
		while (x < game->info.win_width)
		{
			game->img.data[game->info.win_width * y + x] = game->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
}
