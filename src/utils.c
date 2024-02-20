/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 17:57:31 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/01/31 19:55:44 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	draw(mlx_t *mlx, mlx_image_t *image, int x, int y)
{
	return (mlx_image_to_window(mlx, image, x * 128, y * 128));
}

int	gety(char **array)
{
	int	y;

	y = 0;
	while (array[y] != NULL)
		y++;
	return (y);
}

int	getxpostition(char **array)
{
	int	y;
	int	x;

	y = 0;
	while (array[y] != NULL)
	{
		x = 0;
		while (array[y][x] != '\0')
		{
			if (array[y][x] == 'P')
				return (x);
			x++;
		}
		y++;
	}
	return (0);
}

int	getypostition(char **array)
{
	int	y;
	int	x;

	y = 0;
	while (array[y] != NULL)
	{
		x = 0;
		while (array[y][x] != '\0')
		{
			if (array[y][x] == 'P')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}
