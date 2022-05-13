/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:04:52 by krozis            #+#    #+#             */
/*   Updated: 2022/05/13 13:19:13 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_print_key(int key, void *ptr)
{
	(void)ptr;
	ft_printf("Key=|%i|\n", key);
	return (EXIT_SUCCESS);
}

int	sl_no_event(void	*ptr)
{
	return (EXIT_SUCCESS);
}

int	sl_press_key(int key, t_game *game)
{
	if (key == XK_Escape)
		mlx_loop_end(game->data.mlx);
	if (key == XK_Up || key == XK_Down || key == XK_Left || key == XK_Right)
		sl_move_possible(game, key);
	return (EXIT_SUCCESS);
}

int	sl_mouse_close(int key, t_game *game)
{
	mlx_loop_end(game->data.mlx);
	return (EXIT_SUCCESS);
}
