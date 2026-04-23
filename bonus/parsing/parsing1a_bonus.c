/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1a_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:46:15 by mrabenja          #+#    #+#             */
/*   Updated: 2025/03/07 10:49:23 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	valid_file_ext(char *file_name)
{
	char	*tmp;

	tmp = ft_strrchr(file_name, '.');
	if (!tmp || ft_strncmp(tmp, ".cub", 4))
		return (0);
	return (1);
}

int	valid_texture_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

static void	handle_texture(char **splitted, t_map_config *config,
		t_counter *counter)
{
	if (!ft_strcmp(splitted[0], "NO") && !config->no_texture)
	{
		config->no_texture = ft_strdup(splitted[1]);
		config->has_no = valid_texture_path(splitted[1]);
		counter->no_number++;
	}
	else if (!ft_strcmp(splitted[0], "SO") && !config->so_texture)
	{
		config->so_texture = ft_strdup(splitted[1]);
		config->has_so = valid_texture_path(splitted[1]);
		counter->so_number++;
	}
	else if (!ft_strcmp(splitted[0], "EA") && !config->ea_texture)
	{
		config->ea_texture = ft_strdup(splitted[1]);
		config->has_ea = valid_texture_path(splitted[1]);
		counter->ea_number++;
	}
	else if (!ft_strcmp(splitted[0], "WE") && !config->we_texture)
	{
		config->we_texture = ft_strdup(splitted[1]);
		config->has_we = valid_texture_path(splitted[1]);
		counter->we_number++;
	}
}

static void	handle_animated_textures(char **splitted, t_map_config *config)
{
	t_anim_textures	*anim;

	anim = &config->anim;
	handle_door_texture(splitted, anim);
	handle_player_textures(splitted, anim);
	ft_putstr_fd("Animated textures loaded successfully\n", 1);
}

int	parse_id_line(char *line, t_map_config *config, t_counter *counter)
{
	char	**splitted;

	splitted = ft_split_wsp(line);
	if (!splitted || !splitted[0] | !splitted[1] || splitted[2])
	{
		tab_free(splitted);
		return (0);
	}
	handle_texture(splitted, config, counter);
	handle_animated_textures(splitted, config);
	if (!ft_strcmp(splitted[0], "F") && splitted[1])
	{
		config->floor_texture = ft_strdup(splitted[1]);
		config->has_floor = valid_texture_path(splitted[1]);
		counter->flo_number++;
	}
	else if (!ft_strcmp(splitted[0], "C") && splitted[1])
	{
		config->ceiling_texture = ft_strdup(splitted[1]);
		config->has_ceiling = valid_texture_path(splitted[1]);
		counter->ceil_number++;
	}
	if (splitted)
		tab_free(splitted);
	return (1);
}
