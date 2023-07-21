/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexnshimiyimana <alexnshimiyimana@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:37:28 by anshimiy          #+#    #+#             */
/*   Updated: 2023/07/18 11:28:32 by alexnshimiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


/**
 * @brief  Using Bresenham's line drawing algorithm
 * @note   
 * @param  *img: 
 * @param  p1: 
 * @param  p2: 
 * @param  color: 
 * @retval None
*/
void	draw_line(mlx_image_t *img, t_point p1, t_point p2, int color)
{
    t_line_data	line_data;

	lh_init(&line_data, &p1, &p2);
	while (1)
	{
		put_pixel(img, line_data.x, line_data.y, color);
		if ((line_data.x == p2.x) && (line_data.y == p2.y))
			break ;
		line_data.e2 = 2 * line_data.err;
		if (line_data.e2 >= line_data.dy)
		{
			line_data.err += line_data.dy;
			line_data.x += line_data.sx;
		}
		if (line_data.e2 <= line_data.dx)
		{
			line_data.err += line_data.dx;
			line_data.y += line_data.sy;
		}
	}
}

void	draw_rectangle(mlx_image_t *image, t_rectangle rec, uint32_t color)
{
	int32_t	i;
	int32_t	j;

	i = rec.x;
	while (i < rec.width + rec.x)
	{
		j = rec.y;
		while (j < rec.height + rec.y)
		{
			put_pixel(image, i, j, color);
			j++;
		}
		i++;
	}
}

void	set_background(t_raycaster_data rc)
{
	// test
	// mlx_texture_t		*ceill = load_png("/Users/anshimiy/Desktop/toPush/cub3d_work/textures/widewall.png");
	// image_to_window(rc.mlx, rc.background, 0, 0);
	draw_rectangle(
		rc.background,
		init_rectangle(0, 0, rc.screen_width, rc.screen_height / 2 + rc.vertical_view),
		rc.ceiling_color);
	draw_rectangle(
		rc.background,
		init_rectangle(0, rc.screen_height / 2 + rc.vertical_view, rc.screen_width,
			rc.screen_height / 2 - rc.vertical_view),
		rc.floor_color);
}

void	draw_triangle(mlx_image_t *image, t_point p1, t_point p2, t_point p3, uint32_t color)
{
	draw_line(image, p1, p2, color); //  |
	draw_line(image, p2, p3, color); // /
	draw_line(image, p3, p1, color); // -
}