/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvillefr <jvillefr@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:26:12 by anshimiy          #+#    #+#             */
/*   Updated: 2023/07/21 15:07:55 by jvillefr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ****** INCLUDES ****** */

# include 	"my_lib/mylib.h"
# include	"MLX42/include/MLX42/MLX42.h"
# include	<stdarg.h>
# include	<stdio.h>
# include	<limits.h>
# include	<stddef.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<math.h>
# include	<complex.h>
# include	<fcntl.h>
// # include	<mlx.h>
# include	"cub3d_struct.h"

#define WIDTH 256
#define HEIGHT 256



/* ****************************** FUNCTIONS ****************************** */

/* ******   CUB3D   ****** */
void                cub3d(t_game_info *game_info);

/* ******   RAYCASTING/INIT   ****** */
t_raycaster_data	init_raycaster_data(t_game_info *game_info);

/* ******   RAYCASTING/MOVEMENTS    ****** */
void            rotate_player(t_raycaster_data *rc, double rot);

/* ******   RAYCASTING   ****** */
void            raycast(t_raycaster_data *rc);

/* ******   RAYCASTING/WALL/DRAW   ****** */
void	prepare_for_drawing(t_raycaster_data *rc);
void	prepare_for_texture(t_raycaster_data *rc);
void	draw_textured_walls(t_raycaster_data *rc);

/* ******    PARSING/INIT    ****** */
t_game_info     *ft_init_game_info(char **argv);
void            ft_parse_infos(char* path, t_game_info *game_info);
void            ft_load_textures(char **file_data, t_game_info *game_info);
void            ft_load_map(char **file_data, t_game_info *game_info);
int             ft_get_color(char **strings, char *id);
void            ft_create_int_map(char **file_data, t_game_info *game_info);

/* ******     UTILS     ****** */
int             ft_find_map_position(char** file_data);
char            **ft_split_set(char *str, char *set);

/* ******     UTILS/DRAW     ****** */
void	        lh_init(t_line_data *line_data, t_point *p1, t_point *p2);
t_rectangle	    init_rectangle(int x, int y, int width, int height);
t_point	        init_point(int x, int y);
void            set_background(t_raycaster_data rc);
void	        draw_triangle(mlx_image_t *image, t_point p1, t_point p2, t_point p3, uint32_t color);
void	        draw_line(mlx_image_t *img, t_point p1, t_point p2, int color);
void            draw_rectangle(mlx_image_t *image, t_rectangle rec, uint32_t color);

/* ******   MINIMAP   ****** */
void               draw_map(t_raycaster_data rc);

/* ******   RAYCASTING/UTILS   ****** */
void            key_hook(t_raycaster_data *rc);
t_rectangle     init_rectangle(int x, int y, int width, int height);
double          degree_to_radian(int a);
t_point         init_point(int x, int y);

/* ******     ERRORS     ****** */
void	        ft_file_error_case(int error);
void        	ft_map_error_case(int error);
void            ft_texture_error_case(int error);
void            ft_color_error_case(int error);

/* ******      MLX      ****** */
mlx_image_t	    *new_image(mlx_t *mlx, int width, int height);
void	        image_to_window(mlx_t *mlx, mlx_image_t *image, int x, int y);
void	        put_pixel(mlx_image_t *image, int x, int y, uint32_t color);
mlx_texture_t	*load_png(char *path);
void	my_mlx_pixel_put(mlx_image_t* image, int x, int y, int color);
void draw_circle(mlx_image_t* image, int center_x, int center_y, int radius);
void draw_line_bresenham(mlx_image_t* image, int x0, int y0, int x1, int y1);
void draw_line_dda(mlx_image_t* image, int x0, int y0, int x1, int y1);
void draw_triangles(mlx_image_t* image, int x0, int y0, int x1, int y1, int x2, int y2);
int	create_trgb(int t, int r, int g, int b);
int add_shade(double transparent, int r, int g, int b);
int get_opposite(int t, int r, int g, int b);
void draw_square(mlx_image_t* image, int  x);
#endif
