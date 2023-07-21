/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexnshimiyimana <alexnshimiyimana@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:09:13 by anshimiy          #+#    #+#             */
/*   Updated: 2023/07/13 22:00:16 by alexnshimiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// todo

// Calculate wall height, draw start and end positions for the wall.
// Calculate the step size and x position on the texture.
void	prepare_for_drawing(t_raycaster_data *rc)
{

}

// Set the texture to use for the wall depending on the side.
// Then set the x position on the texture.
// static void	prepare_for_texture(t_raycaster_data *rc)
void	prepare_for_texture(t_raycaster_data *rc)
{

}

// int	correct_color(u_int8_t *pixel)
// {
// 	int	rgba;

// 	rgba = 0;
// 	rgba += pixel[0] << 24;
// 	rgba += pixel[1] << 16;
// 	rgba += pixel[2] << 8;
// 	rgba += pixel[3];
// 	return (rgba);
// }

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

int32_t get_texture_color(u_int8_t *pixel)
{
    return (pixel[0] << 24 | pixel[1] << 16 | pixel[2] << 8 | pixel[3]);
}


// Draws the walls on the screen image.
void	draw_textured_walls(t_raycaster_data *rc)
{
}