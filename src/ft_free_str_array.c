/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:18:57 by anshimiy          #+#    #+#             */
/*   Updated: 2023/07/02 22:38:59 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mylib.h"

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
}

void	ft_free_int_array(int **array)
{
	int	i;

	i = -1;
	while (array && array[++i])
		ft_free(array[i]);
	ft_free(array);
}

void	ft_free_two(void *ptr1, void *ptr2)
{
	if (ptr1)
		free(ptr1);
	if (ptr2)
		free(ptr2);
	ptr1 = NULL;
	ptr2 = NULL;
}

void	ft_free_three(void *ptr1, void *ptr2, void *ptr3)
{
	if (ptr1)
		free(ptr1);
	if (ptr2)
		free(ptr2);
	if (ptr3)
		free(ptr3);
	ptr1 = NULL;
	ptr2 = NULL;
	ptr3 = NULL;
}

void	ft_free_str_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}
