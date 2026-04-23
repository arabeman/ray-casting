/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_config_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:52:12 by arabeman          #+#    #+#             */
/*   Updated: 2025/03/04 13:49:10 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	free_player_textures(t_map_config *config)
{
	int	i;

	i = 0;
	while (i < NB_PLAYER_TEX)
	{
		if (config->anim.player_tex[i])
			free(config->anim.player_tex[i]);
		i++;
	}
	if (config->anim.player_tex)
		free(config->anim.player_tex);
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
	if (config->floor_texture)
		free(config->floor_texture);
	if (config->ceiling_texture)
		free(config->ceiling_texture);
	if (config->anim.door_tex)
		free(config->anim.door_tex);
	if (config->anim.player_tex)
		free_player_textures(config);
	if (config->map)
		tab_free(config->map);
}
