/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:20:55 by mrabenja          #+#    #+#             */
/*   Updated: 2025/03/07 10:59:01 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	create_framebuff(t_data *data)
{
	data->framebuff = malloc(sizeof(t_framebuffer));
	if (!data->framebuff)
	{
		ft_putstr_fd("Error\nError allocating framebuffer\n", 2);
		cleanup(data);
		exit(EXIT_FAILURE);
	}
	data->framebuff->img = mlx_new_image(data->mlx, WIN_WIDTH, (WIN_HEIGHT
				+ get_integer()));
	if (!data->framebuff->img)
	{
		ft_putstr_fd("Error\nError creating image\n", 2);
		cleanup(data);
		exit(EXIT_FAILURE);
	}
	data->framebuff->addr = mlx_get_data_addr(data->framebuff->img,
			&data->framebuff->bits_per_pixel, &data->framebuff->line_length,
			&data->framebuff->endian);
}

void	start_win(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, (WIN_HEIGHT
				+ get_integer()), "Cub3D");
	create_framebuff(data);
	load_textures(data);
	set_texture_data(data);
	data->map_config->player_x += TILE_SIZE / 2;
	data->map_config->player_y += TILE_SIZE / 2;
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_hook(data->win, 17, 0, mlx_loop_end, data->mlx);
}

void	cleanup(t_data *data)
{
	free_textures(data);
	if (data->framebuff)
	{
		if (data->framebuff->img)
			mlx_destroy_image(data->mlx, data->framebuff->img);
		free(data->framebuff);
	}
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free_map_config(data->map_config);
}
