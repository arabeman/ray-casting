/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabenja <mrabenja@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:53:28 by mrabenja          #+#    #+#             */
/*   Updated: 2025/03/07 10:54:49 by mrabenja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "const.h"
# include "struct.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/time.h>
# include <time.h>

// parsing
void			init_counter(t_counter *counter);
bool			str_is_valid(char *str);
int				valid_file_ext(char *file_name);
int				parse_id_line(char *line, t_map_config *config,
					t_counter *counter);
void			init_map_config(t_map_config *map_cf);
char			**ft_split_wsp(char const *s);
int				is_pos_closed(char **map_copy, int y, int x);
int				get_content(int fd, t_map_config *cf, char **av);
int				handle_error_input(int ac, char **av, t_map_config *cf);
void			free_map_config(t_map_config *config);

// window
void			start_win(t_data *m);
void			cleanup(t_data *m);
int				handle_mouse(int x, int y, t_data *data);
// key
int				key_press(int keycode, t_data *data);
int				key_release(int keycode, t_data *data);

// angle
void			set_player_angle(t_map_config *cf);
void			reset_angle(double *ray_angle);

// ray
bool			has_wall_at(t_data *data, int x, int y);
bool			has_wall_near(t_data *data, int x, int y);
int				cast_ray(t_map_config *cf, int col, double *ray_dst);
void			render_frame(t_data *data);
void			move_player(t_data *data);
void			ft_mlx_pixel_put(t_framebuffer *img, int x, int y,
					unsigned int color);
void			init_ray_data(t_ray_data *rd);
void			render_background(t_data *data);
int				cast_ray2(t_map_config *cf, int col, double *ray_dst,
					t_ray_data *rd);

// wall
void			calculate_wall_bound(double ray_dist, int *draw_start,
					int *draw_end);
void			put_pixel(char *addr, int pix_idx, int color);
void			render_wall(int col, double ray_dist, char *addr, int side);

// textures
int				valid_texture_path(char *path);
void			load_textures(t_data *data);
void			set_texture_data(t_data *data);
void			free_textures(t_data *data);
void			free_torch(t_data *data);
t_texture		*get_wall_txt(t_data *data, t_ray_data *rd);
int				get_texture_pxl(t_texture *txt, int x, int y);
void			render_textured_wall(int col, double ray_dist, t_data *data,
					t_ray_data *rd);
void			load_door_textures(t_data *data);
void			handle_door_texture(char **splitted, t_anim_textures *anim);
void			handle_player_textures(char **splitted, t_anim_textures *anim);
void			load_player_textures(t_data *data);
void			handle_player_animation(t_data *data);
void			render_player_weapon(t_data *data);
void			ft_put_pixel(t_data *data, int x, int y, int color);
unsigned int	get_pixel_img(t_img img, int x, int y);

// projection
void			render_floor_ceiling(t_data *data, int x, t_ray_data *rd);

// minimap
void			init_minimap(t_data *data);
int				render_minimap(t_data *data);
void			render_img_minimap(t_data *data, t_img img, int x, int y);
void			put_pixel_minimap(t_minimap *minimap, int x, int y, int color);
void			render_wall_minimap(t_data *data, int x, int y);
void			move_player_bonus(t_data *data);
void			draw_border(t_data *data);

// fog
unsigned int	apply_fog(unsigned int color, double dist, t_fog *fog);

// door
bool			is_closed_door_neaby(t_data *data);
void			handle_door(t_data *data);
bool			is_open_door_neaby(t_data *data);

// view
void			init_viewmodel(t_data *data);
void			render_viewmodel(t_data *data);

// animation
void			bounce(t_data *data);
bool			get_boolean(void);
int				get_integer(void);
void			set_integer(int value);
void			set_boolean(bool value);
t_data			*get_data(void);
void			set_data(t_data *value);

#endif