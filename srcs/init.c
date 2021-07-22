/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:37:45 by abourdar          #+#    #+#             */
/*   Updated: 2021/07/19 10:37:47 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	initialize_win(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (map->mlx_ptr == NULL)
		return (FALSE);
	map->win_ptr = mlx_new_window(map->mlx_ptr, map->win_w,
			map->win_h, "So Long");
	if (map->win_ptr == NULL)
	{
		free(map->win_ptr);
		return (FALSE);
	}
	return (TRUE);
}

void	setup(t_map *map)
{
	map->pos_x = map->pos_x * map->tile_size;
	map->pos_y = map->pos_y * map->tile_size;
	map->img.mlx_img = mlx_new_image(map->mlx_ptr, map->win_w, map->win_h);
	map->img.addr = mlx_get_data_addr(map->img.mlx_img, &map->img.bpp,
			&map->img.line_len, &map->img.endian);
}

void	init_struc(t_map *map)
{
	map->error = 0;
	map->nb_line = 0;
	map->player = 0;
	map->collectible = 0;
	map->moves = 0;
	map->collectible_eat = 0;
	map->u = -1;
	map->check = 0;
	map->num_row = 0;
	map->num_col = 0;
}

void	init_parser(t_map *map, char *s, int fd)
{
	char	*line;
	int		ret;
	int		i;

	i = 0;
	ret = 1;
	init_struc(map);
	get_nb_line(map, s);
	map->pars = malloc_list(map, (sizeof(char *) * (map->nb_line + 1)));
	while (ret != 0 && !map->error)
	{
		ret = get_next_line(map, fd, &line);
		map->pars[i] = ft_strdup(map, line);
		pars_line(map, map->pars[i]);
		i++;
	}
	map->pars[i] = NULL;
	close(fd);
	if (!map->check)
		map->error++;
	if (!map->error)
	{
		map->error = check_map(map);
		get_player_pos(map);
	}
}

void	init_collectible(t_map *map)
{
	int	x;
	int	y;
	int	i;

	y = -1;
	i = 0;
	map->sprite = malloc_list(map, (sizeof(t_col) * map->collectible) + 1);
	while (map->pars[++y])
	{
		x = -1;
		while (map->pars[y][++x])
		{
			if (map->pars[y][x] == 'C')
			{
				map->sprite[i].x = x * map->tile_size;
				map->sprite[i].y = y * map->tile_size;
				map->sprite[i].eaten = 0;
				i++;
			}
		}
	}
}
