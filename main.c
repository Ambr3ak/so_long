/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 09:50:21 by abourdar          #+#    #+#             */
/*   Updated: 2021/07/16 09:50:26 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_error(t_map *map, int err_arg)
{
	if (err_arg == 1)
		ft_putstr_fd("Error\nWrong arguments", 1);
	else if (map->error)
		ft_putstr_fd("Error\nWrong map", 1);
	else if (map->collectible != map->collectible_eat)
		ft_putstr_fd("You still have collectibles to pick up !\n", 1);
	else
	{
		ft_putstr_fd("Congrats, you earned ", 1);
		ft_putnbr_fd(map->collectible, 1);
		ft_putstr_fd(" coins in ", 1);
		ft_putnbr_fd(map->moves, 1);
		ft_putstr_fd(" moves, Try your best !\n", 1);
	}
	free_malloc_lst(map);
	free(map);
	exit (0);
}

int	ft_check_argv(char *map_name)
{
	int	i;

	i = ft_strlen(map_name) - 1;
	if (map_name[i--] == 'r')
		if (map_name[i--] == 'e')
			if (map_name[i--] == 'b')
				if (map_name[i--] == '.')
					return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	*map;
	int		i;

	i = 0;
	map = malloc(sizeof(t_map));
	map->ptrs = NULL;
	fd = 0;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		ft_error(map, 1);
	if ((argc == 2 && !ft_check_argv(argv[1])) || fd == -1)
		ft_error(map, 1);
	init_parser(map, argv[1], fd);
	if (!map->error)
		draw_game(map);
	ft_error(map, 0);
}
