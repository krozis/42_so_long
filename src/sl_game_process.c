/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:55:39 by krozis            #+#    #+#             */
/*   Updated: 2022/05/13 13:47:13 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	sl_move_possible(t_game *game, int key);

/*
	To display the map (in console mode):
	sl_display_map(&game->map);
*/	

static int	sl_press_key(int key, t_game *game)
{
	if (key == XK_Escape)
		mlx_loop_end(game->data.mlx);
	if (key == XK_Up || key == XK_Down || key == XK_Left || key == XK_Right)
		sl_move_possible(game, key);
	return (EXIT_SUCCESS);
}

static int	sl_game_end(t_game *game)
{
	ft_printf(GAME_WIN_MSG);
	mlx_loop_end(game->data.mlx);
}

static int	sl_move(t_game *game, int y, int x)
{
	int	game_state;

	game_state = 0;
	game->map.step++;
	if (game->map.tab[game->map.pos_y + y][game->map.pos_x + x] == GROUND)
		game->map.tab[game->map.pos_y][game->map.pos_x] = GROUND;
	else if (game->map.tab[game->map.pos_y + y][game->map.pos_x + x] == COLL)
		game->map.tab[game->map.pos_y][game->map.pos_x] = GROUND;
	else if (game->map.tab[game->map.pos_y + y][game->map.pos_x + x] == EXIT)
	{
		game->map.tab[game->map.pos_y][game->map.pos_x] = GROUND;
		game_state = GAME_WIN;
	}
	game->map.pos_y += y;
	game->map.pos_x += x;
	game->map.tab[game->map.pos_y][game->map.pos_x] = PLAYER;
	ft_printf("Step count: %i\n", game->map.step);
	sl_draw_map(game);
	return (game_state);
}

static t_bool	sl_move_possible(t_game *game, int key)
{
	if (key == XK_Up)
		if (game->map.tab[game->map.pos_y - 1][game->map.pos_x] != WALL
			|| (game->map.tab[game->map.pos_y - 1][game->map.pos_x] == EXIT
			&& game->map.coll == 0))
			game->game_state = sl_move(game, -1, 0);
	if (key == XK_Down)
		if (game->map.tab[game->map.pos_y + 1][game->map.pos_x] != WALL
			|| (game->map.tab[game->map.pos_y + 1][game->map.pos_x] == EXIT
			&& game->map.coll == 0))
			game->game_state = sl_move(game, 1, 0);
	if (key == XK_Left)
		if (game->map.tab[game->map.pos_y][game->map.pos_x - 1] != WALL
			|| (game->map.tab[game->map.pos_y][game->map.pos_x - 1] == EXIT
			&& game->map.coll == 0))
			game->game_state = sl_move(game, 0, -1);
	if (key == XK_Right)
		if (game->map.tab[game->map.pos_y][game->map.pos_x + 1] != WALL
			|| (game->map.tab[game->map.pos_y][game->map.pos_x + 1] == EXIT
			&& game->map.coll == 0))
			game->game_state = sl_move(game, 0, 1);
	if (game->game_state == GAME_WIN)
		sl_game_end(game);
	return (TRUE);
}

int	sl_game_launch(t_game *game)
{
	if (sl_mlx_start(game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (sl_textures_init(game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	sl_draw_map(game);
	mlx_key_hook(game->data.win, &sl_press_key, game);
	mlx_loop(game->data.mlx);
	sl_free_end(game);
	return (EXIT_SUCCESS);
}
