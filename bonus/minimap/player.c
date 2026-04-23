/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:39:47 by arabeman          #+#    #+#             */
/*   Updated: 2025/03/02 18:05:08 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

unsigned int	get_pixel_img(t_img img, int x, int y)
{
	return (*(unsigned int *)((img.addr + (y * img.size_line) + (x
				* img.bits_per_pixel / 8))));
}

t_pos	get_rotated_pos(t_data *data, int x, int y)
{
	t_pos	new_pos;
	double	cos_angle;
	double	sin_angle;

	cos_angle = cos(-data->map_config->player_angle - (90 * (M_PI / 180)));
	sin_angle = sin(-data->map_config->player_angle - (90 * (M_PI / 180)));
	new_pos.x = cos_angle * (y - (MINIMAP_TILE / 2)) - sin_angle * (x
			- (MINIMAP_TILE / 2)) + (MINIMAP_TILE / 2);
	new_pos.y = sin_angle * (y - (MINIMAP_TILE / 2)) + cos_angle * (x
			- (MINIMAP_TILE / 2)) + (MINIMAP_TILE / 2);
	return (new_pos);
}

void	render_img_minimap(t_data *data, t_img img, int x, int y)
{
	int		i;
	int		j;
	t_pos	new_pos;

	i = 0;
	while (i < MINIMAP_TILE)
	{
		j = 0;
		while (j < MINIMAP_TILE)
		{
			new_pos = get_rotated_pos(data, j, i);
			if (new_pos.x >= 0 && new_pos.x < MINIMAP_TILE && new_pos.y >= 0
				&& new_pos.y < MINIMAP_TILE && get_pixel_img(img, new_pos.x,
					new_pos.y) != 0xFF000000)
			{
				put_pixel_minimap(data->minimap, x + i, y + j,
					get_pixel_img(img, new_pos.x, new_pos.y));
			}
			j++;
		}
		i++;
	}
}
