/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:52:16 by stelie            #+#    #+#             */
/*   Updated: 2022/05/11 19:42:34 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game(t_game *game)
{
	game->map.row = 0;
	game->map.clmn = 0;
	game->map.coll = 0;
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
	return (sl_print_error(SL_EXIT_SUCCESS));
}

/*
int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (MLX_ERROR);
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "So_long (and thanks for all the fish)");
	if (mlx_ptr == NULL)
	{
		free(mlx_ptr);
		return (MLX_ERROR);
	}
	img = mlx_new_image(mlx_ptr, 1920, 1080);
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
*/