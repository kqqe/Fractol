/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:52:50 by pben              #+#    #+#             */
/*   Updated: 2019/04/22 21:02:20 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			close_window(void *param)
{
	if (param != NULL)
		exit(-2);
	return (0);
}

int		main(int ac, char **av)

{
	int i;
	draw(i);
	// if (ac != 2)
	// {
	// 	write(1, "non arguments\n", 15);
	//  	return (0);
	// }
	// if (!ft_strcmp(argv[1], "Julia") || !ft_strcmp(argv[1], "Mandelbrot")
	//				|| !ft_strcmp(argv[1], "Ship"))
	//  	draw(i);
	//	else
	//		exit(ft_putstr("Invalid fractol name!\n"));
}