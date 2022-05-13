/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:55:39 by krozis            #+#    #+#             */
/*   Updated: 2022/05/13 16:39:49 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_move_possible(t_game *game, int key);

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
	if (key == XK_W || key == XK_S || key == XK_A || key == XK_D)
		sl_move_possible(game, key);
	if (key == XK_w || key == XK_s || key == XK_a || key == XK_d)
		sl_move_possible(game, key);
	return (EXIT_SUCCESS);
}

static void	sl_game_end(t_game *game)
{
	ft_printf(GAME_WIN_MSG);
	mlx_loop_end(game->data.mlx);
}

static int	sl_move(t_game *game, int y, int x)
{
	int	game_state;

	game_state = 0;
	if (game->map.tab[game->map.pos_y + y][game->map.pos_x + x] == GROUND)
		game->map.tab[game->map.pos_y][game->map.pos_x] = GROUND;
	else if (game->map.tab[game->map.pos_y + y][game->map.pos_x + x] == COLL)
	{
		game->map.tab[game->map.pos_y][game->map.pos_x] = GROUND;
		game->map.coll -= 1;
	}
	else if (game->map.tab[game->map.pos_y + y][game->map.pos_x + x] == EXIT
		&& game->map.coll)
		return (game_state);
	else if (game->map.tab[game->map.pos_y + y][game->map.pos_x + x] == EXIT)
	{
		game->map.tab[game->map.pos_y][game->map.pos_x] = GROUND;
		game_state = GAME_WIN;
	}
	game->map.pos_y += y;
	game->map.pos_x += x;
	game->map.step++;
	game->map.tab[game->map.pos_y][game->map.pos_x] = PLAYER;
	ft_printf("Step count: %i\n", game->map.step);
	sl_draw_map(game);
	return (game_state);
}

static void	sl_move_possible(t_game *game, int key)
{
	if (key == XK_Up || key == XK_W || key == XK_w)
		if (game->map.tab[game->map.pos_y - 1][game->map.pos_x] != WALL)
			game->game_state = sl_move(game, -1, 0);
	if (key == XK_Down || key == XK_S || key == XK_s)
		if (game->map.tab[game->map.pos_y + 1][game->map.pos_x] != WALL)
			game->game_state = sl_move(game, 1, 0);
	if (key == XK_Left || key == XK_A || key == XK_a)
		if (game->map.tab[game->map.pos_y][game->map.pos_x - 1] != WALL)
			game->game_state = sl_move(game, 0, -1);
	if (key == XK_Right || key == XK_D || key == XK_d)
		if (game->map.tab[game->map.pos_y][game->map.pos_x + 1] != WALL)
			game->game_state = sl_move(game, 0, 1);
	if (game->game_state == GAME_WIN)
		sl_game_end(game);
}

int	sl_game_launch(t_game *game)
{
	if (sl_mlx_start(game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (sl_textures_init(game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	sl_draw_map(game);
	mlx_key_hook(game->data.win, &sl_press_key, game);
	mlx_hook(game->data.win, 33, (1L << 5), &mlx_loop_end, game->data.mlx);
	mlx_loop(game->data.mlx);
	sl_free_end(game);
	return (EXIT_SUCCESS);
}
