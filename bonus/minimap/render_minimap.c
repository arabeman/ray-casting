/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:07:39 by arabeman          #+#    #+#             */
/*   Updated: 2025/03/02 18:05:08 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	put_pixel_minimap(t_minimap *minimap, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= MINIMAP_W || y >= MINIMAP_H)
		return ;
	dst = minimap->minimap_img.addr + (y * minimap->minimap_img.size_line + x
			* (minimap->minimap_img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= ((WIN_HEIGHT + get_integer())))
		return ;
	dst = data->framebuff->addr + (y * data->framebuff->line_length + x
			* (data->framebuff->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	render_minimap_img(t_data *data, t_minimap *minimap)
{
	t_texture	tmp;
	int			i;
	int			j;

	i = 16;
	while (i < MINIMAP_H + 16)
	{
		j = 16;
		while (j < MINIMAP_W + 16)
		{
			tmp.img = minimap->minimap_img.img;
			tmp.addr = minimap->minimap_img.addr;
			tmp.endian = minimap->minimap_img.endian;
			tmp.line_length = minimap->minimap_img.size_line;
			tmp.bits_per_pixel = minimap->minimap_img.bits_per_pixel;
			tmp.width = MINIMAP_W;
			tmp.height = MINIMAP_H;
			put_pixel(data->framebuff->addr, (i * WIN_WIDTH + j) * 4,
				get_texture_pxl(&tmp, j, i));
			j++;
		}
		i++;
	}
}

int	render_minimap(t_data *data)
{
	t_minimap	*minimap;
	int			i;
	int			j;

	minimap = data->minimap;
	i = 0;
	while (i < MINIMAP_H)
	{
		j = 0;
		while (j < MINIMAP_W)
		{
			put_pixel_minimap(data->minimap, i, j, 0x000000);
			j++;
		}
		i++;
	}
	render_img_minimap(data, minimap->player_img, PLAYER_POS + 16, PLAYER_POS
		+ 16);
	render_wall_minimap(data, minimap->x + 16, minimap->y + 16);
	draw_border(data);
	render_minimap_img(data, minimap);
	return (0);
}
