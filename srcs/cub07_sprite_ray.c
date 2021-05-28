/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub07_sprite_ray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:29:43 by keulee            #+#    #+#             */
/*   Updated: 2021/05/19 23:24:50 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	sprite_ray_processing(t_game *game)
{
	int	x;

	x = 0;
	sort_sprite_by_distance(&game->map, &game->player);
	while (x < game->map.count_sprite)
	{
		translate_sprite(game, &game->player, &game->sprite_ray, x);
		calculate_sprite_height(game, &game->sprite_ray);
		calculate_sprite_width(game, &game->sprite_ray);
		sprite_draw(game, &game->sprite_ray);
		x++;
	}
}

void	sprite_draw(t_game *game, t_s_ray *s_ray)
{
	int	stripe;
	int	y;

	stripe = s_ray->draw_start_x;
	while (stripe < s_ray->draw_end_x)
	{
		s_ray->tex_x = (int)(256 * (stripe
					- (-s_ray->width / 2 + s_ray->screen_x))
				* TEX_WIDTH / s_ray->width) / 256;
		if (s_ray->transform_y > 0 && stripe > 0
			&& stripe < game->info.win_width
			&& s_ray->transform_y < game->z_buffer[stripe])
		{
			y = s_ray->draw_start_y;
			sprite_y_line_draw(game, s_ray, &y, &stripe);
		}
		stripe++;
	}
}

void	sprite_y_line_draw(t_game *game, t_s_ray *s_ray, int *y, int *stripe)
{
	int	d;
	int	color;

	while (*y < s_ray->draw_end_y)
	{
		d = (*y - s_ray->v_move_screen) * 256 - game->info.win_height
			* 128 + s_ray->height * 128;
		s_ray->tex_y = ((d * TEX_HEIGHT) / s_ray->height) / 256;
		color = game->info.texture[TEX_SPRITE]
		[TEX_WIDTH * s_ray->tex_y + s_ray->tex_x];
		if ((color & 0x00FFFFFF) != 0)
			game->buf[*y][*stripe] = color;
		(*y)++;
	}
}
