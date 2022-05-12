/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:55:39 by krozis            #+#    #+#             */
/*   Updated: 2022/05/12 17:57:12 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_game_launch(t_game *game)
{
	//1) Charger affichage
	if (sl_mlx_start(game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	//2) Charger les textures
	if (sl_textures_init(game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	//3) Afficher la map avec les textures
	//sl_display_map(&game->map);
	sl_draw_map(game);
	mlx_loop_hook(game->data.win, &sl_no_event, game);
	mlx_key_hook(game->data.win, &sl_press_touch, game);
	mlx_loop(game->data.mlx);
	// TANT QUE 'partie_en_cours'
	// 	detect movement
	//		FUNCTION: MOVE IN MAP
	//			-> verifie si mouvement possible
	//			-> step++ && move
	//			-> agit sur le nombre de collectibles ou sur le 'partie_en_cours'
	//	affiche resultat
	// ferme l'affichage
	sl_free_end(game);
	return (EXIT_SUCCESS);
}