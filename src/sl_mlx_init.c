/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:33:17 by krozis            #+#    #+#             */
/*   Updated: 2022/05/12 15:38:51 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_img	sl_textures_load(t_game *game, char *file)
{
	t_img	i;

	i.img = mlx_xpm_file_to_image(game->data.mlx, file, &i.width, &i.height);
	return (i);
}

int	(sl_textures_init(t_game *game))
{
	if (sl_check_textures() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	game->text.collec = sl_textures_load(game, F_COLL);
	game->text.exit = sl_textures_load(game, F_EXIT);
	game->text.player = sl_textures_load(game, F_PLAYER);
	game->text.ground = sl_textures_load(game, F_GROUND);
	game->text.wall = sl_textures_load(game, F_WALL);
	if (game->text.collec.img == NULL || game->text.exit.img == NULL
		|| game->text.player.img == NULL || game->text.ground.img == NULL
		|| game->text.wall.img == NULL)
	{
		sl_free_end(game);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	sl_mlx_start(t_game *game)
{
	game->data.mlx = mlx_init();
	if (game->data.mlx == NULL)
		return (sl_print_error_free_map(ERR_MLX, &game->map));
	game->data.win = mlx_new_window(game->data.mlx, 32 * game->map.clmn,
			32 * game->map.row, WIN_NAME);
	if (game->data.win == NULL)
	{
		mlx_destroy_display(game->data.mlx);
		return (sl_print_error_free_map(ERR_MLX, &game->map));
	}
	return (EXIT_SUCCESS);
}
