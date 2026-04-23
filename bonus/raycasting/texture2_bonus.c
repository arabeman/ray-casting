/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:43:31 by mrabenja          #+#    #+#             */
/*   Updated: 2025/03/02 18:05:08 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	free_torch(t_data *data)
{
	mlx_destroy_image(data->mlx, data->torch[0].img);
	mlx_destroy_image(data->mlx, data->torch[1].img);
	mlx_destroy_image(data->mlx, data->torch[2].img);
	mlx_destroy_image(data->mlx, data->torch[3].img);
	mlx_destroy_image(data->mlx, data->torch[4].img);
}

void	load_door_textures(t_data *data)
{
	t_texture		*txt;
	t_map_config	*cfg;

	txt = data->textures;
	cfg = data->map_config;
	txt[door].img = mlx_xpm_file_to_image(data->mlx, cfg->anim.door_tex,
			&txt[door].width, &txt[door].height);
	if (!data->textures[door].img)
	{
		ft_putstr_fd("Error\nDoor texture not found\n", 2);
		cleanup(data);
		exit(EXIT_FAILURE);
	}
	txt[door].addr = mlx_get_data_addr(txt[door].img, &txt[door].bits_per_pixel,
			&txt[door].line_length, &txt[door].endian);
}

void	load_player_textures(t_data *data)
{
	t_texture		*txt;
	t_map_config	*cfg;
	int				i;

	txt = data->player_tex;
	cfg = data->map_config;
	i = 0;
	while (i < cfg->anim.num_player_tex)
	{
		txt[i].img = mlx_xpm_file_to_image(data->mlx, cfg->anim.player_tex[i],
				&txt[i].width, &txt[i].height);
		if (!txt[i].img)
		{
			ft_putstr_fd("Error\nPlayer texture not found\n", 2);
			cleanup(data);
			exit(EXIT_FAILURE);
		}
		txt[i].addr = mlx_get_data_addr(txt[i].img, &txt[i].bits_per_pixel,
				&txt[i].line_length, &txt[i].endian);
		i++;
	}
}
