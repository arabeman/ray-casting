/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:20:55 by mrabenja          #+#    #+#             */
/*   Updated: 2025/03/07 09:08:05 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	create_framebuff(t_data *m)
{
	m->framebuff = malloc(sizeof(t_framebuffer));
	if (!m->framebuff)
	{
		ft_putstr_fd("Error\nError allocating framebuffer\n", 2);
		cleanup(m);
		exit(EXIT_FAILURE);
	}
	m->framebuff->img = mlx_new_image(m->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!m->framebuff->img)
	{
		ft_putstr_fd("Error\nError creating image\n", 2);
		cleanup(m);
		exit(EXIT_FAILURE);
	}
	m->framebuff->addr = mlx_get_data_addr(m->framebuff->img,
			&m->framebuff->bits_per_pixel, &m->framebuff->line_length,
			&m->framebuff->endian);
}

void	start_win(t_data *m)
{
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	create_framebuff(m);
	load_textures(m);
	load_door_textures(m);
	load_player_textures(m);
	m->is_firing = false;
	m->fire_frame = 0;
	init_minimap(m);
	init_viewmodel(m);
	set_texture_data(m);
	set_data(m);
	m->map_config->player_x += TILE_SIZE / 2;
	m->map_config->player_y += TILE_SIZE / 2;
	mlx_mouse_move(m->mlx, m->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	mlx_hook(m->win, 6, 1L << 6, handle_mouse, m);
	mlx_hook(m->win, 2, 1L << 0, key_press, m);
	mlx_hook(m->win, 3, 1L << 1, key_release, m);
	mlx_hook(m->win, 17, 0, mlx_loop_end, m->mlx);
}

void	cleanup(t_data *data)
{
	free_textures(data);
	if (data->enable_minimap)
	{
		mlx_destroy_image(data->mlx, data->minimap->minimap_img.img);
		mlx_destroy_image(data->mlx, data->minimap->player_img.img);
		free(data->minimap);
	}
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
