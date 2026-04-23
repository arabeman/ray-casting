/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:07:08 by mrabenja          #+#    #+#             */
/*   Updated: 2025/02/28 15:37:15 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

bool	is_closed_door_neaby(t_data *data)
{
	double	dst;
	double	x;
	double	y;
	int		map_x;
	int		map_y;

	dst = TILE_SIZE * DOOR_RATIO;
	x = data->map_config->player_x + cos(data->map_config->player_angle) * dst;
	y = data->map_config->player_y + sin(data->map_config->player_angle) * dst;
	map_x = (int)(x / TILE_SIZE);
	map_y = (int)(y / TILE_SIZE);
	if (data->map_config->map[map_y][map_x]
		&& data->map_config->map[map_y][map_x] == 'D')
		return (true);
	return (false);
}

bool	is_open_door_neaby(t_data *data)
{
	double	dst;
	double	x;
	double	y;
	int		map_x;
	int		map_y;

	dst = TILE_SIZE * DOOR_RATIO;
	x = data->map_config->player_x + cos(data->map_config->player_angle) * dst;
	y = data->map_config->player_y + sin(data->map_config->player_angle) * dst;
	map_x = (int)(x / TILE_SIZE);
	map_y = (int)(y / TILE_SIZE);
	if (data->map_config->map[map_y][map_x]
		&& data->map_config->map[map_y][map_x] == '2')
		return (true);
	return (false);
}

void	handle_door(t_data *data)
{
	int		map_x;
	int		map_y;
	double	dst;
	double	x;
	double	y;

	dst = TILE_SIZE * DOOR_RATIO;
	x = data->map_config->player_x + cos(data->map_config->player_angle) * dst;
	y = data->map_config->player_y + sin(data->map_config->player_angle) * dst;
	map_x = (int)(x / TILE_SIZE);
	map_y = (int)(y / TILE_SIZE);
	if (is_closed_door_neaby(data) && data->key.open_door)
		data->map_config->map[map_y][map_x] = '2';
	else if (is_open_door_neaby(data) && data->key.close_door)
		data->map_config->map[map_y][map_x] = 'D';
}
