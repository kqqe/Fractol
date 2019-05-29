/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:01:48 by pben              #+#    #+#             */
/*   Updated: 2019/05/29 17:41:14 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		initForMandelbrod(t_frl *frl)
{
			frl->newIm = 0;
			frl->newRe = 0;
			frl->oldIm = 0;
			frl->oldRe = 0;
}

int     mandelbrod(t_frl *frl)
{
	int		i;

	frl->y = 0;
	while (frl->y++ < WIN - 1)
	{
		frl->x = 0;
		while (frl->x++ < WIN -1 )
		{
			frl->cRe = 2 * (frl->x - WIN / 2) / (0.5 * frl->zoom * WIN) + frl->moveX;
			frl->cIm = 2 * (frl->y - WIN / 2) / (0.5 * frl->zoom * WIN) + frl->moveY;
    		i = 0;
			initForMandelbrod(frl);
			while (i++ < frl->maxIteration)
   		 	{
				frl->oldRe = frl->newRe;
				frl->oldIm = frl->newIm;
				//zx = oldRE
				//zy = oldIm
				frl->newRe = frl->oldRe * frl->oldRe - frl->oldIm * frl->oldIm + frl->cRe;
				frl->newIm = 2 * frl->oldRe * frl->oldIm + frl->cIm;
				if((frl->newRe * frl->newRe + frl->newIm * frl->newIm) > 4) 
					break;
			}
    		if (i < frl->maxIteration)
			{
				frl->color = 0x100045 + i * frl->color1;
   				frl->img->addr[frl->x + (frl->y * WIN)] = frl->color;
			}
			else
				frl->img->addr[frl->x + (frl->y * WIN)] = 0x000000;
  		}
	}
  return 0;
}



