/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:21:21 by stelie            #+#    #+#             */
/*   Updated: 2022/05/12 11:24:12 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
//# include "mlx_int.h"
# include "libft.h"
# include "sl_error_msg.h"

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 600
# endif

# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 300
# endif

# define ALLOWED_CHAR "01CEP"
# define GROUND '0'
# define WALL '1'
# define ITEM 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define EXT_TYPE ".ber"

typedef struct s_data
{
	void	*mlx;
	void	*win;
}				t_data;

typedef struct s_img
{
	void	*img;
	int		height;
	int		width;
}				t_img;

typedef struct s_text
{
	t_img	wall;
	t_img	ground;
	t_img	player;
	t_img	collectible;
	t_img	exit;
}				t_text;

typedef struct s_map
{
	int		row;
	int		clmn;
	char	**tab;
	int		exit;
	int		coll;
	int		pos_x;
	int		pos_y;
	int		step;
}				t_map;

typedef struct s_game
{
	t_map	map;
	t_data	data;
	t_img	img;
	t_text	text;
}				t_game;

/*
	FUNCTIONS: Errors
*/
int		sl_print_error(char *s);
int		sl_check_file(t_game *game, char **file);
int		sl_map_walled(t_map *map);

/*
	FUNCTIONS: Map init
*/
//int		sl_map_tab_error(int fd, char *line, t_map *map);
int		sl_copy_map(char **av, t_map *map);
void	sl_free_map_tab(t_map *map);
void	sl_resize_map(t_map *map);

/*
	DEBUG
*/
void	sl_display_map(t_map *map);

#endif