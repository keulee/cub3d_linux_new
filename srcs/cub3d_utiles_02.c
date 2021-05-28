/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utiles_02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:31:30 by keulee            #+#    #+#             */
/*   Updated: 2021/05/19 23:34:31 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	map_component_check(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr("012NSEW ", line[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

int	empty_line_check(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	malloc_buffer(t_game *game)
{
	int	i;

	game->buf = ft_calloc(game->info.win_height + 1, sizeof(int **));
	if (!(game->buf))
		error_msg("ERROR: Buffer malloc failed");
	i = 0;
	while (i < game->info.win_height)
	{
		game->buf[i] = ft_calloc(game->info.win_width + 1, sizeof(int *));
		if (!(game->buf[i]))
			error_msg("ERROR: Buffer malloc failed");
		i++;
	}
}

void	malloc_z_buffer(t_game *game)
{
	game->z_buffer = (double *)ft_calloc(game->info.win_width, sizeof(double));
	if (!(game->z_buffer))
		error_msg("ERROR: z_buffer malloc failed");
}

void	malloc_sprite_utile(t_game *game)
{
	game->map.sprite = (t_sprite *)ft_calloc((game->map.count_sprite),
			sizeof(t_sprite));
	if (!(game->map.sprite))
		error_msg("ERROR: Array(t_sprite) malloc failed");
	game->map.sprite_order = (int *)ft_calloc((game->map.count_sprite),
			sizeof(int));
	if (!(game->map.sprite_order))
		error_msg("ERROR: Array(sprite_order) malloc failed");
	game->map.sprite_dist = (double *)ft_calloc((game->map.count_sprite),
			sizeof(double));
	if (!(game->map.sprite_dist))
		error_msg("ERROR: Array(sprite_dist) malloc failed");
}
