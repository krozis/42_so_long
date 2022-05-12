/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:04:52 by krozis            #+#    #+#             */
/*   Updated: 2022/05/12 17:56:16 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_print_key(int keycode)
{
	ft_printf("PRESSED : |%i|\n", keycode);
	return (0);
}

int	sl_no_event(void	*ptr)
{
	return (0);
}

int	sl_press_touch(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		mlx_loop_end(game->data.mlx);
	if (keycode == XK_Up)
		ft_printf("UP!\n");
	return (0);
}