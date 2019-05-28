/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:01:48 by pben              #+#    #+#             */
/*   Updated: 2019/05/28 18:56:18 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int     julia(t_frl *frl)
{
	int		i;
	
	frl->y = 0;
	while (frl->y++ < WIN - 1)
	{
		frl->x = 0;
		while (frl->x++ < WIN -1 )
		{
			frl->newRe = 2 *(frl->x - WIN / 2) / (0.5 * frl->zoom * WIN) + frl->moveX;
			frl->newIm = 2 *(frl->y - WIN / 2) / (0.5 * frl->zoom * WIN) + frl->moveY;
    		i = 0;
			while (i++ < frl->maxIteration)
   		 	{
				frl->oldRe = frl->newRe;
				frl->oldIm = frl->newIm;
				frl->newRe = frl->oldRe * frl->oldRe - frl->oldIm * frl->oldIm + frl->cRe;
				frl->newIm = 2 * frl->oldRe * frl->oldIm + frl->cIm;
				if((frl->newRe * frl->newRe + frl->newIm * frl->newIm) > 4) 
					break;
			}
    		frl->color = 0x100045 + i * 0x070500;
   			frl->img->addr[frl->x + (frl->y * WIN)] = frl->color;
  		}
	}
  return 0;
}
