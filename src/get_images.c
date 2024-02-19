/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_images.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 17:52:28 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/01/31 20:12:06 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**ft_getpaths(void)
{
	char	**paths;

	paths = malloc(8 * sizeof(char *));
	if (!paths)
		return (NULL);
	paths[0] = "./images/wall.png";
	paths[1] = "./images/path.png";
	paths[2] = "./images/player_right.png";
	paths[3] = "./images/collectible.png";
	paths[4] = "./images/endpoint.png";
	paths[5] = "./images/player_left.png";
	paths[6] = "./images/header.png";
	paths[7] = "./images/header2.png";
	return (paths);
}

void	ft_freetextures2(mlx_texture_t **textures, char **paths, int i)
{
	while (i >= 1)
	{
		mlx_delete_texture(textures[i - 1]);
		i--;
	}
	free(textures);
	free(paths);
}

void	ft_freetextures(mlx_texture_t **textures)
{
	int	i;

	i = 0;
	while (textures[i] != NULL)
	{
		mlx_delete_texture(textures[i]);
		i++;
	}
	free(textures);
}

mlx_texture_t	**ft_loadpng(void)
{
	mlx_texture_t	**textures;
	char			**paths;
	int				i;

	textures = malloc(sizeof(mlx_texture_t *) * 9);
	if (!textures)
		return (NULL);
	paths = ft_getpaths();
	if (paths == NULL)
		return (free(textures), NULL);
	i = 0;
	while (i < 8)
	{
		textures[i] = mlx_load_png(paths[i]);
		if (textures[i] == NULL)
			return (ft_freetextures2(textures, paths, i), NULL);
		i++;
	}
	textures[i] = NULL;
	free(paths);
	return (textures);
}

mlx_image_t	**ft_getim(mlx_t *mlx, mlx_texture_t **textures)
{
	mlx_image_t	**images;

	if (textures == NULL)
		return (NULL);
	images = malloc(sizeof(mlx_image_t *) * 9);
	if (!images)
		return (ft_freetextures(textures), NULL);
	images[0] = mlx_texture_to_image(mlx, textures[0]);
	images[1] = mlx_texture_to_image(mlx, textures[1]);
	images[2] = mlx_texture_to_image(mlx, textures[2]);
	images[3] = mlx_texture_to_image(mlx, textures[3]);
	images[4] = mlx_texture_to_image(mlx, textures[4]);
	images[5] = mlx_texture_to_image(mlx, textures[5]);
	images[6] = mlx_texture_to_image(mlx, textures[6]);
	images[7] = mlx_texture_to_image(mlx, textures[7]);
	images[8] = NULL;
	return (ft_freetextures(textures), images);
}
