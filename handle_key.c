/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:37:22 by abourdar          #+#    #+#             */
/*   Updated: 2021/07/19 10:37:25 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	ft_exit(t_map *map)
{
	int	i;

	i = 0;
	while (i < 18)
	{
		if (map->txtrs[i].mlx_img)
			mlx_destroy_image(map->mlx_ptr, map->txtrs[i].mlx_img);
		i++;
	}
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	map->win_ptr = NULL;
	return (0);
}

void	new_position(t_map *map, float new_x, float new_y, int pos)
{
	if (!mapHasWallAt(new_x, new_y, map))
	{
		map->pos_x = new_x;
		map->pos_y = new_y;
		map->u = pos;
		map->moves++;
		put_moves_shell(map->moves);
	}
	if (exit_at(map->pos_x, map->pos_y, map))
	{
		if (map->collectible_eat == map->collectible)
			ft_exit(map);
		else
		{
			ft_putstr_fd("You still have collectibles to pick ", 1);
			ft_putstr_fd("come back later\n", 1);
		}	
	}
}

int	handle_keypress(int keysym, t_map *map)
{
	if (keysym == XK_Escape)
		ft_exit(map);
	if (keysym == XK_w)
		new_position(map, map->pos_x, map->pos_y - map->tile_size, 1);
	if (keysym == XK_s)
		new_position(map, map->pos_x, map->pos_y + map->tile_size, -1);
	if (keysym == XK_d)
		new_position(map, map->pos_x + map->tile_size, map->pos_y, -2);
	if (keysym == XK_a)
		new_position(map, map->pos_x - map->tile_size, map->pos_y, 2);
	return (0);
}

void	hooks(t_map *map)
{
	mlx_loop_hook(map->mlx_ptr, &render, map);
	mlx_hook(map->win_ptr, KeyPress, KeyPressMask, &handle_keypress, map);
	mlx_hook(map->win_ptr, 33, 1L << 17, ft_exit, map);
	mlx_loop(map->mlx_ptr);
}
