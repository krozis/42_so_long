/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:32:17 by krozis            #+#    #+#             */
/*   Updated: 2022/05/12 11:30:05 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static int	sl_map_tab_error(int fd, char *line, t_map *map)
{
	sl_free_map_tab(map);
	free(line);
	close(fd);
	return (EXIT_FAILURE);
}

void	sl_resize_map(t_map *map)
{
	int		i;
	char	*tmp;

	i = 0;
	while (map->tab[i])
	{
		tmp = map->tab[i];
		map->tab[i] = ft_str_cut_before(tmp, '\n');
		free(tmp);
		i++;
	}
}

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

int	sl_copy_map(char **av, t_map *map)
{
	char	*line;
	int		fd;
	int		i;

	i = -1;
		line = NULL;
	map->tab = malloc(sizeof(char *) * (map->row + 1));
	if (map->tab == NULL)
		return (sl_print_error(ERR_MALLOC));
	map->tab[map->row] = NULL;
	fd = open(av[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map->clmn = ft_strlen(line);
		map->tab[++i] = ft_strdup(line);
		if (map->tab[i] == NULL)
			return (sl_map_tab_error(fd, line, map));
		free(line);
		line = NULL;
	}
	close(fd);
	return (EXIT_SUCCESS);
}
