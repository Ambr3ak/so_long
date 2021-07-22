/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:40:48 by abourdar          #+#    #+#             */
/*   Updated: 2021/07/20 11:40:52 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	get_sprite_color(t_img *txtrs, int x, int y, int tile_size)
{
	int	txt_x;
	int	txt_y;
	int	color;
	int	*int_addr;

	int_addr = (int *)txtrs->addr;
	txt_x = 0;
	txt_y = 0;
	txt_x = txtrs->x / (32 / (((double)x / tile_size) * 32.0));
	txt_y = txtrs->y / (32 / (((double)y / tile_size) * 32.0));
	color = int_addr[txtrs->x * txt_y + txt_x];
	return (color);
}

int	pixel_get_color(t_img *txtrs, int x, int y)
{
	int	color;
	int	*int_addr;

	int_addr = (int *)txtrs->addr;
	color = int_addr[y * txtrs->x + x];
	return (color);
}
