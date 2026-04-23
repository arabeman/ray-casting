/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1b_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:10:37 by mrabenja          #+#    #+#             */
/*   Updated: 2025/02/28 16:16:06 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	init_map_cfg_anim(t_map_config *map_cfg)
{
	map_cfg->anim.door_tex = NULL;
	map_cfg->anim.has_door = 0;
	map_cfg->anim.player_tex = NULL;
	map_cfg->anim.num_player_tex = NB_PLAYER_TEX;
}

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
	init_map_cfg_anim(map_cf);
}
