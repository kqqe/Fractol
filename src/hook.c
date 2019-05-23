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
    if (key == 65307)//53)
		close_window(frl);
    return (0);
}

// void hook_key(int key, t_frl *frl)
// {
//   if (key = )
//   frl->maxIteration +=50;
//   make_fractal() 
// }