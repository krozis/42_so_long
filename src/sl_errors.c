/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:17:27 by krozis            #+#    #+#             */
/*   Updated: 2022/05/11 18:39:23 by krozis           ###   ########.fr       */
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
	ft_printf("\033[31m\n\t%s\033[0m\n", msg);
	return (EXIT_FAILURE);
}
