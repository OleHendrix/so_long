/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkmap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 17:58:59 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/01/31 20:24:05 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	checkcol(char **array, t_v pos, int collectibles, bool **visited);

void	ft_resetvisited(char **array, bool **visited)
{
	int	y;

	y = 0;
	while (y < gety(array))
	{
		ft_bzero(visited[y], (ft_strlen(array[0]) * sizeof(bool)));
		y++;
	}
}

void	ft_freebool(char **array, bool **visited)
{
	int	y;

	y = gety(array) - 1;
	while (y >= 0)
	{
		free(visited[y]);
		y--;
	}
	free(visited);
}

int	ft_checkpath(char **array, int collectibles)
{
	t_v			pos;
	bool		**visited;

	pos = (t_v){getypostition(array), getxpostition(array)};
	visited = ft_initializevisited(array);
	if (ft_checkexit(array, pos, visited) == 0)
		return (ft_freebool(array, visited), 0);
	ft_resetvisited(array, visited);
	pos = (t_v){getypostition(array), getxpostition(array)};
	if (checkcol(array, pos, collectibles, visited) == 0)
		return (ft_freebool(array, visited), 0);
	return (ft_freebool(array, visited), 1);
}

int	ft_checkmap2(char **array, int *count)
{
	int	collectibles;

	collectibles = count[2];
	if (count[0] != 1 || count[1] != 1 || count[2] < 1 || collectibles > 5)
		return (free(count), 0);
	if (ft_checkpath(array, collectibles) == 0)
		return (free(count), 0);
	return (free(count), collectibles);
}

int	ft_checkmap(char **arr, int a, int b, int y)
{
	int	x;
	int	*count;

	count = ft_calloc(3, sizeof(int));
	if (!count)
		return (0);
	while (arr[y] != NULL)
	{
		x = 0;
		while (arr[y][x] != '\0')
		{
			if (arr[0][x] != '1' || arr[b - 1][x] != '1' || arr[y][0] != '1' ||
					arr[y][a - 1] != '1' || !ft_strchr("10PEC", (arr[y][x])))
				return (free(count), 0);
			if (arr[y][x] == 'P')
				count[0]++;
			if (arr[y][x] == 'E')
				count[1]++;
			if (arr[y][x] == 'C')
				count[2]++;
			x++;
		}
		y++;
	}
	return (ft_checkmap2(arr, count));
}
