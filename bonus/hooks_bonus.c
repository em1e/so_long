/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:51:17 by vkettune          #+#    #+#             */
/*   Updated: 2024/04/25 18:25:13 by vkettune         ###   ########.fr       */
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

	map = param;
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
	{
		move_player(map, 1, 0);
	}
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
	{
		move_player(map, -1, 0);
	}
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
	{
		move_player(map, 0, 1);
	}
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
	{
		move_player(map, 0, -1);
	}
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
