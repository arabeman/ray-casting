/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:46 by mrabenja          #+#    #+#             */
/*   Updated: 2025/03/07 11:02:12 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_counter(t_counter *counter)
{
	counter->no_number = 0;
	counter->so_number = 0;
	counter->ea_number = 0;
	counter->we_number = 0;
	counter->flo_number = 0;
	counter->ceil_number = 0;
}

bool	str_is_valid(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) || str[i] == ',')
	{
		if (str[i] == ',')
		{
			count++;
			if (str[i + 1] == '+')
				i++;
		}
		i++;
	}
	if (count != 2)
		return (false);
	if (str[i] && (!ft_isdigit(str[i]) && str[i] != ','))
		return (false);
	return (true);
}
