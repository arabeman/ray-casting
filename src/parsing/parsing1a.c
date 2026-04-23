/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:46:15 by mrabenja          #+#    #+#             */
/*   Updated: 2025/03/07 11:02:00 by mrabenja         ###   ########.fr       */
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

int	parse_rgb_color(char *str, t_color *color)
{
	char	**splitted;
	int		i;

	i = 0;
	if (!str_is_valid(str))
		return (0);
	splitted = ft_split(str, ',');
	if (!splitted[0] || !splitted[1] || !splitted[2])
	{
		tab_free(splitted);
		return (0);
	}
	color->r = ft_atoi(splitted[i++]);
	color->g = ft_atoi(splitted[i++]);
	color->b = ft_atoi(splitted[i++]);
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
	{
		tab_free(splitted);
		return (0);
	}
	tab_free(splitted);
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

int	parse_id_line(char *line, t_map_config *config, t_counter *counter)
{
	char	**splitted;

	splitted = ft_split_wsp(line);
	if (!splitted || !splitted[0] || !splitted[1] || splitted[2])
	{
		tab_free(splitted);
		return (0);
	}
	if (splitted[1])
		handle_texture(splitted, config, counter);
	if (!ft_strcmp(splitted[0], "F") && splitted[1])
	{
		config->has_floor = parse_rgb_color(splitted[1], &config->floor_c);
		counter->flo_number++;
	}
	else if (!ft_strcmp(splitted[0], "C") && splitted[1])
	{
		config->has_ceiling = parse_rgb_color(splitted[1], &config->ceiling_c);
		counter->ceil_number++;
	}
	if (splitted)
		tab_free(splitted);
	return (1);
}
