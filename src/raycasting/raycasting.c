/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:48:55 by mrabenja          #+#    #+#             */
/*   Updated: 2025/03/02 18:29:54 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_ray_data(t_ray_data *rd)
{
	rd->ray_x = 0.0;
	rd->ray_y = 0.0;
	rd->delta_x = 0.0;
	rd->delta_y = 0.0;
	rd->step_x = 0;
	rd->step_y = 0;
	rd->side_dist_x = 0.0;
	rd->side_dist_y = 0.0;
	rd->hit = 0;
	rd->side = 0;
	rd->ray_angle = 0.0;
}

static void	set_step(int *step_x, int *step_y, double ray_angle)
{
	if (cos(ray_angle) >= 0)
		*step_x = 1;
	else
		*step_x = -1;
	if (sin(ray_angle) >= 0)
		*step_y = 1;
	else
		*step_y = -1;
}

static void	set_dist(t_ray_data *rd, t_map_config *cf)
{
	if (rd->step_x > 0)
		rd->side_dist_x = (cf->map_x + 1 - rd->ray_x / TILE_SIZE) * rd->delta_x;
	else
		rd->side_dist_x = (rd->ray_x / TILE_SIZE - cf->map_x) * rd->delta_x;
	if (rd->step_y > 0)
		rd->side_dist_y = (cf->map_y + 1 - rd->ray_y / TILE_SIZE) * rd->delta_y;
	else
		rd->side_dist_y = (rd->ray_y / TILE_SIZE - cf->map_y) * rd->delta_y;
}

// set side correctly (walls are colored distinctly)
static void	ray_loop(t_ray_data *rd, t_map_config *cf)
{
	while (!rd->hit)
	{
		if (rd->side_dist_x < rd->side_dist_y)
		{
			rd->side_dist_x += rd->delta_x;
			cf->map_x += rd->step_x;
			rd->side = 0;
		}
		else
		{
			rd->side_dist_y += rd->delta_y;
			cf->map_y += rd->step_y;
			rd->side = 1;
		}
		if (cf->map[cf->map_y] && cf->map[cf->map_y][cf->map_x]
			&& cf->map[cf->map_y][cf->map_x] == '1')
			rd->hit = 1;
	}
}

int	cast_ray2(t_map_config *cf, int col, double *ray_dst, t_ray_data *rd)
{
	init_ray_data(rd);
	rd->ray_angle = cf->player_angle + ((col - WIN_WIDTH / 2.0) / WIN_WIDTH)
		* FOV_ANGLE;
	reset_angle(&rd->ray_angle);
	rd->ray_x = cf->player_x;
	rd->ray_y = cf->player_y;
	rd->delta_x = fabs(1 / (cos(rd->ray_angle)));
	rd->delta_y = fabs(1 / (sin(rd->ray_angle)));
	cf->map_x = (int)(rd->ray_x / TILE_SIZE);
	cf->map_y = (int)(rd->ray_y / TILE_SIZE);
	set_step(&rd->step_x, &rd->step_y, rd->ray_angle);
	set_dist(rd, cf);
	ray_loop(rd, cf);
	if (rd->side == 0)
		*ray_dst = (rd->side_dist_x - rd->delta_x);
	else
		*ray_dst = (rd->side_dist_y - rd->delta_y);
	rd->corrected_fisheye = *ray_dst * cos((rd->ray_angle - cf->player_angle));
	return (rd->side);
}
