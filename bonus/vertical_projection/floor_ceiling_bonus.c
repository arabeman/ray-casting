/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:46:00 by mrabenja          #+#    #+#             */
/*   Updated: 2025/03/02 18:12:38 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	init_ray_direct(t_floor_ceiling *fc, t_ray_data *rd)
{
	fc->ray_dir_x = cos(rd->ray_angle);
	fc->ray_dir_y = sin(rd->ray_angle);
}

static void	set_floor_pos(t_floor_ceiling *fc, t_data *data, int y,
		t_ray_data *rd)
{
	fc->camera_y = y - ((WIN_HEIGHT + get_integer())) / 2.0;
	fc->current_dist = ((((WIN_HEIGHT + get_integer())) / 2.0) / fc->camera_y)
		/ cos((rd->ray_angle - data->map_config->player_angle));
	fc->current_floor_x = data->map_config->player_x / TILE_SIZE
		+ fc->current_dist * fc->ray_dir_x;
	fc->current_floor_y = data->map_config->player_y / TILE_SIZE
		+ fc->current_dist * fc->ray_dir_y;
}

// change size when using another img size
static void	get_texture_coord(int *tex_x, int *tex_y, t_floor_ceiling *fc)
{
	int	size;

	size = 2;
	*tex_x = (int)(fc->current_floor_x * TILE_SIZE) % TILE_SIZE * size;
	*tex_y = (int)(fc->current_floor_y * TILE_SIZE) % TILE_SIZE * size;
}

static void	draw_floor_ceiling_pxl(t_data *data, int x, int y,
		t_floor_ceiling *fc)
{
	t_pos_int	tex;
	int			floor_color;
	int			ceiling_color;
	int			ceiling_y;
	t_fog		fog;

	get_texture_coord(&tex.x, &tex.y, fc);
	fog.max_fog_dist = MAX_FOG;
	floor_color = get_texture_pxl(&data->textures[_floor], tex.x, tex.y);
	floor_color = apply_fog(floor_color, fc->current_dist, &fog);
	put_pixel(data->framebuff->addr, (y * WIN_WIDTH + x) * 4, floor_color);
	ceiling_y = ((WIN_HEIGHT + get_integer())) - y - 1;
	ceiling_color = get_texture_pxl(&data->textures[ceiling], tex.x, tex.y);
	ceiling_color = apply_fog(ceiling_color, fc->current_dist, &fog);
	put_pixel(data->framebuff->addr, (ceiling_y * WIN_WIDTH + x) * 4,
		ceiling_color);
}

void	render_floor_ceiling(t_data *data, int x, t_ray_data *rd)
{
	t_floor_ceiling	fc;
	int				y;

	init_ray_direct(&fc, rd);
	if (rd->corrected_fisheye < 1.0)
		return ;
	y = ((WIN_HEIGHT + get_integer())) / 2 + 1;
	while (y < ((WIN_HEIGHT + get_integer())))
	{
		set_floor_pos(&fc, data, y, rd);
		draw_floor_ceiling_pxl(data, x, y, &fc);
		y++;
	}
}
