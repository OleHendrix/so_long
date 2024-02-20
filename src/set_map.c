/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_map.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 17:49:20 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/01/31 19:55:07 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_setsmallheader(mlx_t *mlx, mlx_image_t **images, int arraylen)
{
	int	x;

	if (arraylen % 2 == 0)
		x = ((arraylen / 2) * 128) - 192;
	else
		x = ((arraylen / 2) - 1) * 128;
	if (mlx_image_to_window(mlx, images[7], x, 0) == -1)
		return (0);
	return (1);
}

int	ft_setheader(mlx_t *mlx, char **array, mlx_image_t **im, mlx_image_t **sc)
{
	int	y;
	int	arraylen;
	int	x;

	y = 0;
	arraylen = ft_strlen(array[0]);
	while (y < 4)
	{
		x = 0;
		while (x < arraylen)
		{
			if (mlx_image_to_window(mlx, im[1], x * 128, y * 128) == -1)
				return (0);
			x++;
		}
		y++;
	}
	x = (arraylen / 2) - 4;
	if (arraylen < 8)
		return (ft_setsmallheader(mlx, im, arraylen));
	if (mlx_image_to_window(mlx, im[6], x * 128, 0) == -1)
		return (0);
	if (mlx_image_to_window(mlx, sc[0], (arraylen / 2) * 128, 3 * 128) == -1)
		return (0);
	return (1);
}

int	ft_setmap(mlx_t *mlx, char **array, mlx_image_t **i, mlx_image_t **sc)
{
	int	y;
	int	x;

	y = 0;
	while (array[y] != NULL)
	{
		x = 0;
		while (array[y][x] != '\0')
		{
			if (array[y][x] == '1' && draw(mlx, i[0], x, y +4) == -1)
				return (0);
			if (array[y][x] == '0' && draw(mlx, i[1], x, y +4) == -1)
				return (0);
			if (array[y][x] == 'P' && draw(mlx, i[2], x, y +4) == -1)
				return (0);
			if (array[y][x] == 'C' && draw(mlx, i[3], x, y +4) == -1)
				return (0);
			if (array[y][x] == 'E' && draw(mlx, i[4], x, y +4) == -1)
				return (0);
			x++;
		}
		y++;
	}
	return (ft_setheader(mlx, array, i, sc));
}

int	checkhole(char *string)
{
	int	x;

	x = 0;
	while (string[x] != '\0')
	{
		if (string[x] == '\n' && string[x + 1] == '\n')
			return (0);
		x++;
	}
	return (1);
}

char	**ft_makearr(char *map)
{
	char	*string;
	char	*new_string;
	char	**array;
	char	temp[2];
	int		fd;

	fd = open(map, O_RDONLY);
	string = malloc(1);
	if (!string)
		return (NULL);
	string[0] = '\0';
	while ((read(fd, temp, 1) > 0))
	{
		temp[1] = '\0';
		new_string = ft_strjoin(string, temp);
		free(string);
		string = new_string;
	}
	close(fd);
	if (string[0] == '\0' || checkhole(string) == 0)
		return (free(string), NULL);
	array = ft_split(string, '\n');
	free(string);
	return (array);
}
