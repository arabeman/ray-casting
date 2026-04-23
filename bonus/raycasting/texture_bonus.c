/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:00:22 by mrabenja          #+#    #+#             */
/*   Updated: 2025/03/03 17:18:25 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	load_textures(t_data *data)
{
	t_texture		*txt;
	t_map_config	*cfg;

	txt = data->textures;
	cfg = data->map_config;
	txt[north].img = mlx_xpm_file_to_image(data->mlx, cfg->no_texture,
			&txt[north].width, &txt[north].height);
	txt[south].img = mlx_xpm_file_to_image(data->mlx, cfg->so_texture,
			&txt[south].width, &txt[south].height);
	txt[east].img = mlx_xpm_file_to_image(data->mlx, cfg->ea_texture,
			&txt[east].width, &txt[east].height);
	txt[west].img = mlx_xpm_file_to_image(data->mlx, cfg->we_texture,
			&txt[west].width, &txt[west].height);
	txt[_floor].img = mlx_xpm_file_to_image(data->mlx, cfg->floor_texture,
			&txt[_floor].width, &txt[_floor].height);
	txt[ceiling].img = mlx_xpm_file_to_image(data->mlx, cfg->ceiling_texture,
			&txt[ceiling].width, &txt[ceiling].height);
	if (!data->textures[north].img || !data->textures[south].img
		|| !data->textures[east].img || !data->textures[west].img
		|| !data->textures[_floor].img || !data->textures[ceiling].img)
	{
		cleanup(data);
		exit(EXIT_FAILURE);
	}
	ft_putstr_fd("Textures loaded successfully\n", 1);
}

void	set_texture_data(t_data *data)
{
	t_texture	*txt;
	int			i;

	i = -1;
	txt = data->textures;
	while (++i < 6)
		txt[i].addr = mlx_get_data_addr(txt[i].img, &txt[i].bits_per_pixel,
				&txt[i].line_length, &txt[i].endian);
}

void	free_textures(t_data *data)
{
	t_texture	*txt;
	int			i;

	i = -1;
	txt = data->textures;
	while (++i < 7)
	{
		if (txt[i].img)
		{
			mlx_destroy_image(data->mlx, txt[i].img);
			txt[i].img = NULL;
		}
	}
	i = -1;
	while (++i < data->map_config->anim.num_player_tex)
	{
		if (data->player_tex[i].img)
		{
			mlx_destroy_image(data->mlx, data->player_tex[i].img);
			data->player_tex[i].img = NULL;
		}
	}
	free_torch(data);
}

t_texture	*get_wall_txt(t_data *data, t_ray_data *rd)
{
	if (
		data->map_config->map[data->map_config->map_y][data->map_config->map_x]
		== 'D')
		return (&data->textures[door]);
	else if (rd->side == 0)
	{
		if (rd->step_x > 0)
			return (&data->textures[west]);
		else
			return (&data->textures[east]);
	}
	else
	{
		if (rd->step_y > 0)
			return (&data->textures[north]);
		else
			return (&data->textures[south]);
	}
}

int	get_texture_pxl(t_texture *txt, int x, int y)
{
	char	*res;

	if (x < 0 || y < 0 || x >= txt->width || y >= txt->height)
		return (0x000000);
	res = txt->addr + (y * txt->line_length + x * (txt->bits_per_pixel / 8));
	return (*(unsigned int *)res);
}
