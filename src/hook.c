/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:37:27 by pben              #+#    #+#             */
/*   Updated: 2019/05/29 17:48:46 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int    hook(int key, void *param)
{
    t_frl		*frl;

	frl = (t_frl*)param;
    if (key == 53)
		close_window(frl);
	if (key == 69 || key == 4)
		frl->zoom += 1.0;
	if (frl->zoom > 1.0 && (key == 78 || key == 5))
		frl->zoom -= 1.0;
	if (key == 123 || key == 124 || key == 126 || key == 125 || key == 1 || key == 2)
		move_x_y(key, frl);
	if (frl->maxIteration > 10 && key == 31)
		frl->maxIteration -=10; 
	if (key == 35)
		frl->maxIteration +=10;
	if (key == 18 || key == 19 || key == 20 || key == 21)
		color(key, frl);
	if (key == 12 || key == 13 || key == 14 || key == 15)
		wtf_fr(key, frl);
	draw(frl);
    return (0);
}

void	move_x_y(int key, t_frl *frl)
{
	if (key == 1)
		frl->F = 1;
	if (key == 2)
		frl->F = 0;
	if (key == 124)
		frl->moveX -= 0.05;
	if (key == 123)
		frl->moveX += 0.05;
	if (key == 126)
		frl->moveY += 0.05;
	if (key == 125)
		frl->moveY -= 0.05;
}

void	wtf_fr(int key, t_frl *frl)
{
	if (key == 12)
		frl->wtf ='j';
	if (key == 13)
		frl->wtf ='m';
	if (key == 14)
		frl->wtf ='b';
	if (key == 15)
		frl->wtf ='t';
}

int		controlms(int key, int x, int y, void *param)
{
	t_frl		*frl;

	frl = (t_frl*)param;;
	if (key == 4 || key == 5 || key == 1 || key == 2)
		hook(key, frl);
	return (0);
}

int		mouse_move(int x, int y, void *param)
{

	  t_frl		*frl;

	frl = (t_frl*)param;
	if (frl->F == 0)
	{
  		if (x > 200 && x < 1200)
			frl->cRe = ((long double)x - 200) / WIN;
		if (y > 0 && y < 1000)
			frl->cIm = (long double)y / WIN;
		draw(frl);
	}
	return (0);
}
// values->stats.scale *= SCALE;
// values->stats.offx += (x - (WIDTH / 2) + values->stats.offx) * (SCALE - 1);
// values->stats.offy += (y - (HEIGHT / 2) + values->stats.offy) * (SCALE - 1);