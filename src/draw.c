/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:01:48 by pben              #+#    #+#             */
/*   Updated: 2019/05/29 18:08:23 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int   draw(t_frl *frl)
{
	menu(frl);
	mlx_clear_window(frl->img->mlx_ptr, frl->img->win_ptr);
	if (frl->wtf == 'j')
	{
	 	julia(frl);
	}
	if (frl->wtf == 'm')
	  	mandelbrod(frl);
	if (frl->wtf == 'b')
	  	burnship(frl);
	if (frl->wtf == 't')
	  	tricorn(frl); 
	text(frl);
    mlx_put_image_to_window(frl->img->mlx_ptr, frl->img->win_ptr, frl->img->img, 200, 0);
	mlx_put_image_to_window(frl->img->mlx_ptr, frl->img->win_ptr, frl->img->imgm, 0, 0);
    mlx_hook(frl->img->win_ptr, 2, (1L << 0), hook, (void*)(frl));
	mlx_hook(frl->img->win_ptr, 6, (1L << 0), mouse_move, (void*)(frl));
	mlx_mouse_hook(frl->img->win_ptr, controlms, (void*)(frl));
    mlx_loop(frl->img->mlx_ptr);
    return (0);
} 

void		menu(t_frl *frl)
{
	int i;

	i = 0;
	while(i < 199 * 1000)
	{
		frl->img->addrm[i] = 0x303040;
		i++;
	}
}

void		text(t_frl *frl)
{
	mlx_string_put(frl->img->mlx_ptr, frl->img->win_ptr, 10, 10, 0xAF5555, "Menu:");
	mlx_string_put(frl->img->mlx_ptr, frl->img->win_ptr, 10, 30, 0xAF5555, "Switch Fractal:");
	mlx_string_put(frl->img->mlx_ptr, frl->img->win_ptr, 10, 50, 0xAF5555, "q - Mandelbrot");
	mlx_string_put(frl->img->mlx_ptr, frl->img->win_ptr, 10, 70, 0xAF5555, "w - Julia");
	mlx_string_put(frl->img->mlx_ptr, frl->img->win_ptr, 10, 90, 0xAF5555, "e - Burningship");
	mlx_string_put(frl->img->mlx_ptr, frl->img->win_ptr, 10, 110, 0xAF5555, "r - Tricorn");
	mlx_string_put(frl->img->mlx_ptr, frl->img->win_ptr, 10, 120, 0xAF5555, "__________________");
	mlx_string_put(frl->img->mlx_ptr, frl->img->win_ptr, 10, 140, 0xAF5555, "Controls:");
	mlx_string_put(frl->img->mlx_ptr, frl->img->win_ptr, 10, 160, 0xAF5555, "Move: < > ^ v");
	mlx_string_put(frl->img->mlx_ptr, frl->img->win_ptr, 10, 180, 0xAF5555, "Zoom: + -");
	mlx_string_put(frl->img->mlx_ptr, frl->img->win_ptr, 10, 200, 0xAF5555, "Zoom: wheel mouse");
	mlx_string_put(frl->img->mlx_ptr, frl->img->win_ptr, 10, 220, 0xAF5555, "Iteration: * /");
	mlx_string_put(frl->img->mlx_ptr, frl->img->win_ptr, 10, 230, 0xAF5555, "__________________");
	mlx_string_put(frl->img->mlx_ptr, frl->img->win_ptr, 10, 250, 0xAF5555, "Mouse mode: m");
	mlx_string_put(frl->img->mlx_ptr, frl->img->win_ptr, 10, 260, 0xAF5555, "__________________");
	mlx_string_put(frl->img->mlx_ptr, frl->img->win_ptr, 10, 280, 0xAF5555, "Colors:");
	mlx_string_put(frl->img->mlx_ptr, frl->img->win_ptr, 10, 300, 0xAF5555, "1: Green");
	mlx_string_put(frl->img->mlx_ptr, frl->img->win_ptr, 10, 320, 0xAF5555, "2: Red");
	mlx_string_put(frl->img->mlx_ptr, frl->img->win_ptr, 10, 340, 0xAF5555, "3: Blue");
	mlx_string_put(frl->img->mlx_ptr, frl->img->win_ptr, 10, 360, 0xAF5555, "4: Psyho");
}

void	what_is_fractal(char *av)
{
	t_frl *frl;

	if ((frl = (t_frl *)ft_memalloc(sizeof(t_frl))) == NULL)
		exit(0); 
	init_value(frl);
	init_mlx(frl);
	if (av[0] == 'j')
		frl->wtf='j';
	if (av[0] == 'm')
		frl->wtf='m';
	if (av[0] == 'b')
		frl->wtf='b';
	if (av[0] == 't')
		frl->wtf='t';
	draw(frl);
	//free(frl);
}