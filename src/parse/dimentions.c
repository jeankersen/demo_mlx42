/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimentions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexnshimiyimana <alexnshimiyimana@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:15:27 by anshimiy          #+#    #+#             */
/*   Updated: 2023/07/12 13:54:11 by alexnshimiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief  Convert **file_data[i][j] to the **map[i][j] int array
 * @note   2: empty space, 1: wall, 0: floor
 * @param  **file_data: 
 * @param  *game_info: 
 * @param  i: i'th position in the map (height)
 * @param  j: j'th position in the map (width/position in the line)
 * @retval game_info->map_width if there's no map (to exit ft_set_int_map())
*/
int     ft_assign_number(char **file_data, t_game_info *game_info, int i, int j)
{
	if (!file_data[game_info->mapstart + i][j])
	{
		while (j < game_info->map_width)
		{
			game_info->map[i][j] = 2;
			j++;
		}
	}
	else if (file_data[game_info->mapstart + i][j] == '\t')
		game_info->map[i][j] = 2;
	else if (file_data[game_info->mapstart + i][j] == ' ')
		game_info->map[i][j] = 2;
	else if (file_data[game_info->mapstart + i][j] == '0')
		game_info->map[i][j] = 0;
	else if (file_data[game_info->mapstart + i][j] == '1')
		game_info->map[i][j] = 1;
	return (j);
}

/**
 * @brief  Loop through the **file_data map and convert it to the int **game_info->map
 * @note   with the help of ft_assign_number()
 * @param  **file_data: 
 * @param  *game_info: 
 * @retval None
*/
void	ft_set_int_map(char **file_data, t_game_info *game_info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game_info->map_height)
	{
		while (j <= game_info->map_width)
		{
			j = ft_assign_number(file_data, game_info, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

/**
 * @brief  Get the dimensions of the map and allocate the memory for it. 
 *		   Then create the **game_info->map int array with ft_set_int_map()
 * @note   
 * @param  **file_data: 
 * @param  *game_info: 
 * @retval None
*/
void    ft_create_int_map(char **file_data, t_game_info *game_info)
{
    int	len;
	int	i;

	i = game_info->mapstart + 1;
	len = ft_strlen(file_data[game_info->mapstart]);
	while (file_data[i])
	{
		if (len < (int)ft_strlen(file_data[i]))
			len = ft_strlen(file_data[i]);
		i++;
	}
	game_info->map_width = len;
	game_info->map_height = i - game_info->mapstart;
	i = 0;
	game_info->map = ft_calloc(game_info->map_height, sizeof(int *));
	if (!game_info->map)
		throw_error("Unable to malloc dimension Y value...", 1);
	while (i < game_info->map_height)
	{
		game_info->map[i] = ft_calloc(game_info->map_width, sizeof(int));
		if (!game_info->map[i])
			throw_error("Unable to malloc dimension X value...", 1);
		i++;
	}
    ft_set_int_map(file_data, game_info);
}