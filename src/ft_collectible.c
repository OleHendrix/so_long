/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_collectible.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 17:58:23 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/01/31 20:03:20 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_collectible(mlx_t *mlx, t_vars *vars)
{
	int	x;

	vars->movements++;
	ft_printf("Total amount of movements: %d\n", vars->movements);
	x = (vars->xlen / 2) * 128;
	if (vars->arr[vars->yp][vars->xp] == 'C')
	{
		vars->count++;
		if (vars->xlen >= 8)
			mlx_image_to_window(mlx, vars->sc[vars->count], x, 3 * 128);
		vars->arr[vars->yp][vars->xp] = '0';
	}
	if (vars->arr[vars->yp][vars->xp] == 'E' && vars->count == vars->col)
		mlx_close_window(mlx);
}
