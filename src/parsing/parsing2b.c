/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:12:38 by mrabenja          #+#    #+#             */
/*   Updated: 2025/03/07 10:46:43 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	check_position(char **map, int *data, t_map_config *map_cfg)
{
	if (!is_pos_closed(map, data[1], data[0]))
	{
		ft_putstr_fd("Error\nMap not closed\n", 2);
		return (0);
	}
	if (ft_strchr("NSEW", map[data[1]][data[0]]))
	{
		if (data[2])
			return (0);
		data[2] = 1;
		map_cfg->map_y = data[1];
		map_cfg->map_x = data[0];
		map_cfg->player_y = data[1] * TILE_SIZE;
		map_cfg->player_x = data[0] * TILE_SIZE;
		map_cfg->player_dir = map[data[1]][data[0]];
	}
	return (1);
}

static int	validate_map_line(char **map, int *data, t_map_config *map_cfg)
{
	while (map[data[1]][data[0]])
	{
		if (map[data[1]][data[0]] == '0' || ft_strchr("NSEW",
				map[data[1]][data[0]]))
		{
			if (!check_position(map, data, map_cfg))
				return (0);
		}
		else if (map[data[1]][data[0]] != '1' && map[data[1]][data[0]] != ' ')
			return (0);
		data[0]++;
	}
	return (1);
}

static int	valid_map(t_map_config *map_cfg)
{
	char	**map;
	int		data[3];

	map = map_cfg->map;
	data[1] = 0;
	data[2] = 0;
	while (map[data[1]])
	{
		data[0] = 0;
		if (!validate_map_line(map, data, map_cfg))
			return (0);
		data[1]++;
	}
	return (data[2]);
}

static int	parsing(int fd, char **av, t_map_config *cf)
{
	if (fd < 0)
	{
		free_map_config(cf);
		return (ft_putstr_fd("Error\nInvalid file\n", 2), 1);
	}
	if (!get_content(fd, cf, av))
	{
		free_map_config(cf);
		return (ft_putstr_fd("Error\nInvalid file\n", 2), 1);
	}
	if (!valid_map(cf))
	{
		free_map_config(cf);
		return (ft_putstr_fd("Error\nInvalid map config\n", 2), 1);
	}
	if (!cf->has_no || !cf->has_so || !cf->has_we || !cf->has_ea
		|| !cf->has_floor || !cf->has_ceiling)
	{
		free_map_config(cf);
		return (ft_putstr_fd("Error\nConfig error\n", 2), 1);
	}
	return (0);
}

int	handle_error_input(int ac, char **av, t_map_config *cf)
{
	int	fd;
	int	res;

	res = 0;
	if (ac != 2)
		return (ft_putendl_fd("Usage: ./cub3D path_to_map\n", 2), 1);
	if (!valid_file_ext(av[1]))
		ft_putstr_fd("Error\nInvalid file extension\n", 2);
	init_map_config(cf);
	fd = open(av[1], O_RDONLY);
	res = parsing(fd, av, cf);
	set_player_angle(cf);
	return (res);
}
