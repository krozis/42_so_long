/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:28:23 by krozis            #+#    #+#             */
/*   Updated: 2022/05/11 16:41:34 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_ERROR_MSG_H
# define SL_ERROR_MSG_H

/*
	Errors in map file
*/
# define ERR_EXTENSION "Map file has a wrong extension.\n"
# define ERR_ARGS "No Argument or too much argument (just one is required).\n"
# define ERR_EXISTS "File does not exist.\n"
# define ERR_MAP_SMALL "Map is too small.\n"
# define ERR_MAP_RECTANGLE "Map is not a rectangle.\n"
# define ERR_MAP_WALLS "Map is not fully surrounded by walls.\n"
# define ERR_MAP_NO_COLLECTIBLE "Map must contain at least one collectible.\n"
# define ERR_MAP_NO_EXIT "Map must contain at least one exit.\n"
# define ERR_MAP_NO_PLAYER_POS "Map must contain one initial player position.\n"

/*
	Errors in program process
*/
# define ERR_MAP_OPEN "Map file has not been opened.\n"

#endif