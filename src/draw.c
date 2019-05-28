/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:01:48 by pben              #+#    #+#             */
/*   Updated: 2019/05/24 19:57:05 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int   draw(t_frl *frl)
{
	 if (frl->wtf == 'j')
	 	julia(frl);
	 if (frl->wtf == 'm')
	  	mandelbrod(frl);
	 if (frl->wtf == 'b')
	  	burnship(frl);
    mlx_put_image_to_window(frl->img->mlx_ptr, frl->img->win_ptr, frl->img->img, 0, 0);
    mlx_hook(frl->img->win_ptr, 2, (1L << 0), hook, (void*)(frl));
	mlx_hook(frl->img->win_ptr, 6, (1L << 0), mouse_move, (void*)(frl));
    mlx_loop(frl->img->mlx_ptr);
    return (0);
} 

void	what_is_fractal(char *av)
{
	t_frl *frl;

	if ((frl = (t_frl *)ft_memalloc(sizeof(t_frl))) == NULL)
		exit(0); 
	init_value(frl);
	init_mlx(frl);
    //menu()
	if (av[0] == 'j')
		frl->wtf='j';
	if (av[0] == 'm')
		frl->wtf='m';
	if (av[0] == 'b')
		frl->wtf='b';
	printf("%c", frl->wtf);
	draw(frl);
	//free(frl);
}