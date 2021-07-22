/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:37:15 by abourdar          #+#    #+#             */
/*   Updated: 2021/07/19 10:37:16 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	draw_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = 0;
	while (i < rect.height + 1)
	{
		j = 0;
		while (j < rect.width + 1)
		{
			img_pix_put(img, j + rect.x, i + rect.y, rect.color);
			j++;
		}
		++i;
	}
	return (0);
}

void	draw_tiles(int x, int y, t_map *map, int color)
{
	draw_rect(&map->img, (t_rect){x,
		y, map->tile_size,
		map->tile_size, color});
}
