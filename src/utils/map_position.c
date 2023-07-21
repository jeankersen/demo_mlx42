/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexnshimiyimana <alexnshimiyimana@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:24:57 by anshimiy          #+#    #+#             */
/*   Updated: 2023/07/12 13:42:16 by alexnshimiy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief  Return the position of the map in the file_data
 * @note   TODO: make sure this function is valid and don't need more...
 * @param  file_data: 
 * @retval 
*/
int ft_find_map_position(char** file_data)
{
    int i;

    i = 0;
    while (file_data[i])
    {
        if (file_data[i][0] && ft_str_made_of_set(file_data[i], "\t 1"))
        {
            return (i);
        }
        i++;
    }
    return (-1);
    // ft_char_in_str(file_data[0], '1') || ft_char_in_str(file_data[0], ' ');
}