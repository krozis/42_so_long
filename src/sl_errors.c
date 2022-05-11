/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krozis <krozis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:17:27 by krozis            #+#    #+#             */
/*   Updated: 2022/05/11 18:26:19 by krozis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_print_error(char *error_type)
{
	ft_printf("\033[31m\n\t%s\033[0m\n", error_type);
	return (ERROR);
}