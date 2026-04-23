/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_wall_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:27:16 by mrabenja          #+#    #+#             */
/*   Updated: 2025/02/28 16:39:13 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static double	calculate_wall_x(t_ray_data *rd, double ray_dist)
{
	double	wall_x;

	if (rd->side == 0)
		wall_x = rd->ray_y / TILE_SIZE + ray_dist * sin(rd->ray_angle);
	else
		wall_x = rd->ray_x / TILE_SIZE + ray_dist * cos(rd->ray_angle);
	return (wall_x - floor(wall_x / TILE_SIZE) * TILE_SIZE);
}

static void	set_texture_coord(t_texture *wall_txt, t_ray_data *rd,
		double wall_x, int *tex_x)
{
	*tex_x = (int)(wall_x * (double)wall_txt->width) % wall_txt->width;
	(void)rd;
}

static void	draw_texture_line(t_data *data, int col, t_render_param *param,
		t_ray_data *rd)
{
	int		y;
	int		color;
	t_fog	fog;

	fog.max_fog_dist = MAX_FOG;
	y = param->draw_start;
	param->tex_pos = (param->draw_start - ((WIN_HEIGHT + get_integer())) / 2
			+ param->line_height / 2) * param->step;
	while (y < param->draw_end)
	{
		param->tex_y = (int)param->tex_pos % (param->texture->height);
		param->tex_pos += param->step;
		color = get_texture_pxl(param->texture, param->tex_x, param->tex_y);
		color = apply_fog(color, rd->corrected_fisheye, &fog);
		put_pixel(data->framebuff->addr, (y * WIN_WIDTH + col) * 4, color);
		y++;
	}
}

void	render_textured_wall(int col, double ray_dist, t_data *data,
		t_ray_data *rd)
{
	t_render_param	param;
	double			wall_x;
	t_map_config	*cf;

	cf = data->map_config;
	param.line_height = (((WIN_HEIGHT + get_integer()))
			/ rd->corrected_fisheye);
	calculate_wall_bound(rd->corrected_fisheye, &param.draw_start,
		&param.draw_end);
	param.texture = get_wall_txt(data, rd);
	wall_x = calculate_wall_x(rd, ray_dist);
	set_texture_coord(param.texture, rd, wall_x, &param.tex_x);
	param.tex_x = (int)(wall_x * (double)param.texture->width)
		% param.texture->width;
	if (((rd->side == 0 && rd->step_x < 0) || (rd->side == 1 && rd->step_y > 0))
		&& (cf->map[cf->map_y][cf->map_x] != 'D'))
		param.tex_x = param.texture->width - param.tex_x - 1;
	param.step = (double)param.texture->height / param.line_height;
	draw_texture_line(data, col, &param, rd);
}
