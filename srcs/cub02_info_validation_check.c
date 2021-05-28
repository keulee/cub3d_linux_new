/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub02_info_validation_check.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:24:35 by keulee            #+#    #+#             */
/*   Updated: 2021/05/28 14:55:15 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	file_validation_check(int ac, char **av)
{
	//game->save = OFF;
	if (ac != 2)
		error_msg("ERROR: Argument Not Enough or Too Many");
	if (ac == 2 && (ft_strstr_cub(av[1], ".cub")) != 1)
		error_msg("ERROR: Wrong .cub Extension");
	//if (ac == 3 && ft_strcmp(av[2], "--save") != 0)
	//	error_msg("ERROR: --save argument not corrected");
	//else if (ac == 3 && ft_strcmp(av[2], "--save") == 0)
	//	game->save = ON;
}

void	info_validation_check(t_game *game)
{
	if (game->info.mark == -1)
		error_msg("ERROR: Info element(s) Missing or Info not well aligned");
	if (!game->info.win_width || !game->info.win_height)
		error_msg("ERROR: Resolution Info missing");
	if (game->info.floor_color == -1 || game->info.ceiling_color == -1)
		error_msg("ERROR: Color Info missing");
	if (!game->info.tex_path[TEX_NORTH] || !game->info.tex_path[TEX_SOUTH]
		|| !game->info.tex_path[TEX_WEST] || !game->info.tex_path[TEX_EAST])
		error_msg("ERROR: Texture Info missing");
}

void	linux_resolution_max_min_check(t_game *game)
{
	int	r_width;
	int	r_height;
	int	check;

	r_width = 0;
	r_height = 0;
	check = 0;
	mlx_get_screen_size(game->mlx, &r_width, &r_height);
	if (game->info.win_width > r_width || game->info.win_width < 0)
	{
		game->info.win_width = r_width;
		check = 1;
	}
	if (game->info.win_height > r_height || game->info.win_height < 0)
	{
		game->info.win_height = r_height;
		check = 1;
	}
	if (check == 1)
		printf("INFO: Window resized as : %d %d\n",
			game->info.win_width, game->info.win_height);
}
