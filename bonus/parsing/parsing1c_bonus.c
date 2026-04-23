/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1c_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:29:59 by mrabenja          #+#    #+#             */
/*   Updated: 2025/02/28 16:16:12 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	handle_door_texture(char **splitted, t_anim_textures *anim)
{
	if (!ft_strcmp(splitted[0], "D") && splitted[1])
	{
		anim->door_tex = ft_strdup(splitted[1]);
		anim->has_door = valid_texture_path(splitted[1]);
	}
}

void	handle_player_textures(char **splitted, t_anim_textures *anim)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	if (!ft_strcmp(splitted[0], "P") && splitted[1])
	{
		anim->player_tex = malloc(sizeof(char *) * 5);
		if (!anim->player_tex)
			return ;
		i = -1;
		while (++i < NB_PLAYER_TEX)
		{
			tmp2 = ft_itoa(i + 1);
			tmp = ft_strjoin(splitted[1], tmp2);
			anim->player_tex[i] = ft_strjoin(tmp, ".xpm");
			free(tmp);
			free(tmp2);
			if (!valid_texture_path(anim->player_tex[i]))
			{
				tab_free(anim->player_tex);
				anim->num_player_tex = 0;
				return ;
			}
		}
	}
}
