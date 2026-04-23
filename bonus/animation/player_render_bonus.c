/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_render_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:38:04 by mrabenja          #+#    #+#             */
/*   Updated: 2025/02/28 15:38:10 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	get_current_player_tex(t_data *data)
{
	if (!data->is_firing)
		return (0);
	return ((data->fire_frame / 5) % (data->map_config->anim.num_player_tex));
}

static void	put_player_pixel(t_data *data, t_texture *tex, int x, int y)
{
	int	color;
	int	screen_x;
	int	screen_y;
	int	i;
	int	j;

	color = get_texture_pxl(tex, x, y);
	if ((color >> 24) != 0)
		return ;
	i = 0;
	while (i < SCALE_FACTOR)
	{
		j = 0;
		while (j < SCALE_FACTOR)
		{
			screen_x = (WIN_WIDTH - tex->width * SCALE_FACTOR) / 2 + x
				* SCALE_FACTOR + i;
			screen_y = (((WIN_HEIGHT + get_integer())) - tex->height
					* SCALE_FACTOR) + y * SCALE_FACTOR + j;
			put_pixel(data->framebuff->addr, (screen_y * WIN_WIDTH + screen_x)
				* 4, color);
			j++;
		}
		i++;
	}
}

void	handle_player_animation(t_data *data)
{
	if (data->key.fire && !data->is_firing)
	{
		data->is_firing = true;
		data->fire_frame = 1;
	}
	if (data->is_firing)
	{
		data->fire_frame++;
		if (data->fire_frame >= 20)
		{
			data->fire_frame = 0;
			data->is_firing = false;
		}
	}
}

void	render_player_weapon(t_data *data)
{
	t_texture	*tex;
	int			x;
	int			y;
	int			tex_idx;

	tex_idx = get_current_player_tex(data);
	tex = &data->player_tex[tex_idx];
	x = -1;
	while (++x < tex->width)
	{
		y = -1;
		while (++y < tex->height)
			put_player_pixel(data, tex, x, y);
	}
}
