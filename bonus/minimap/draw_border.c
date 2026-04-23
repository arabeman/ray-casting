/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_border.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:52:54 by arabeman          #+#    #+#             */
/*   Updated: 2025/02/28 16:05:39 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_screen_border(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < ((WIN_HEIGHT + get_integer())))
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			if (j == 0 || j == WIN_WIDTH - 1 || j == 1 || j == WIN_WIDTH - 2)
				ft_put_pixel(data, j, i, BORDER_COLOR);
			if (i == 0 || i == ((WIN_HEIGHT + get_integer())) - 1 || i == 1
				|| i == ((WIN_HEIGHT + get_integer())) - 2)
				ft_put_pixel(data, j, i, BORDER_COLOR);
			j++;
		}
		i++;
	}
}

void	draw_border(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < MINIMAP_H)
	{
		j = 0;
		while (j < MINIMAP_W)
		{
			if (j == 0 || j == MINIMAP_W - 1 || j == 1 || j == MINIMAP_W - 2)
				put_pixel_minimap(data->minimap, i + 16, j + 16, BORDER_COLOR);
			if (i == 0 || i == MINIMAP_H - 1 || i == 1 || i == MINIMAP_H - 2)
				put_pixel_minimap(data->minimap, i + 16, j + 16, BORDER_COLOR);
			j++;
		}
		i++;
	}
	draw_screen_border(data);
}
