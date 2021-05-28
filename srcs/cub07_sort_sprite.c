/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub07_sort_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keulee <keulee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:29:36 by keulee            #+#    #+#             */
/*   Updated: 2021/05/19 23:23:44 by keulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	sort_sprite_by_distance(t_map *m, t_player *p)
{
	int	i;

	i = 0;
	while (i < m->count_sprite)
	{
		m->sprite_order[i] = i;
		m->sprite_dist[i] = ((p->x - m->sprite[i].x) * (p->x - m->sprite[i].x)
				+ (p->y - m->sprite[i].y) * (p->y - m->sprite[i].y));
		i++;
	}
	sort_sprites(m->sprite_order, m->sprite_dist, m->count_sprite);
}

void	sort_sprites(int *sprite_order, double *sprite_dist, int sprite_count)
{
	t_pair	*sprites;
	int		i;

	sprites = (t_pair *)malloc(sizeof(t_pair) * sprite_count);
	if (!(sprites))
		error_msg("ERROR: Array(t_pair) malloc failed");
	i = 0;
	while (i < sprite_count)
	{
		sprites[i].first = sprite_dist[i];
		sprites[i].second = sprite_order[i];
		i++;
	}
	sort_sprite_order(sprites, sprite_count);
	i = 0;
	while (i < sprite_count)
	{
		sprite_dist[i] = sprites[sprite_count - i - 1].first;
		sprite_order[i] = sprites[sprite_count - i - 1].second;
		i++;
	}
	free(sprites);
}

void	sort_sprite_order(t_pair *orders, int sprite_count)
{
	t_pair	tmp;
	int		i;
	int		j;

	i = 0;
	while (i < sprite_count)
	{
		j = 0;
		while (j < sprite_count - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
			j++;
		}
		i++;
	}
}
