/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 17:57:57 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/01/31 18:37:53 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_freearr(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	freeim(mlx_t *mlx, mlx_image_t **im, mlx_image_t **sc, char **arr)
{
	int	i;

	i = 0;
	if (im != NULL)
	{
		while (im[i] != NULL)
		{
			mlx_delete_image(mlx, im[i]);
			i++;
		}
		free(im);
		i = 0;
	}
	if (sc != NULL)
	{
		while (sc[i] != NULL)
		{
			mlx_delete_image(mlx, sc[i]);
			i++;
		}
		free(sc);
	}
	ft_freearr(arr);
}
