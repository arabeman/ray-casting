/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2a_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:39:26 by mrabenja          #+#    #+#             */
/*   Updated: 2025/03/07 10:49:37 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	is_pos_closed(char **map_copy, int y, int x)
{
	int	tmp_len[3];

	tmp_len[0] = x;
	if (y == 0)
		tmp_len[1] = -1;
	else
		tmp_len[1] = ft_strlen(map_copy[y - 1]);
	tmp_len[2] = ft_strlen(map_copy[y + 1]);
	if (tmp_len[1] < tmp_len[0])
		return (0);
	if (tmp_len[2] < tmp_len[0])
		return (0);
	if (!map_copy[y - 1] || !map_copy[y - 1][x] || map_copy[y - 1][x] == ' ')
		return (0);
	if (!map_copy[y + 1] || !map_copy[y + 1][x] || map_copy[y + 1][x] == ' ')
		return (0);
	if (!map_copy[y][x - 1] || map_copy[y][x - 1] == ' ')
		return (0);
	if (!map_copy[y][x + 1] || map_copy[y][x + 1] == ' ')
		return (0);
	return (1);
}

static int	count_lines(int fd)
{
	char	*line;
	int		count;

	count = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	return (count);
}

static int	allocate_map(t_map_config *map_cf, int count)
{
	map_cf->map = (char **)malloc((count + 1) * sizeof(char *));
	if (!map_cf->map)
		return (0);
	return (1);
}

static int	read_lines(int fd, t_map_config *map_cf, t_counter *counter)
{
	char	*line;
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strchr("NSWEFCDP", line[0]) && res != 8)
			res += parse_id_line(line, map_cf, counter);
		else if (ft_strlen(line) > 0 && res == 8)
		{
			if (line[ft_strlen(line) - 1] == '\n')
				line[ft_strlen(line) - 1] = '\0';
			map_cf->map[i++] = ft_strdup(line);
		}
		free(line);
	}
	map_cf->map[i] = NULL;
	return (1);
}

int	get_content(int fd, t_map_config *cf, char **av)
{
	int			count;
	int			temp_fd;
	t_counter	counter;

	init_counter(&counter);
	count = count_lines(fd);
	if (!allocate_map(cf, count))
		return (0);
	close(fd);
	temp_fd = open(av[1], O_RDONLY);
	if (temp_fd < 0)
	{
		free_map_config(cf);
		return (0);
	}
	if (!read_lines(temp_fd, cf, &counter))
	{
		free_map_config(cf);
		close(temp_fd);
		return (0);
	}
	close(temp_fd);
	return (1);
}
