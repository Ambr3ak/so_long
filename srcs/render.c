/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:38:39 by abourdar          #+#    #+#             */
/*   Updated: 2021/07/19 10:38:40 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_transparency(t_map *map, int x, int y, int color)
{
	if (color != pixel_get_color(&map->txtrs[0], 0, 0))
		img_pix_put(&map->img, x, y, color);
}

void	renderCollectible(t_map *map)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (i < map->collectible)
	{
		if (map->sprite[i].x == map->pos_x
			&& map->sprite[i].y == map->pos_y
			&& map->sprite[i].eaten == 0)
		{
			map->sprite[i].eaten = 1;
			map->collectible_eat++;
		}
		else if (map->sprite[i].eaten == 0)
		{
			draw_anim(map, map->sprite[i], map->txtrs[0], x);
		}
		i++;
	}
}

void	renderPlayer(t_map *map)
{
	if (map->u == 1)
		draw_player(map, map->txtrs[14]);
	else if (map->u == -1)
		draw_player(map, map->txtrs[15]);
	else if (map->u == 2)
		draw_player(map, map->txtrs[16]);
	else if (map->u == -2)
		draw_player(map, map->txtrs[17]);
}	

void	renderMap(t_map *map)
{
	t_recup	*r;

	r = malloc_list(map, sizeof(t_recup));
	r->x = 0;
	while (map->pars[r->x])
	{
		r->y = 0;
		while (map->pars[r->x][r->y])
		{
			map->tyleX = r->y * map->tile_size;
			map->tyleY = r->x * map->tile_size;
			if (map->pars[r->x][r->y] == '1')
				draw_walls(map, map->tyleX, map->tyleY, map->txtrs[11]);
			else if (ft_strrchr("0PEC", map->pars[r->x][r->y]))
				choose_text(map, r, map->tyleX, map->tyleY);
			if (map->pars[r->x][r->y] == 'E')
				draw_exit(map, map->tyleX, map->tyleY, map->txtrs[13]);
			r->y++;
		}
		r->x++;
	}
}

int	render(t_map *map)
{
	if (map->win_ptr == NULL)
		return (1);
	renderMap(map);
	renderCollectible(map);
	renderPlayer(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.mlx_img, 0, 0);
	return (0);
}
