/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:21:21 by stelie            #+#    #+#             */
/*   Updated: 2022/05/13 14:14:22 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include "libft.h"
# include "sl_error_msg.h"
# include <X11/keysym.h>

# define PIXELS 32
# define WIN_NAME "./so_long"
# define ALLOWED_CHAR "01CEP"
# define GROUND '0'
# define WALL '1'
# define COLL 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define EXT_TYPE ".ber"
# define F_COLL "./textures/collectible.xpm"
# define F_EXIT "./textures/exit.xpm"
# define F_PLAYER "./textures/player.xpm"
# define F_GROUND "./textures/ground.xpm"
# define F_WALL "./textures/wall.xpm"
# define GAME_WIN 777

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
	t_img	collec;
	t_img	exit;
}				t_text;

typedef struct s_map
{
	char	**tab;
	int		row;
	int		clmn;
	int		exit;
	int		coll;
	int		player;
	int		pos_x;
	int		pos_y;
	int		step;
}				t_map;

typedef struct s_game
{
	t_map	map;
	t_data	data;
	t_text	text;
	int		game_state;
}				t_game;

/*
	FUNCTIONS: Game process
*/
int		sl_game_launch(t_game *game);

/*
	FUNCTIONS: Map check and init
*/
int		sl_copy_map(char **av, t_map *map);
void	sl_free_map_tab(t_map *map);
void	sl_resize_map(t_map *map);
int		sl_check_textures(void);
int		sl_check_file(t_game *game, char **file);
int		sl_map_walled(t_map *map);
int		sl_check_items(t_map *map);

/*
	FUNCTIONS: Errors and free
*/
int		sl_print_error(char *s);
int		sl_print_error_free_map(char *msg, t_map *map);
void	sl_free_map_tab(t_map *map);
void	sl_free_end(t_game *game);

/*
	FUNCTIONS: MLX use
*/
int		sl_mlx_start(t_game *game);
int		sl_textures_init(t_game *game);

/*
	FUNCTIONS: Display
*/
void	sl_draw_map(t_game *game);

/*
	DEBUG
*/
void	sl_display_map(t_map *map);

#endif