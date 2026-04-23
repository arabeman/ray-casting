/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:40:14 by arabeman          #+#    #+#             */
/*   Updated: 2025/03/07 10:48:23 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>

typedef struct s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct s_pos_int
{
	int				x;
	int				y;
}					t_pos_int;

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct s_key
{
	bool			forward;
	bool			backward;
	bool			right;
	bool			left;
	bool			turn_left;
	bool			turn_right;
	bool			open_door;
	bool			close_door;
	bool			alt;
	bool			fire;
}					t_key;

typedef struct s_anim_textures
{
	char			*door_tex;
	int				has_door;
	char			**player_tex;
	int				num_player_tex;
}					t_anim_textures;

typedef struct s_counter
{
	int				no_number;
	int				so_number;
	int				we_number;
	int				ea_number;
	int				flo_number;
	int				ceil_number;
}					t_counter;

typedef struct s_map_config
{
	char			*no_texture;
	char			*so_texture;
	char			*we_texture;
	char			*ea_texture;
	char			*floor_texture;
	char			*ceiling_texture;
	t_color			floor_c;
	t_color			ceiling_c;
	char			**map;
	int				height;
	int				width;
	double			player_x;
	double			player_y;
	int				map_x;
	int				map_y;
	double			player_angle;
	char			player_dir;
	int				has_no;
	int				has_so;
	int				has_we;
	int				has_ea;
	int				has_floor;
	int				has_ceiling;
	t_anim_textures	anim;
}					t_map_config;

typedef struct s_ray_data
{
	double			ray_x;
	double			ray_y;
	double			delta_x;
	double			delta_y;
	int				step_x;
	int				step_y;
	double			side_dist_x;
	double			side_dist_y;
	int				hit;
	int				side;
	double			ray_angle;
	double			corrected_fisheye;
}					t_ray_data;

typedef struct s_framebuffer
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_framebuffer;

typedef struct s_texture
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_texture;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	double			angle;
}					t_img;

typedef struct s_minimap
{
	char			**map;

	t_img			minimap_img;
	t_img			player_img;

	double			x;
	double			y;
}					t_minimap;

typedef struct s_floor_ceiling
{
	double			ray_dir_x;
	double			ray_dir_y;
	double			camera_y;
	double			center;
	double			current_floor_x;
	double			current_floor_y;
	double			current_dist;
}					t_floor_ceiling;

typedef struct s_render_param
{
	double			line_height;
	int				draw_start;
	int				draw_end;
	int				tex_x;
	int				tex_y;
	double			step;
	t_texture		*texture;
	double			tex_pos;
}					t_render_param;

typedef struct s_fog
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
	double			fog_factor;
	unsigned char	fog_r;
	unsigned char	fog_g;
	unsigned char	fog_b;
	double			max_fog_dist;
}					t_fog;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_framebuffer	*framebuff;
	t_map_config	*map_config;
	t_key			key;
	t_texture		textures[7];
	t_texture		player_tex[5];
	bool			enable_minimap;
	t_minimap		*minimap;
	int				player_start_index[2];
	int				current_player_tex;
	bool			is_firing;
	int				fire_frame;
	t_img			torch[5];
	int				map_size[2];
}					t_data;

#endif