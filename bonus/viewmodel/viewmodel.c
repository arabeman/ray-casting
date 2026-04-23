/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewmodel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:00:18 by arabeman          #+#    #+#             */
/*   Updated: 2025/03/02 18:08:52 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_torch(t_data *data, t_img *torch, char *path)
{
	int	_;

	torch->img = mlx_xpm_file_to_image(data->mlx, path, &_, &_);
	torch->addr = mlx_get_data_addr(torch->img, &torch->bits_per_pixel,
			&torch->size_line, &torch->endian);
}

void	init_viewmodel(t_data *data)
{
	t_img	torch[5];
	int		i;

	init_torch(data, &torch[0], "texture/mine/greenflame/greenflame_0.xpm");
	init_torch(data, &torch[1], "texture/mine/greenflame/greenflame_1.xpm");
	init_torch(data, &torch[2], "texture/mine/greenflame/greenflame_2.xpm");
	init_torch(data, &torch[3], "texture/mine/greenflame/greenflame_3.xpm");
	init_torch(data, &torch[4], "texture/mine/greenflame/greenflame_4.xpm");
	i = -1;
	while (++i < 5)
		data->torch[i] = torch[i];
}

static void	render_img(t_data *data, t_img img, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < 640)
	{
		j = 0;
		while (j < 320)
		{
			if (get_pixel_img(img, j, i) != 0xFF000000)
				ft_put_pixel(data, x + j, y + i, get_pixel_img(img, j, i));
			j++;
		}
		i++;
	}
}

void	render_viewmodel(t_data *data)
{
	struct timeval	tv;
	int				x;
	int				y;

	x = (WIN_WIDTH + get_integer()) - 384;
	y = (WIN_HEIGHT + get_integer() * 0.8f) - 384;
	gettimeofday(&tv, NULL);
	if (tv.tv_usec % 400000 < 20 * 4000)
		render_img(data, data->torch[0], x, y);
	else if (tv.tv_usec % 400000 < 40 * 4000)
		render_img(data, data->torch[1], x, y);
	else if (tv.tv_usec % 400000 < 60 * 4000)
		render_img(data, data->torch[2], x, y);
	else if (tv.tv_usec % 400000 < 80 * 4000)
		render_img(data, data->torch[3], x, y);
	else if (tv.tv_usec % 400000 < 100 * 4000)
		render_img(data, data->torch[4], x, y);
}
