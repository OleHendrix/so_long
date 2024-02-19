/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_scores.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 17:55:50 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/01/31 20:12:51 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**ft_getscorespaths(void)
{
	char	**scorespaths;

	scorespaths = malloc(6 * sizeof(char *));
	if (!scorespaths)
		return (NULL);
	scorespaths[0] = "./images/0.png";
	scorespaths[1] = "./images/1.png";
	scorespaths[2] = "./images/2.png";
	scorespaths[3] = "./images/3.png";
	scorespaths[4] = "./images/4.png";
	scorespaths[5] = "./images/5.png";
	return (scorespaths);
}

mlx_texture_t	**ft_loadsc(void)
{
	mlx_texture_t	**textures;
	char			**scorespaths;
	int				i;

	textures = malloc(sizeof(mlx_texture_t *) * 7);
	if (!textures)
		return (NULL);
	scorespaths = ft_getscorespaths();
	if (scorespaths == NULL)
		return (free(textures), NULL);
	i = 0;
	while (i < 6)
	{
		textures[i] = mlx_load_png(scorespaths[i]);
		if (textures[i] == NULL)
			return (ft_freetextures2(textures, scorespaths, i), NULL);
		i++;
	}
	textures[i] = NULL;
	free(scorespaths);
	return (textures);
}

mlx_image_t	**ft_getsc(mlx_t *mlx, mlx_texture_t **textures)
{
	mlx_image_t	**scores;

	if (textures == NULL)
		return (NULL);
	scores = malloc(sizeof(mlx_image_t *) * 7);
	if (!scores)
		return (ft_freetextures(textures), NULL);
	scores[0] = mlx_texture_to_image(mlx, textures[0]);
	scores[1] = mlx_texture_to_image(mlx, textures[1]);
	scores[2] = mlx_texture_to_image(mlx, textures[2]);
	scores[3] = mlx_texture_to_image(mlx, textures[3]);
	scores[4] = mlx_texture_to_image(mlx, textures[4]);
	scores[5] = mlx_texture_to_image(mlx, textures[5]);
	scores[6] = NULL;
	return (ft_freetextures(textures), scores);
}
