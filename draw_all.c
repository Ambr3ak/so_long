/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:37:06 by abourdar          #+#    #+#             */
/*   Updated: 2021/07/19 10:37:10 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	draw_player(t_map *map, t_img txtrs)
{
	int	tmp_x;
	int	tmp_y;
	int	y;
	int	x;

	tmp_x = map->pos_x;
	x = 0;
	while (x < map->tile_size)
	{
		y = 0;
		tmp_y = map->pos_y;
		while (y < map->tile_size)
		{
			draw_transparency(map, tmp_x, tmp_y++,
				get_sprite_color(&txtrs, x, y, map->tile_size));
			y++;
		}
		tmp_x++;
		x++;
	}
}

void	draw_anim(t_map *map, t_col sprite, t_img txtrs, int x)
{	
	int	tmp_x;
	int	tmp_y;
	int	y;

	tmp_x = sprite.x;
	while (x < map->tile_size)
	{
		y = 0;
		tmp_y = sprite.y;
		while (y < map->tile_size)
		{
			draw_transparency(map, tmp_x, tmp_y++,
				get_sprite_color(&txtrs, x, y, map->tile_size));
			y++;
		}
		tmp_x++;
		x++;
	}
}

void	draw_walls(t_map *map, int tylex, int tyley, t_img txtrs)
{	
	int	tmp_x;
	int	tmp_y;
	int	y;
	int	x;

	tmp_x = tylex;
	x = 0;
	while (x < map->tile_size)
	{
		y = 0;
		tmp_y = tyley;
		while (y < map->tile_size)
		{
			draw_transparency(map, tmp_x, tmp_y++,
				get_sprite_color(&txtrs, x, y, map->tile_size));
			y++;
		}
		tmp_x++;
		x++;
	}
}

void	draw_exit(t_map *map, int tylex, int tyley, t_img txtrs)
{	
	int	tmp_x;
	int	tmp_y;
	int	y;
	int	x;

	tmp_x = tylex;
	x = 0;
	map->E_x = tylex;
	map->E_y = tyley;
	while (x < map->tile_size)
	{
		y = 0;
		tmp_y = tyley;
		while (y < map->tile_size)
		{
			draw_transparency(map, tmp_x, tmp_y++,
				get_sprite_color(&txtrs, x, y, map->tile_size));
			y++;
		}
		tmp_x++;
		x++;
	}
}

int	draw_game(t_map *map)
{
	if (!(initialize_win(map)))
		return (-1);
	setup(map);
	load_textures(map);
	hooks(map);
	mlx_destroy_image(map->mlx_ptr, map->img.mlx_img);
	mlx_destroy_display(map->mlx_ptr);
	free(map->mlx_ptr);
	return (0);
}
