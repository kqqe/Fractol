/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:37:27 by pben              #+#    #+#             */
/*   Updated: 2019/05/23 18:41:04 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int    hook(int key, void *param)
{
    t_frl		*frl;

	frl = (t_frl*)param;
  printf("key = %d\n", key);
    if (key == 1)//53)
		close_window(frl);
	if (key == 65451)//+
		frl->zoom += 1.0;  
	if (key == 65453)//-
		frl->zoom -= 1.0;
	if (key == 65361)
		frl->moveX = -0.05;
	if (key == 65363)
		frl->moveX = +0.05;
	if (key == 65362)
		frl->moveY = +0.05;
	if (key == 65364)
		frl->moveY = -0.05;
	if (key == 111)
		frl->maxIteration -=50; 
	if (key == 112)
		frl->maxIteration +=50; 

	//printf("zoom  =%f \n", frl->zoom);
	draw(frl);
    return (0);
}

int		mouse_move(int x, int y, void *param)
{

	  t_frl		*frl;

	frl = (t_frl*)param;
	  //printf("%d\n", x);
	//if (frl->jm == 1)
	//{	
    if (x > 200 && x < 1200)
		frl->moveX = ((long double)x - 200) / 1000;
	if (y > 0 && y < 1000)
		frl->moveY = (long double)y / 1000;
	//}
	//julia(frl);
	return (0);
}
// void hook_key(int key, t_frl *frl)
// {
//   if (key = )
//   frl->maxIteration +=50;
//   make_fractal() 
// }
//!!!! CLEAR window
//mlx_destroy_image (pmtx->img->mlx_ptr, pmtx->img->img);
	//pmtx->img->img = mlx_new_image(pmtx->img->mlx_ptr, WINDOW, WINDOW);
	//pmtx->img->addr = mlx_get_data_addr(pmtx->img->img, &pmtx->img->bts, &pmtx->img->size_line, &pmtx->img->endian);// для отрисовки через аддр