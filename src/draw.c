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
    // t_img		*img;
    // t_frl		frl;
    // char		*s;
    
    // if ((img = (t_img *)ft_memalloc(sizeof(t_img))) == NULL)
	// 	exit(0);
    // img->mlx_ptr = mlx_init();
	// img->win_ptr = mlx_new_window(img->mlx_ptr, WIN, WIN, "Fractol");
    // img->img = mlx_new_image(img->mlx_ptr, WIN, WIN);
    // s = mlx_get_data_addr(img->img, &img->bts, &img->size_line, &img->endian);
    // img->addr = (unsigned int*)s;
    //init_value(&frl);
    //what_is_fractol();
    //julia(&frl, img);
	//mandelbrod(&frl, img);
	//burnship(&frl, img);

    //if ()
    mlx_put_image_to_window(frl->img->mlx_ptr, frl->img->win_ptr, frl->img->img, 0, 0);
    //mlx_hook(img->win_ptr, 2, (1L << 0), hook, (void*)(&frl));
    mlx_loop(frl->img->mlx_ptr);
    return (0);
} 

void	what_is_fractal(void)//char *av)
{
	t_frl *frl;

	if ((frl = (t_frl *)ft_memalloc(sizeof(t_frl))) == NULL)
		exit(0); 
	init_value(frl);
	init_mlx(frl);
	// if (av[0] == 'j')
		julia(frl);
	// if (av[0] == 'm')
	// 	mandelbrod(&frl);
	// if (av[0] == 'b')
	// 	burnship(&frl);
	free(frl);
}