/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:01:48 by pben              #+#    #+#             */
/*   Updated: 2019/05/29 17:40:48 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void      init_value(t_frl *frl)
{
    frl->color = 0x00FF9632;
	frl->cIm = 0.156;//27015;
	frl->cRe = -0.8;//-0.7;
	frl->zoom = 1;
	frl->moveX = 0;
	frl->moveY = 0;  
	frl->x = 0;
	frl->y = 0;
	frl->z = 0;
	frl->maxIteration = 30;
	frl->F = 0;
}

void		init_mlx(t_frl	*frl)
{
	t_img		*img;
    char		*s;
	char 		*m;
    
    if ((img = (t_img *)ft_memalloc(sizeof(t_img))) == NULL)
		exit(0);
    img->mlx_ptr = mlx_init();
	img->win_ptr = mlx_new_window(img->mlx_ptr, WIN, WIN, "Fractol");
    img->img = mlx_new_image(img->mlx_ptr, WIN, WIN);
	img->imgm = mlx_new_image(img->mlx_ptr, 199, 1000);
    s = mlx_get_data_addr(img->img, &img->bts, &img->size_line, &img->endian);
    img->addr = (unsigned int*)s;
	m = mlx_get_data_addr(img->img, &img->bts, &img->size_line, &img->endian);
    img->addrm = (unsigned int*)s;
	frl->img = img;
	//mlx_hook(img->win_ptr, 2, (1L << 0), hook, (void*)(&frl));
	//menu()
}

void	color(int key, t_frl *frl)
{
	if (key == 18)
		frl->color1 = 0x040a01;
	if (key == 19)
		frl->color1 = 0x110000;
	if (key == 20)
		frl->color1 = 0x000a0a;
	if (key == 21)
		frl->color1 = 0x025677799;
	draw(frl);
}
