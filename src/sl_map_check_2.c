/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_check_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:32:24 by krozis            #+#    #+#             */
/*   Updated: 2022/05/12 11:49:42 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	sl_check_items_ret(t_map *map)
{
	if (map->coll == 0)
		return (sl_print_error_free_map(ERR_MAP_NO_COLLECTIBLE, map));
	if (map->exit == 0)
		return (sl_print_error_free_map(ERR_MAP_NO_EXIT, map));
	if (map->player != 1)
		return (sl_print_error_free_map(ERR_MAP_NO_PLAYER_POS, map));
	return (EXIT_SUCCESS);
}

int	sl_check_items(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->clmn)
		{
			if (map->tab[i][j] == 'C')
				map->coll++;
			if (map->tab[i][j] == 'E')
				map->exit++;
			if (map->tab[i][j] == 'P')
			{
				map->player++;
				map->pos_x = j;
				map->pos_y = i;
			}
			j++;
		}
		i++;
	}
	return (sl_check_items_ret(map));
}

int	sl_map_walled(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->clmn)
	{
		if (map->tab[0][i] != WALL || map->tab[map->row - 1][i] != WALL)
		{
			sl_free_map_tab(map);
			return (sl_print_error(ERR_MAP_WALLS));
		}
		i++;
	}
	i = 0;
	while (i < map->row)
	{
		if (map->tab[i][0] != WALL || map->tab[i][map->clmn - 1] != WALL)
		{
			sl_free_map_tab(map);
			return (sl_print_error(ERR_MAP_WALLS));
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
