/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:38:46 by abourdar          #+#    #+#             */
/*   Updated: 2021/07/19 10:38:49 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	fill_txt(t_map *map, t_img *txts, char *path)
{
	txts->mlx_img = mlx_xpm_file_to_image(map->mlx_ptr, path,
			&txts->x, &txts->y);
	txts->addr = mlx_get_data_addr(txts->mlx_img, &txts->bpp, &txts->line_len,
			&txts->endian);
}

void	load_textures(t_map *map)
{
	int	i;

	i = 0;
	map->txtrs = malloc_list(map, (sizeof(t_img) * 18) + 1);
	fill_txt(map, &map->txtrs[0], "texture/coin.xpm");
	fill_txt(map, &map->txtrs[1], "texture/x-1.xpm");
	fill_txt(map, &map->txtrs[2], "texture/y-1.xpm");
	fill_txt(map, &map->txtrs[3], "texture/x-1y-1.xpm");
	fill_txt(map, &map->txtrs[4], "texture/x+1y+1.xpm");
	fill_txt(map, &map->txtrs[5], "texture/x-1y+1.xpm");
	fill_txt(map, &map->txtrs[6], "texture/x+1y-1.xpm");
	fill_txt(map, &map->txtrs[7], "texture/x+1x-1.xpm");
	fill_txt(map, &map->txtrs[8], "texture/y-1y+1.xpm");
	fill_txt(map, &map->txtrs[9], "texture/x+1.xpm");
	fill_txt(map, &map->txtrs[10], "texture/y+1.xpm");
	fill_txt(map, &map->txtrs[11], "texture/water.xpm");
	fill_txt(map, &map->txtrs[12], "texture/else.xpm");
	fill_txt(map, &map->txtrs[13], "texture/mong.xpm");
	fill_txt(map, &map->txtrs[14], "texture/up.xpm");
	fill_txt(map, &map->txtrs[15], "texture/down.xpm");
	fill_txt(map, &map->txtrs[16], "texture/left.xpm");
	fill_txt(map, &map->txtrs[17], "texture/right.xpm");
}

int	choose_big_text(t_map *map, t_recup *r, int tyleX, int tyleY)
{
	if (map->pars[r->x][r->y - 1] == '1'
		&& map->pars[r->x][r->y + 1] == '1')
		draw_walls(map, tyleX, tyleY, map->txtrs[7]);
	else if (map->pars[r->x - 1][r->y] == '1'
		&& map->pars[r->x + 1][r->y] == '1')
		draw_walls(map, tyleX, tyleY, map->txtrs[8]);
	else if (map->pars[r->x - 1][r->y] == '1'
		&& map->pars[r->x][r->y - 1] == '1')
		draw_walls(map, tyleX, tyleY, map->txtrs[3]);
	else if (map->pars[r->x + 1][r->y] == '1'
		&& map->pars[r->x][r->y + 1] == '1')
		draw_walls(map, tyleX, tyleY, map->txtrs[4]);
	else if (map->pars[r->x + 1][r->y] == '1'
		&& map->pars[r->x][r->y - 1] == '1')
		draw_walls(map, tyleX, tyleY, map->txtrs[5]);
	else if (map->pars[r->x - 1][r->y] == '1'
		&& map->pars[r->x][r->y + 1] == '1')
		draw_walls(map, tyleX, tyleY, map->txtrs[6]);
	else
		return (0);
	return (1);
}

void	choose_text(t_map *map, t_recup *r, int tyleX, int tyleY)
{
	if ((choose_big_text(map, r, tyleX, tyleY)))
		return ;
	else if (map->pars[r->x][r->y - 1] == '1')
		draw_walls(map, tyleX, tyleY, map->txtrs[1]);
	else if (map->pars[r->x - 1][r->y] == '1')
		draw_walls(map, tyleX, tyleY, map->txtrs[2]);
	else if (map->pars[r->x + 1][r->y] == '1')
		draw_walls(map, tyleX, tyleY, map->txtrs[10]);
	else if (map->pars[r->x][r->y + 1] == '1')
		draw_walls(map, tyleX, tyleY, map->txtrs[9]);
	else
		draw_walls(map, tyleX, tyleY, map->txtrs[12]);
}
