/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utiles_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:31:20 by keulee            #+#    #+#             */
/*   Updated: 2021/05/19 23:29:40 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_exit_key(t_game *game)
{
	(void)game;
	exit_msg("CUB3D CLOSED, BYE!");
	exit(0);
}

void	error_msg(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	exit(-1);
}

void	exit_msg(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	exit(0);
}

void	free_tab2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

double	degree_to_radian(double degree)
{
	return (degree * (PI / 180.0));
}
