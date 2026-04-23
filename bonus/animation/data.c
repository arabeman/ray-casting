/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:26:24 by arabeman          #+#    #+#             */
/*   Updated: 2025/02/28 15:37:01 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static t_data	**_data(void)
{
	static t_data	*value = 0;

	return (&value);
}

t_data	*get_data(void)
{
	return (*_data());
}

void	set_data(t_data *value)
{
	*_data() = value;
}
