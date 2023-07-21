/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexnshimiyimana <alexnshimiyimana@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:11:08 by anshimiy          #+#    #+#             */
/*   Updated: 2023/07/18 10:42:47 by alexnshimiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// todo

// Length of ray from current position to next x or y-side
// Delta distance calculation
static void	delta_distance_calculation(t_raycaster_data *rc)
{
	
}

// Calculate step and initial side distance
static void	step_calculation(t_raycaster_data *rc)
{
	
}

// DDA or "Digital Differential Analysis". DDA is a fast algorithm typically
// used on square grids to find which squares a line hits (for example to
// draw a line on a screen, which is a grid of square pixels).
// rc->side is set to 0 for vertical hit or 1 for horizontal hit.
// When it hits a wall the loop breaks.
// Lastly it calculates the distance to the wall. */
static void	dda(t_raycaster_data *rc)
{
	
}

// First calculate the camera x position. Then calculate the ray direction
// and the map position. Then calculate the delta distance and the step size.
// Then do the DDA and calculate the distance to the wall.
// Then calculate the wall height and the start and end positions for the wall.
// Then calculate the step size and x position on the texture.
// Then draw the wall.
static void	cast_single_ray(t_raycaster_data *rc)
{
	
}

// Cast a ray for every x position on the screen.
void	raycast(t_raycaster_data *rc)
{
	rc->x = 0;
	while (rc->x < rc->screen_width)
	{
		cast_single_ray(rc);
		rc->x++;
	}
}
