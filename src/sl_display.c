/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:57:52 by krozis            #+#    #+#             */
/*   Updated: 2022/05/13 13:20:18 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_draw_items(t_game *game, int x, int y)
{
	if (game->map.tab[y][x] == EXIT)
		mlx_put_image_to_window(game->data.mlx, game->data.win,
			game->text.exit.img, x * PIXELS, y * PIXELS);
	else if (game->map.tab[y][x] == COLL)
		mlx_put_image_to_window(game->data.mlx, game->data.win,
			game->text.collec.img, x * PIXELS, y * PIXELS);
	else if (game->map.tab[y][x] == PLAYER)
		mlx_put_image_to_window(game->data.mlx, game->data.win,
			game->text.player.img, x * PIXELS, y * PIXELS);
}

void	sl_draw_bg(t_game *game, int x, int y)
{
	if (game->map.tab[y][x] == WALL)
		mlx_put_image_to_window(game->data.mlx, game->data.win,
			game->text.wall.img, x * PIXELS, y * PIXELS);
	else
		mlx_put_image_to_window(game->data.mlx, game->data.win,
			game->text.ground.img, x * PIXELS, y * PIXELS);
}

void	sl_draw_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.clmn)
	{
		y = 0;
		while (y < game->map.row)
		{
			sl_draw_bg(game, x, y);
			sl_draw_items(game, x, y);
			y++;
		}
		x++;
	}
}
