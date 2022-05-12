/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:01:47 by krozis            #+#    #+#             */
/*   Updated: 2022/05/12 17:49:43 by krozis           ###   ########.fr       */
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

void	sl_free_textures(t_game *game)
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
//	if (game->data.mlx != NULL)
	mlx_destroy_display(game->data.mlx);
	free(game->data.mlx);
	sl_free_map_tab(&game->map);
}
