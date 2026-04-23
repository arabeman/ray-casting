/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:18:39 by arabeman          #+#    #+#             */
/*   Updated: 2025/02/28 15:36:49 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static bool	*boolean(void)
{
	static bool	value = false;

	return (&value);
}

bool	get_boolean(void)
{
	return (*boolean());
}

void	set_boolean(bool value)
{
	*boolean() = value;
}
