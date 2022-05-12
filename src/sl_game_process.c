/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:55:39 by krozis            #+#    #+#             */
/*   Updated: 2022/05/12 15:39:17 by krozis           ###   ########.fr       */
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