/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fog_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:36:45 by mrabenja          #+#    #+#             */
/*   Updated: 2025/02/28 15:38:16 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

unsigned int	apply_fog(unsigned int color, double dist, t_fog *fog)
{
	fog->fog_r = 20;
	fog->fog_g = 20;
	fog->fog_b = 30;
	fog->b = color & 0xFF;
	fog->g = (color >> 8) & 0xFF;
	fog->r = (color >> 16) & 0xFF;
	fog->a = (color >> 24) & 0xFF;
	fog->fog_factor = dist / fog->max_fog_dist;
	if (fog->fog_factor > 1.0)
		fog->fog_factor = 1.0;
	fog->b = fog->b + fog->fog_factor * (fog->fog_b - fog->b);
	fog->g = fog->g + fog->fog_factor * (fog->fog_g - fog->g);
	fog->r = fog->r + fog->fog_factor * (fog->fog_r - fog->r);
	return ((fog->a << 24) | (fog->r << 16) | (fog->g << 8) | fog->b);
}
