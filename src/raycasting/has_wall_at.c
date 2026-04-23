/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_wall_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:30:53 by arabeman          #+#    #+#             */
/*   Updated: 2025/03/02 18:24:47 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

bool	has_wall_at(t_data *data, int x, int y)
{
	char	**map;
	char	c;

	map = data->map_config->map;
	c = map[(int)floor(y / TILE_SIZE)][(int)floor(x / TILE_SIZE)];
	if (c == '1' || c == 'D')
		return (true);
	return (false);
}

bool	has_wall_near(t_data *data, int x, int y)
{
	int	radius;

	radius = 3;
	return (has_wall_at(data, x, y) || has_wall_at(data, x - radius, y - radius)
		|| has_wall_at(data, x + radius, y - radius) || has_wall_at(data, x
			- radius, y + radius) || has_wall_at(data, x + radius, y + radius));
}
