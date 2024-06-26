/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:14:46 by vkettune          #+#    #+#             */
/*   Updated: 2024/04/27 04:02:28 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_instance_t	*get_tile(t_map *map, int y, int x)
{
	mlx_image_t	*image;
	int			inst;

	image = map->grid[y][x].tile_img;
	inst = map->grid[y][x].tile_inst;
	return (&image->instances[inst]);
}

mlx_instance_t	*get_object(t_map *map, int y, int x)
{
	mlx_image_t	*image;
	int			inst;

	image = map->grid[y][x].obj_img;
	if (image == 0)
		return (0);
	inst = map->grid[y][x].obj_inst;
	return (&image->instances[inst]);
}

mlx_instance_t	*get_player(t_map *map)
{
	mlx_image_t	*image;
	int			inst;

	image = map->player.img;
	if (image == 0)
		return (0);
	inst = map->player.inst;
	return (&image->instances[inst]);
}
