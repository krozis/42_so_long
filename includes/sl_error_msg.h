/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error_msg.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:28:23 by krozis            #+#    #+#             */
/*   Updated: 2022/05/12 14:39:24 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_ERROR_MSG_H
# define SL_ERROR_MSG_H
/*
	Errors in map files
*/
# define ERR_EXTENSION "Map file has a wrong extension (*.ber format only).\n"
# define ERR_ARGS "No Argument or too much argument (just one is required).\n"
# define ERR_EXISTS "File does not exist or can't be opened.\n"
# define ERR_MAP_SMALL "Map is too small.\n"
# define ERR_MAP_RECTANGLE "Map is not a rectangle.\n"
# define ERR_MAP_CHAR "Map must only be composed by the following char: 01CEP\n"
# define ERR_MAP_WALLS "Map is not fully surrounded by walls.\n"
# define ERR_MAP_NO_COLLECTIBLE "Map must contain at least one collectible.\n"
# define ERR_MAP_NO_EXIT "Map must contain at least one exit.\n"
# define ERR_MAP_NO_PLAYER_POS "Map must contain ONE initial player position.\n"
# define ERR_NO_TEXTURES "Missing or invalid texture(s) in textures folder.\n"

/*
	Errors in program process
*/
# ifndef EXIT_FAILURE
#  define EXIT_FAILURE 1
# endif
# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS 0
# endif
# define SL_EXIT_SUCCESS "Program ran and shut correcty.\n"
# define MLX_ERROR 1
# define ERR_MAP_OPEN "Map file has not been opened.\n"
# define ERR_MALLOC "Error during dynamic allocation process.\n"
# define ERR_MLX "Error with the MinilibX\n"

#endif