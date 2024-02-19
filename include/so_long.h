/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 20:13:59 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/01/31 20:26:07 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>

# include "../MLX42/include/glad/glad.h"
# include "../MLX42/include/KHR/khrplatform.h"
# include "../MLX42/include/lodepng/lodepng.h"
# include "../MLX42/include/MLX42/MLX42_Int.h"
# include "../ft_printf/libftprintf.h"
# include "../Libft/libft.h"

typedef struct t_vars
{
	mlx_t			*mlx;
	mlx_image_t		**im;
	mlx_image_t		**sc;
	int				xlen;
	int				ylen;
	int				xp;
	int				yp;
	char			**arr;
	int				k;
	int				count;
	int				col;
	int				movements;
}	t_vars;

typedef struct t_v
{
	int	y;
	int	x;
}	t_v;

int				ft_vars(t_vars *vars, char *map);
void			ft_update_position(void *param);
int				ft_checkvalidmove(t_vars *vars, int x, int y);
void			ft_render(mlx_t *mlx, int x, int y, t_vars *v);
void			ft_collectible(mlx_t *mlx, t_vars *vars);
char			**ft_getpaths(void);
void			ft_freetextures2(mlx_texture_t **textures, char **paths, int i);
void			ft_freetextures(mlx_texture_t **textures);
mlx_texture_t	**ft_loadpng(void);
mlx_image_t		**ft_getim(mlx_t *mlx, mlx_texture_t **textures);
char			**ft_getscorespaths(void);
mlx_texture_t	**ft_loadsc(void);
mlx_image_t		**ft_getsc(mlx_t *mlx, mlx_texture_t **textures);
char			**ft_makearr(char *map);
int				checkhole(char *string);
int				ft_checkmap(char **array, int a, int b, int y);
int				ft_checkmap2(char **array, int *count);
int				ft_checkpath(char **array, int collectibles);
void			ft_freebool(char **array, bool **visited);
void			ft_resetvisited(char **array, bool **visited);
bool			**ft_initializevisited(char **array);
int				ft_checkexit(char **array, t_v pos, bool **visited);
int				getypostition(char **array);
int				getxpostition(char **array);
int				gety(char **array);
void			ft_freearr(char **array);
int				draw(mlx_t *mlx, mlx_image_t *image, int x, int y);

#endif