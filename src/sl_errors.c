/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:17:27 by krozis            #+#    #+#             */
/*   Updated: 2022/05/12 11:41:05 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	sl_display_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->tab[i])
	{
		ft_printf("|%s|%i\n", map->tab[i], ft_strlen(map->tab[i]));
		i++;
	}
}
