/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:52:50 by pben              #+#    #+#             */
/*   Updated: 2019/05/29 18:09:05 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int			close_window(void *param)
{
	if (param != NULL)
		exit(-2);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
 		write(1, "non arguments\n", 15);
	  	return (0);
	}
	if (!ft_strcmp(av[1], "j") || !ft_strcmp(av[1], "m") || !ft_strcmp(av[1], "b") || !ft_strcmp(av[1], "t"))
 	 	what_is_fractal(av[1]);
	else
		 exit(write(1,"Invalid fractol name!\n", 23));
 }		