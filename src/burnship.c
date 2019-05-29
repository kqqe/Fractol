/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burnship.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:01:48 by pben              #+#    #+#             */
/*   Updated: 2019/05/29 17:02:13 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int     burnship(t_frl *frl)
{
	int		i;

	frl->y = 0;
	while (frl->y++ < WIN - 1)
	{
		frl->x = 0;
		while (frl->x++ < WIN - 1)
		{	
			long double x = 2 * (frl->x - WIN / 2) / (0.5 * frl->zoom * WIN) + frl->moveX;
			long double y = 2 *(frl->y - WIN / 2) / (0.5 * frl->zoom * WIN) + frl->moveY;
    		frl->newRe = x;
    		frl->newIm = y;
    		i = 0;
			while (i++ < frl->maxIteration)
   		 	{
				frl->oldRe = frl->newRe;
				frl->oldIm = frl->newIm;
				frl->newRe = fabsl(frl->oldRe * frl->oldRe - frl->oldIm * frl->oldIm + x);
				frl->newIm = fabsl(2 * frl->oldRe * frl->oldIm) + y;
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