/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:38:29 by abourdar          #+#    #+#             */
/*   Updated: 2021/07/19 10:38:31 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_char(int c, t_map *map)
{	
	if (c == 'E')
		map->check++;
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

int	pars_line(t_map *map, char *str)
{
	int	i;

	i = -1;
	map->num_row++;
	if (str[0] == '\0')
		map->error++;
	while (str[++i])
	{
		if (!check_char(str[i], map))
			return (map->error = 1);
	}
	return (0);
}

void	get_player_pos(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->pars[y])
	{
		x = -1;
		while (map->pars[y][++x])
		{
			if (map->pars[y][x] == 'P')
			{
				map->pos_x = x;
				map->pos_y = y;
				map->player++;
			}
			if (map->pars[y][x] == 'C')
				map->collectible++;
		}
		y++;
	}
	if (map->player == 1 && map->collectible)
		init_collectible(map);
	else
		map->error++;
}

int	parse_wall(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->pars[i])
	{
		j = 0;
		while (map->pars[i][j])
		{
			if (map->pars[i][j] != '1')
				if (i == 0 || j == 0
					|| j == map->num_col - 1
					|| i == map->num_row - 1)
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->num_col = 0;
	while (map->pars[i])
	{
		j = 0;
		while (map->pars[0][map->num_col])
			map->num_col++;
		while (map->pars[i][j])
			j++;
		if (j != map->num_col)
			return (1);
		i++;
	}
	map->tile_size = 1000 / map->num_col;
	if (!parse_wall(map))
		get_map_size(map);
	else
		return (1);
	return (0);
}
