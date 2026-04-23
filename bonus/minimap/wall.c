/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:28:45 by arabeman          #+#    #+#             */
/*   Updated: 2025/02/28 16:15:25 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	_get_wall_x(int player_x, int wall_x)
{
	return ((PLAYER_POS + (wall_x - player_x) * 32));
}

int	_get_wall_y(int player_y, int wall_y)
{
	return ((PLAYER_POS + (wall_y - player_y) * 32));
}

void	draw_square(t_minimap *minimap, int x, int y)
{
	int	i;
	int	j;

	i = 1;
	while (i < MINIMAP_TILE - 1)
	{
		j = 1;
		while (j < MINIMAP_TILE - 1)
		{
			put_pixel_minimap(minimap, i + x, j + y, MINIMAP_COLOR);
			j++;
		}
		i++;
	}
}

void	draw_door_minimap(t_minimap *minimap, int x, int y)
{
	int	i;
	int	j;

	i = 6;
	while (i < MINIMAP_TILE - 6)
	{
		j = 6;
		while (j < MINIMAP_TILE - 6)
		{
			put_pixel_minimap(minimap, i + x, j + y, 0x929163);
			j++;
		}
		i++;
	}
}

void	render_wall_minimap(t_data *data, int x, int y)
{
	char		**map;
	t_pos		p_i;
	t_pos_int	i;

	map = data->map_config->map;
	p_i.x = data->player_start_index[0];
	p_i.y = data->player_start_index[1];
	i.x = 0;
	i.y = 0;
	while (i.x < tab_length(map))
	{
		i.y = 0;
		while (i.y < (int)ft_strlen(map[i.x]))
		{
			if (map[i.x][i.y] == '1')
				draw_square(data->minimap, _get_wall_y(p_i.y, i.y) + y,
					_get_wall_x(p_i.x, i.x) + x);
			if (map[i.x][i.y] == 'D')
				draw_door_minimap(data->minimap, _get_wall_y(p_i.y, i.y) + y,
					_get_wall_x(p_i.x, i.x) + x);
			i.y++;
		}
		i.x++;
	}
}
