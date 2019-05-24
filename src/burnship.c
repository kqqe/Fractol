/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burnship.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:01:48 by pben              #+#    #+#             */
/*   Updated: 2019/05/24 19:29:24 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int     burnship(t_frl *frl)
{
	int		i;

	while (frl->y++ < WIN)
	{
		frl->x = 0;
		while (frl->x++ < WIN)
		{
    		frl->newRe = 1.5 * (frl->x - WIN / 2) / (0.5 * frl->zoom * WIN) + frl->moveX;
    		frl->newIm = (frl->y - WIN / 2) / (0.5 * frl->zoom * WIN) + frl->moveY;
    		i = 0;
			while (i++ < frl->maxIteration)
   		 	{
				frl->oldRe = frl->newRe;
				frl->oldIm = frl->newIm;
				frl->newRe = fabs(frl->oldRe * frl->oldRe - frl->oldIm * frl->oldIm) + (1.5 * (frl->x - WIN / 2) / (0.5 * frl->zoom * WIN) + frl->moveX);
				frl->newIm = fabs(2 * frl->oldRe * frl->oldIm + ((frl->y - WIN / 2) / (0.5 * frl->zoom * WIN) + frl->moveY));
				if((frl->newRe * frl->newRe + frl->newIm * frl->newIm) > 4) 
					break;
			}
    		frl->color = 0x100045 + i * 0x070500;
   			frl->img->addr[frl->x + (frl->y * WIN)] = frl->color;
  		}
	}
  return 0;
}