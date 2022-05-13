/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_errors_and_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:17:27 by krozis            #+#    #+#             */
/*   Updated: 2022/05/13 13:42:56 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_free_map_tab(t_map *map)
{
	int	i;

	i = 0;
	if (map->tab)
	{
		while (map->tab[i])
		{
			free(map->tab[i]);
			i++;
		}
		free(map->tab);
	}
}

static void	sl_free_textures(t_game *game)
{
	if (game->text.wall.img != NULL)
		mlx_destroy_image(game->data.mlx, game->text.wall.img);
	if (game->text.ground.img != NULL)
		mlx_destroy_image(game->data.mlx, game->text.ground.img);
	if (game->text.player.img != NULL)
		mlx_destroy_image(game->data.mlx, game->text.player.img);
	if (game->text.exit.img != NULL)
		mlx_destroy_image(game->data.mlx, game->text.exit.img);
	if (game->text.collec.img != NULL)
		mlx_destroy_image(game->data.mlx, game->text.collec.img);
}

void	sl_free_end(t_game *game)
{
	if (game->data.win != NULL)
		mlx_destroy_window(game->data.mlx, game->data.win);
	sl_free_textures(game);
	mlx_destroy_display(game->data.mlx);
	free(game->data.mlx);
	sl_free_map_tab(&game->map);
}

int	sl_print_error(char *msg)
{
	if (!ft_strncmp(msg, SL_EXIT_SUCCESS,
			ft_max(ft_strlen(msg), ft_strlen(SL_EXIT_SUCCESS))))
	{
		ft_printf("\033[32m\n\t%s\033[0m\n", msg);
		return (EXIT_SUCCESS);
	}
	ft_printf("\033[31m\n\t%s\033[0m\n", "Error\n");
	ft_printf("\033[31m\n\t%s\033[0m\n", msg);
	return (EXIT_FAILURE);
}

int	sl_print_error_free_map(char *msg, t_map *map)
{
	sl_free_map_tab(map);
	return (sl_print_error(msg));
}
