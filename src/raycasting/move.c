/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:34:03 by mrabenja          #+#    #+#             */
/*   Updated: 2025/02/28 12:35:15 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	_handle_forward(t_data *data, float speed);
static void	_handle_backward(t_data *data, float speed);
static void	_handle_left(t_data *data, float speed);
static void	_handle_right(t_data *data, float speed);

void	move_player(t_data *data)
{
	float	speed;

	speed = MOVE_SPEED / 4;
	if ((data->key.forward && (data->key.right || data->key.left))
		|| (data->key.backward && (data->key.right || data->key.left)))
		speed = DIAGONAL_SPEED / 4;
	_handle_forward(data, speed);
	_handle_backward(data, speed);
	_handle_left(data, speed);
	_handle_right(data, speed);
	if (data->key.turn_left)
		data->map_config->player_angle -= ROTA_SPEED / 4;
	if (data->key.turn_right)
		data->map_config->player_angle += ROTA_SPEED / 4;
	reset_angle(&data->map_config->player_angle);
}

static void	_handle_forward(t_data *data, float speed)
{
	double	x;
	double	y;
	double	cos_angle;
	double	sin_angle;

	cos_angle = cos(data->map_config->player_angle);
	sin_angle = sin(data->map_config->player_angle);
	if (data->key.forward)
	{
		x = data->map_config->player_x + cos_angle * speed;
		y = data->map_config->player_y + sin_angle * speed;
		if (!has_wall_near(data, x, y))
		{
			data->map_config->player_x = x;
			data->map_config->player_y = y;
		}
	}
}

static void	_handle_backward(t_data *data, float speed)
{
	double	x;
	double	y;
	double	cos_angle;
	double	sin_angle;

	cos_angle = cos(data->map_config->player_angle);
	sin_angle = sin(data->map_config->player_angle);
	if (data->key.backward)
	{
		x = data->map_config->player_x - cos_angle * speed;
		y = data->map_config->player_y - sin_angle * speed;
		if (!has_wall_near(data, x, y))
		{
			data->map_config->player_x = x;
			data->map_config->player_y = y;
		}
	}
}

static void	_handle_left(t_data *data, float speed)
{
	double	x;
	double	y;
	double	cos_angle;
	double	sin_angle;

	cos_angle = cos(data->map_config->player_angle);
	sin_angle = sin(data->map_config->player_angle);
	if (data->key.left)
	{
		x = data->map_config->player_x + sin_angle * speed;
		y = data->map_config->player_y - cos_angle * speed;
		if (!has_wall_near(data, x, y))
		{
			data->map_config->player_x = x;
			data->map_config->player_y = y;
		}
	}
}

static void	_handle_right(t_data *data, float speed)
{
	double	x;
	double	y;
	double	cos_angle;
	double	sin_angle;

	cos_angle = cos(data->map_config->player_angle);
	sin_angle = sin(data->map_config->player_angle);
	if (data->key.right)
	{
		x = data->map_config->player_x - sin_angle * speed;
		y = data->map_config->player_y + cos_angle * speed;
		if (!has_wall_near(data, x, y))
		{
			data->map_config->player_x = x;
			data->map_config->player_y = y;
		}
	}
}
