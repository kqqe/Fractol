/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:01:48 by pben              #+#    #+#             */
/*   Updated: 2019/05/23 18:40:39 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int   draw(int i)
{
    t_img		*img;
    t_frl		frl;
    char		*s;
    
    if ((img = (t_img *)ft_memalloc(sizeof(t_img))) == NULL)
		exit(0);
    img->mlx_ptr = mlx_init();
	img->win_ptr = mlx_new_window(img->mlx_ptr, WIN, WIN, "Fractol");
    img->img = mlx_new_image(img->mlx_ptr, WIN, WIN);
    s = mlx_get_data_addr(img->img, &img->bts, &img->size_line, &img->endian);
    img->addr = (unsigned int*)s;
    init_value(&frl);
    //what_is_fractol();
    //julia(&frl, img);
	//mandelbrod(&frl, img);
	burnship(&frl, img);
    mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
    mlx_hook(img->win_ptr, 2, (1L << 0), hook, (void*)(&frl));
    mlx_loop(img->mlx_ptr);
    return (0);
} 
