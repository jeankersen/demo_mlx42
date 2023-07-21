/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexnshimiyimana <alexnshimiyimana@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:56:12 by anshimiy          #+#    #+#             */
/*   Updated: 2023/07/18 11:12:37 by alexnshimiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// todo

// Draws a triangle as the player on the minimap.
static void draw_player_triangle(t_raycaster_data rc, int color)
{
    // Calculate the three points of the triangle based on the player's position and direction.
    // t_point p1 = init_point(rc.px * rc.tile_size, rc.py * rc.tile_size);
    t_point p1;
    t_point p2;
    t_point p3;
	p1 = init_point(rc.px * rc.tile_size - rc.pdy * (rc.tile_size / 4),
                             rc.py * rc.tile_size + rc.pdx * (rc.tile_size / 4));
    p2 = init_point(rc.px * rc.tile_size + rc.pdx * (rc.tile_size / 2),
                             rc.py * rc.tile_size + rc.pdy * (rc.tile_size / 2));
    p3 = init_point(rc.px * rc.tile_size + rc.pdy * (rc.tile_size / 4),
                             rc.py * rc.tile_size - rc.pdx * (rc.tile_size / 4));
    // Draw the triangle on the minimap.
    draw_triangle(rc.minimap, p1, p2, p3, color);
}

// Draws the player on the minimap with a direction vector.
static void	draw_player(t_raycaster_data rc)
{
	draw_player_triangle(rc, YELLOW);
    draw_line(rc.minimap, init_point(rc.px * rc.tile_size, rc.py * rc.tile_size),
        init_point(rc.px * rc.tile_size + rc.pdx * (rc.tile_size),
			       rc.py * rc.tile_size + rc.pdy * (rc.tile_size)), RED);
}

// Check what type is the tile and draws it on the minimap.
static void	draw_map_tile(t_raycaster_data rc, int x, int y)
{
    if (rc.map[y][x] == 1)
	{
		draw_rectangle(rc.minimap,
			init_rectangle(x * rc.tile_size + 1, y * rc.tile_size + 1,
				rc.tile_size - 2, rc.tile_size - 2), WHITE);
	}
	else if (rc.map[y][x] == 0)
	{
		draw_rectangle(rc.minimap,
			init_rectangle(x * rc.tile_size + 1, y * rc.tile_size + 1,
				rc.tile_size - 2, rc.tile_size - 2), DARK_GRAY);
	}
	else
	{
		draw_rectangle(rc.minimap,
			init_rectangle(x * rc.tile_size, y * rc.tile_size,
				rc.tile_size, rc.tile_size), TRANSLUCENT);
	}
}

// Draws a minimap that shows the floor and the walls.
void	draw_map(t_raycaster_data rc)
{
    int	x;
	int	y;

	if (rc.tile_size == -1)
	{
		draw_rectangle(rc.minimap, init_rectangle(0, 0, rc.map_width * rc.tile_size,
				rc.map_height * rc.tile_size), TRANSPARENT);
		return ;
	}
	draw_rectangle(rc.minimap, init_rectangle(0, 0, rc.map_width * rc.tile_size,
			rc.map_height * rc.tile_size), BLACK);
	x = 0;
	while (x < rc.map_width)
	{
		y = 0;
		while (y < rc.map_height)
		{
			draw_map_tile(rc, x, y);
			y++;
		}
		x++;
	}
	draw_player(rc);
}
