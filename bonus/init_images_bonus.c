/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:11:53 by vkettune          #+#    #+#             */
/*   Updated: 2024/05/17 12:26:34 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

mlx_image_t	*load_img(mlx_t *mlx, char *file)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(file);
	if (texture == 0)
		return (0);
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}

int	init_images(mlx_t *mlx, t_map *map)
{
	map->images.random = 1;
	map->images.player_im = load_img(mlx, PLAYER_IDLE1);
	map->images.e_asleep_im = load_img(mlx, ENEMY_1);
	map->images.e_awake_im = load_img(mlx, ENEMY_2);
	map->images.floor_im = load_img(mlx, FLOOR);
	map->images.wall_im = load_img(mlx, WALL);
	map->images.door_closed = load_img(mlx, DOOR_CLOSED);
	map->images.door_open = load_img(mlx, DOOR_OPEN);
	map->images.coin_im = load_img(mlx, COIN);
	if (!map->images.player_im || !map->images.floor_im
		|| !map->images.wall_im || !map->images.door_closed
		|| !map->images.door_open || !map->images.coin_im
		|| !map->images.e_asleep_im || !map->images.e_awake_im)
		return (0);
	if (resize_images(map->images, map) == 0)
		return (0);
	if (place_images(mlx, map, &map->images) == 0)
		return (0);
	if (init_player_animation(mlx, map) == 0)
		return (0);
	if (resize_player_animation(map->player_animation, map->tile_size) == 0)
		return (0);
	return (1);
}
