/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabeman <arabeman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:41:24 by arabeman          #+#    #+#             */
/*   Updated: 2025/03/02 18:20:28 by arabeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
# define CONST_H

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define WIN_WIDTH 1000
# define WIN_HEIGHT 750
# define TILE_SIZE 32
# define FOV_ANGLE 1.0471975512
// 60 degrees

// player config
# define MOVE_SPEED 2.5
# define ROTA_SPEED 0.1
# define DIAGONAL_SPEED 1.75
// --> (0.07 * MOVE_SPEED) / 0.1

// minimap config
# define MINIMAP_TILE 32
# define MINIMAP_W 128
# define MINIMAP_H 128
# define MINIMAP_CENTER 64
# define PLAYER_POS 48
# define MINIMAP_COLOR 0xD0D4E4
# define BORDER_COLOR 0x222034

// fog param
# define MAX_FOG 4

// door interaction
# define DOOR_RATIO 1

// player texture
# define NB_PLAYER_TEX 5
# define SCALE_FACTOR 4

// keycode
# define W 119
# define A 97
# define S 115
# define D 100
# define Q 113
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define OPEN 32
# define CLOSE 99
# define FIRE 102
# define ALT 65513

// enum direction
enum	e_direct
{
	north,
	south,
	east,
	west,
	_floor,
	ceiling,
	door
};

#endif