/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:23:07 by arabeman          #+#    #+#             */
/*   Updated: 2025/03/03 17:17:45 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

void		init_key(t_data *data);

static int	gameloop(t_data *data)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
	move_player_bonus(data);
	render_frame(data);
	handle_door(data);
	render_viewmodel(data);
	usleep(16667);
	if (!data->key.alt && !(x < 0 || x > WIN_WIDTH || y < 0 || y > WIN_HEIGHT))
		mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}

void	init_key(t_data *data)
{
	data->key.forward = false;
	data->key.backward = false;
	data->key.left = false;
	data->key.right = false;
	data->key.turn_left = false;
	data->key.turn_right = false;
	data->key.open_door = false;
	data->key.close_door = false;
	data->key.alt = false;
	data->key.fire = false;
}

int	main(int ac, char **av)
{
	t_data			data;
	t_map_config	cf;

	if (handle_error_input(ac, av, &cf))
		return (1);
	data.map_config = &cf;
	data.enable_minimap = true;
	init_key(&data);
	ft_putstr_fd("Configuration file parsed successfully!\n", 1);
	start_win(&data);
	mlx_loop_hook(data.mlx, gameloop, &data);
	mlx_loop(data.mlx);
	cleanup(&data);
	return (0);
}
