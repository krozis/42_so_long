/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelie <stelie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:52:16 by stelie            #+#    #+#             */
/*   Updated: 2022/04/13 15:56:31 by stelie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include "so_long.h"

int	so_long(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}

int	main(void)
{
	so_long();
	return (0);
}
