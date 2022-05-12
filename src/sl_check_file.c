/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:10:50 by krozis            #+#    #+#             */
/*   Updated: 2022/05/12 11:26:49 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	To display the map (in console mode):
*/
	//sl_display_map(&game->map);

static int	sl_check_map_char(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (!ft_incharset(map->tab[i][j], ALLOWED_CHAR))
			{
				sl_free_map_tab(map);
				return (sl_print_error(ERR_MAP_CHAR));
			}
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	sl_check_rectangle(t_map *map)
{
	int		i;
	int		compare;

	compare = 0;
	i = 1;
	while (map->tab[i])
	{
		compare = ft_strlen(map->tab[i - 1]) - ft_strlen(map->tab[i]);
		if (compare != 0)
		{
			sl_free_map_tab(map);
			return (sl_print_error(ERR_MAP_RECTANGLE));
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	sl_get_map_size(char **av, t_map *map)
{
	char	*line;
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (sl_print_error(ERR_EXISTS));
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map->row++;
		free(line);
		line = NULL;
	}
	if (map->row < 3)
	{
		close(fd);
		return (sl_print_error(ERR_MAP_SMALL));
	}
	close(fd);
	return (EXIT_SUCCESS);
}

static int	sl_check_extension(char *file)
{
	size_t	i;

	i = ft_strlen(file);
	if (i < 5 || (strncmp(EXT_TYPE, file + (i - 4), 4)))
		return (sl_print_error(ERR_EXTENSION));
	return (EXIT_SUCCESS);
}

int	sl_check_file(t_game *game, char **av)
{
	if (sl_check_extension(av[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (sl_get_map_size(av, &game->map))
		return (EXIT_FAILURE);
	if (sl_copy_map(av, &game->map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	sl_resize_map(&game->map);
	if (sl_check_map_char(&game->map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (sl_check_rectangle(&game->map) == EXIT_FAILURE
		|| sl_map_walled(&game->map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	sl_free_map_tab(&game->map);
	return (EXIT_SUCCESS);
}
