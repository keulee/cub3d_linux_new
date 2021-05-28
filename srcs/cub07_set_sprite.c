/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub07_set_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:29:25 by keulee            #+#    #+#             */
/*   Updated: 2021/05/19 23:22:46 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	translate_sprite(t_game *game, t_player *player, t_s_ray *s_ray, int i)
{
	double	v_mode;

	v_mode = 0.0;
	s_ray->x = game->map.sprite[game->map.sprite_order[i]].x - player->x;
	s_ray->y = game->map.sprite[game->map.sprite_order[i]].y - player->y;
	s_ray->inv_det = 1.0 / (player->plane_x * player->dir_y
			- player->dir_x * player->plane_y);
	s_ray->transform_x = s_ray->inv_det
		* (player->dir_y * s_ray->x - player->dir_x * s_ray->y);
	s_ray->transform_y = s_ray->inv_det
		* (-player->plane_y * s_ray->x + player->plane_x * s_ray->y);
	s_ray->screen_x = (int)((game->info.win_width / 2)
			* (1 - s_ray->transform_x / s_ray->transform_y));
	s_ray->v_move_screen = (int)(v_mode / s_ray->transform_y);
}

void	calculate_sprite_height(t_game *game, t_s_ray *s_ray)
{
	int	v_div;

	v_div = 1;
	s_ray->height = (int)fabs((game->info.win_height / s_ray->transform_y)
			/ v_div);
	s_ray->draw_start_y = -s_ray->height / 2 + game->info.win_height / 2
		+ s_ray->v_move_screen;
	if (s_ray->draw_start_y < 0)
		s_ray->draw_start_y = 0;
	s_ray->draw_end_y = s_ray->height / 2 + game->info.win_height / 2
		+ s_ray->v_move_screen;
	if (s_ray->draw_end_y >= game->info.win_height)
		s_ray->draw_end_y = game->info.win_height - 1;
}

void	calculate_sprite_width(t_game *game, t_s_ray *s_ray)
{
	int	u_div;

	u_div = 1;
	s_ray->width = (int)fabs((game->info.win_height / s_ray->transform_y)
			/ u_div);
	s_ray->draw_start_x = -s_ray->width / 2 + s_ray->screen_x;
	if (s_ray->draw_start_x < 0)
		s_ray->draw_start_x = 0;
	s_ray->draw_end_x = s_ray->width / 2 + s_ray->screen_x;
	if (s_ray->draw_end_x >= game->info.win_width)
		s_ray->draw_end_x = game->info.win_width - 1;
}

void	init_and_set_sprite(t_game *game)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (y < game->map.height_count)
	{
		x = 0;
		while (x < game->map.width_count)
		{
			if (game->map.map[y][x] == '2')
			{
				sprite_pos(game, i, x, y);
				i++;
			}
			x++;
		}
		y++;
	}
}

void	sprite_pos(t_game *game, int i, int x, int y)
{
	game->map.sprite[i].x = 0.5f + x;
	game->map.sprite[i].y = 0.5f + y;
}
