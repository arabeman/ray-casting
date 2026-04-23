/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:10:37 by mrabenja          #+#    #+#             */
/*   Updated: 2025/03/04 10:58:27 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_map_config(t_map_config *map_cf)
{
	map_cf->no_texture = NULL;
	map_cf->so_texture = NULL;
	map_cf->we_texture = NULL;
	map_cf->ea_texture = NULL;
	map_cf->floor_c.r = -1;
	map_cf->floor_c.g = -1;
	map_cf->floor_c.b = -1;
	map_cf->ceiling_c.r = -1;
	map_cf->ceiling_c.g = -1;
	map_cf->ceiling_c.b = -1;
	map_cf->map = NULL;
	map_cf->height = 0;
	map_cf->width = 0;
	map_cf->player_x = -1;
	map_cf->player_y = -1;
	map_cf->player_dir = 0;
	map_cf->has_no = 0;
	map_cf->has_so = 0;
	map_cf->has_we = 0;
	map_cf->has_ea = 0;
	map_cf->has_floor = 0;
	map_cf->has_ceiling = 0;
	map_cf->map_x = 0;
	map_cf->map_y = 0;
}

void	free_map_config(t_map_config *config)
{
	if (config->no_texture)
		free(config->no_texture);
	if (config->so_texture)
		free(config->so_texture);
	if (config->ea_texture)
		free(config->ea_texture);
	if (config->we_texture)
		free(config->we_texture);
	if (config->map)
		tab_free(config->map);
}
