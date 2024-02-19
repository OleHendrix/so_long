/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checkpath.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohendrix <ohendrix@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 17:58:29 by ohendrix      #+#    #+#                 */
/*   Updated: 2024/01/31 18:21:50 by ohendrix      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_checkexit(char **arr, t_v pos, bool **visited)
{
	if (arr[pos.y][pos.x] == 'E')
		return (1);
	if (arr[pos.y][pos.x] == '1' || visited[pos.y][pos.x] == true)
		return (0);
	visited[pos.y][pos.x] = true;
	if (ft_checkexit(arr, (t_v){pos.y, pos.x + 1}, visited) == 1)
		return (1);
	if (ft_checkexit(arr, (t_v){pos.y, pos.x - 1}, visited) == 1)
		return (1);
	if (ft_checkexit(arr, (t_v){pos.y + 1, pos.x}, visited) == 1)
		return (1);
	if (ft_checkexit(arr, (t_v){pos.y - 1, pos.x}, visited) == 1)
		return (1);
	return (0);
}

int	checkcol(char **arr, t_v pos, int collectibles, bool **visited)
{
	static int	count;

	if (arr[pos.y][pos.x] == '1' || visited[pos.y][pos.x] == true)
		return (0);
	if (arr[pos.y][pos.x] == 'C')
		count++;
	if (count == collectibles)
		return (1);
	visited[pos.y][pos.x] = true;
	if (checkcol(arr, (t_v){pos.y, pos.x + 1}, collectibles, visited) == 1)
		return (1);
	if (checkcol(arr, (t_v){pos.y, pos.x - 1}, collectibles, visited) == 1)
		return (1);
	if (checkcol(arr, (t_v){pos.y + 1, pos.x}, collectibles, visited) == 1)
		return (1);
	if (checkcol(arr, (t_v){pos.y - 1, pos.x}, collectibles, visited) == 1)
		return (1);
	return (0);
}

bool	**ft_initializevisited(char **array)
{
	int		y;
	bool	**visited;

	y = 0;
	visited = malloc(gety(array) * sizeof(bool *));
	if (!visited)
		return (0);
	while (y < gety(array))
	{
		visited[y] = ft_calloc(ft_strlen(array[0]), sizeof(bool));
		if (!visited[y])
		{
			while (y >= 1)
			{
				free(visited[y - 1]);
				y--;
			}
			return (free(visited), NULL);
		}
		y++;
	}
	return (visited);
}
