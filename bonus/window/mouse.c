/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:03:23 by arabeman          #+#    #+#             */
/*   Updated: 2025/03/02 18:14:12 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	handle_mouse(int x, int y, t_data *data)
{
	float	delta_x;

	if (x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT || data->key.alt)
	{
		mlx_mouse_show(data->mlx, data->win);
		return (1);
	}
	mlx_mouse_hide(data->mlx, data->win);
	delta_x = x - (WIN_WIDTH / 2);
	data->map_config->player_angle += delta_x * 0.001f;
	return (0);
}
