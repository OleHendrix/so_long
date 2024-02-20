/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 17:50:45 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/01/31 20:26:29 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int		ft_setmap(mlx_t *mlx, char **array, mlx_image_t **i, mlx_image_t **sc);
void	freeim(mlx_t *mlx, mlx_image_t **im, mlx_image_t **sc, char **arr);

void	ft_render(mlx_t *mlx, int x, int y, t_vars *v)
{
	int	a;

	a = 128;
	if (x == 1)
	{
		v->xp -= 1;
		mlx_image_to_window(mlx, v->im[5], v->xp * a, (v->yp +4) * a);
		v->k = 3;
	}
	if (x == -1)
	{
		v->xp += 1;
		mlx_image_to_window(mlx, v->im[2], v->xp * a, (v->yp +4) * a);
		v->k = 0;
	}
	if (y == 1 || y == -1)
	{
		v->yp += -y;
		mlx_image_to_window(mlx, v->im[2 + v->k], v->xp * a, (v->yp +4) * a);
	}
	if (v->arr[v->yp + y][v->xp + x] == 'E')
		mlx_image_to_window(mlx, v->im[4], (v->xp + x) * a, (v->yp + y +4) * a);
	else
		mlx_image_to_window(mlx, v->im[1], (v->xp + x) * a, (v->yp + y +4) * a);
	ft_collectible(mlx, v);
}

int	validmove(t_vars *vars, int x, int y)
{
	if (vars->arr[vars->yp + y][vars->xp + x] != '1')
		return (1);
	return (0);
}

void	ft_update_position(void *param)
{
	t_vars			*vars;
	static double	previous_time;

	vars = (t_vars *)param;
	if (mlx_is_key_down(vars->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(vars->mlx);
	if (previous_time + 0.1 > mlx_get_time())
		return ;
	previous_time = mlx_get_time();
	if (mlx_is_key_down(vars->mlx, MLX_KEY_LEFT) && validmove(vars, -1, 0) == 1)
		ft_render(vars->mlx, 1, 0, vars);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_RIGHT) && validmove(vars, 1, 0) == 1)
		ft_render(vars->mlx, -1, 0, vars);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_UP) && validmove(vars, 0, -1) == 1)
		ft_render(vars->mlx, 0, 1, vars);
	if (mlx_is_key_down(vars->mlx, MLX_KEY_DOWN) && validmove(vars, 0, 1) == 1)
		ft_render(vars->mlx, 0, -1, vars);
}

int	ft_vars(t_vars *vars, char *map)
{
	vars->arr = ft_makearr(map);
	if (vars->arr == NULL)
		return (perror("Map niet valid"), 0);
	vars->xp = getxpostition(vars->arr);
	vars->yp = getypostition(vars->arr);
	vars->xlen = ft_strlen(vars->arr[0]);
	vars->ylen = gety(vars->arr);
	vars->col = ft_checkmap(vars->arr, vars->xlen, vars->ylen, 0);
	if (vars->col == 0)
	{
		perror("Map niet valid");
		return (ft_freearr(vars->arr), 0);
	}
	vars->mlx = mlx_init(vars->xlen * 128, (vars->ylen + 4) * 128, "sl", true);
	if (vars->mlx == NULL)
		return (ft_freearr(vars->arr), 0);
	vars->im = ft_getim(vars->mlx, ft_loadpng());
	vars->sc = ft_getsc(vars->mlx, ft_loadsc());
	if (vars->im == NULL || vars->sc == NULL)
		return (freeim(vars->mlx, vars->im, vars->sc, vars->arr), 0);
	vars->count = 0;
	vars->movements = 0;
	vars->k = 0;
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return (0);
	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 4))
		return (perror("Map niet valid"), 0);
	if (ft_vars(&vars, argv[1]) == 0)
		return (0);
	if (ft_setmap(vars.mlx, vars.arr, vars.im, vars.sc) == 0)
		return (freeim(vars.mlx, vars.im, vars.sc, vars.arr), 0);
	mlx_loop_hook(vars.mlx, ft_update_position, &vars);
	mlx_loop(vars.mlx);
	freeim(vars.mlx, vars.im, vars.sc, vars.arr);
	mlx_terminate(vars.mlx);
}
