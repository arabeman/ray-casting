/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:18:39 by arabeman          #+#    #+#             */
/*   Updated: 2025/02/28 15:37:34 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	*integer(void)
{
	static int	value = 0;

	return (&value);
}

int	get_integer(void)
{
	return (*integer());
}

void	set_integer(int value)
{
	*integer() = value;
}
