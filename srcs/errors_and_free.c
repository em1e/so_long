/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:21:43 by vkettune          #+#    #+#             */
/*   Updated: 2024/05/10 16:19:01 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(char *msg)
{
	ft_printf("Error: %s\n", msg);
	return (0);
}

int	game_error(mlx_t *mlx, t_map *map, char *msg, int won)
{
	ft_printf("Error: %s\n", msg);
	end_game(map, mlx, won);
	return (0);
}

int	free_grid(t_grid **grid)
{
	int	i;

	i = 0;
	while (grid[i] != 0)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	return (0);
}
