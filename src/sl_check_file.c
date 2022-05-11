/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:10:50 by krozis            #+#    #+#             */
/*   Updated: 2022/05/11 19:44:07 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	sl_check_rectangle();

static int	sl_check_extension(char *file)
{
	size_t i;

	i = ft_strlen(file);
	if (i < 5 || (strncmp(EXT_TYPE, file + (i - 4), 4)))
		return (sl_print_error(ERR_EXTENSION));
	return (EXIT_SUCCESS);
}

int	sl_check_file(t_game *game, char **av)
{
	int		fd;


	if (sl_check_extension(av[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (sl_print_error(ERR_EXISTS));
	close(fd);
	return (EXIT_SUCCESS);
}
