/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:52:16 by stelie            #+#    #+#             */
/*   Updated: 2022/05/13 13:28:33 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game(t_game *game)
{
	game->game_state = 0;
	game->map.tab = NULL;
	game->map.row = 0;
	game->map.clmn = 0;
	game->map.exit = 0;
	game->map.coll = 0;
	game->map.player = 0;
	game->map.pos_x = 0;
	game->map.pos_y = 0;
	game->map.step = 0;
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (sl_print_error(ERR_ARGS));
	init_game(&game);
	if (sl_check_file(&game, av) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (sl_game_launch(&game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (sl_print_error(SL_EXIT_SUCCESS));
}
