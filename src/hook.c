/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:37:27 by pben              #+#    #+#             */
/*   Updated: 2019/05/28 20:05:26 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int    hook(int key, void *param)
{
    t_frl		*frl;

	frl = (t_frl*)param;
  //printf("key = %d\n", key);
    if (key == 53)//53)
		close_window(frl);
	if (frl->zoom > 0.9 &&  (key == 69 || key ==4))//65451)//+
		frl->zoom += 1.0;  
	if (frl->zoom > 0.9 && (key == 78 || key == 5))//65453)//-
		frl->zoom -= 1.0;
	if (key == 123)//65361)
		frl->moveX -= 0.05;
	if (key == 124)//65363)
		frl->moveX += 0.05;
	if (key == 126)//65362)
		frl->moveY += 0.05;
	if (key == 125)//65364)
		frl->moveY -= 0.05;
	if (key == 31)//111)
		frl->maxIteration -=10; 
	if (key == 35)//112)
		frl->maxIteration +=10; 

	//printf("moveX  =%Lf \n", frl->moveX);
	draw(frl);
    return (0);
}


int		controlms(int key, int x, int y, void *param)
{
	t_frl		*frl;

	frl = (t_frl*)param;;
	if (key == 4 || key == 5)
		hook(key, frl);
	return (0);
}

int		mouse_move(int x, int y, void *param)
{

	  t_frl		*frl;

	frl = (t_frl*)param;
  if (x > 200 && x < 1200)
		frl->cRe = ((long double)x - 200) / WIN;
	if (y > 0 && y < 1000)
		frl->cIm = (long double)y / WIN;
	draw(frl);
	return (0);
}
//!!!! CLEAR window
//mlx_destroy_image (pmtx->img->mlx_ptr, pmtx->img->img);
	//pmtx->img->img = mlx_new_image(pmtx->img->mlx_ptr, WIN, WIN);
	//pmtx->img->addr = mlx_get_data_addr(pmtx->img->img, &pmtx->img->bts, &pmtx->img->size_line, &pmtx->img->endian);// для отрисовки через аддр