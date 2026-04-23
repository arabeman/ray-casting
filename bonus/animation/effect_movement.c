/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effect_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:26:17 by arabeman          #+#    #+#             */
/*   Updated: 2025/02/28 15:37:24 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	bounce(t_data *data)
{
	if (data->key.forward && data->key.backward)
		return ;
	if (data->key.right && data->key.left)
		return ;
	if (get_boolean())
	{
		set_integer(get_integer() + 1 + 2);
		if (get_integer() >= 20 - 1 - 2)
			set_boolean(false);
	}
	else
	{
		set_integer(get_integer() - 1 - 2);
		if (get_integer() <= 0)
			set_boolean(true);
	}
}
