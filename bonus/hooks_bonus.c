/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:51:17 by vkettune          #+#    #+#             */
/*   Updated: 2024/05/19 20:55:42 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	window_input_hook(void *param)
{
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
}

void	key_hooks(mlx_key_data_t keydata, void *param)
{
	t_map	*map;
	int		key;

	map = param;
	key = keydata.key;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move_player(map, 1, 0, key);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move_player(map, -1, 0, key);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		move_player(map, 0, 1, key);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move_player(map, 0, -1, key);
	if (keydata.key == MLX_KEY_SPACE && map->enemy.awake == 1)
		is_enemy(key, map, 1);
}

void	anim_update_hook(void *param)
{
	static double		timer;
	t_map				*map;
	mlx_t				*mlx;

	map = param;
	mlx = map->mlx;
	timer += mlx->delta_time;
	if (timer < (double) DELAY)
		return ;
	timer = 0;
	map = param;
	animate_player(map);
}
