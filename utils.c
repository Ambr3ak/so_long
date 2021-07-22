/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:38:55 by abourdar          #+#    #+#             */
/*   Updated: 2021/07/19 10:38:56 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	get_map_size(t_map *map)
{
	map->win_w = map->tile_size * map->num_col;
	map->win_h = map->tile_size * map->num_row;
	if (map->win_h > 700)
	{
		map->tile_size = 700 / map->num_row;
		map->win_w = map->tile_size * map->num_col;
		map->win_h = map->tile_size * map->num_row;
	}
}

int	get_nb_line(t_map *map, char *file)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	while (get_next_line(map, fd, &line) == 1)
	{
		map->nb_line++;
	}
	map->nb_line++;
	close (fd);
	return (1);
}

int	exit_at(float x, float y, t_map *map)
{
	int	map_grid_index_x;
	int	map_grid_index_y;

	if (x < 0 || y < 0)
		return (FALSE);
	map_grid_index_x = x / map->tile_size;
	map_grid_index_y = y / map->tile_size;
	if (x >= map->win_w || y >= map->win_h)
		return (FALSE);
	return (map->pars[map_grid_index_y][map_grid_index_x] == 'E');
}

int	mapHasWallAt(float x, float y, t_map *map)
{
	int	map_grid_index_x;
	int	map_grid_index_y;

	if (x < 0 || y < 0)
		return (FALSE);
	map_grid_index_x = x / map->tile_size;
	map_grid_index_y = y / map->tile_size;
	if (x >= map->win_w || y >= map->win_h)
		return (FALSE);
	return (map->pars[map_grid_index_y][map_grid_index_x] == '1');
}

void	put_moves_shell(int moves)
{
	ft_putstr_fd("[MOVES ", 1);
	ft_putnbr_fd(moves, 1);
	ft_putstr_fd("]\n", 1);
}
