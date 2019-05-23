/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:01:48 by pben              #+#    #+#             */
/*   Updated: 2019/05/23 18:38:58 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void      init_value(t_frl *frl)
{
    frl->color = 0x00FF9632;
	//frl->cIm = 0.156;//27015;
	//frl->cRe = -0.8;//-0.7;
	// frl->newIm = 0;
	// frl->newRe = 0;
	// frl->oldIm = 0;
	// frl->oldRe = 0;
	frl->zoom = 1;
	frl->moveX = 0;
	frl->moveY = 0;  
	frl->x = 0;
	frl->y = 0;
	frl->maxIteration = 300;
}

