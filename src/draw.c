/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:01:48 by pben              #+#    #+#             */
/*   Updated: 2019/04/22 21:51:48 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int   draw(int i)
{
    t_img		*img;
    t_frl		frl;
    char		*s;
    
    if ((img = (t_img *)ft_memalloc(sizeof(t_img))) == NULL)
		exit(0);
    img->mlx_ptr = mlx_init();
	img->win_ptr = mlx_new_window(img->mlx_ptr, WIN, WIN, "Fractol");
    img->img = mlx_new_image(img->mlx_ptr, WIN, WIN);
    s = mlx_get_data_addr(img->img, &img->bts, &img->size_line, &img->endian);
    img->addr = (unsigned int*)s;
    init_value(&frl);
    //what_is_fractol();
    julia(&frl, img);
	//mandelbrod(&frl, img);
    mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
    mlx_hook(img->win_ptr, 2, (1L << 0), hook, (void*)(&frl));
    mlx_loop(img->mlx_ptr);
    return (0);
} 

int     julia(t_frl *frl, t_img *img)
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
				frl->newRe = frl->oldRe * frl->oldRe - frl->oldIm * frl->oldIm + frl->cRe;
				frl->newIm = 2 * frl->oldRe * frl->oldIm + frl->cIm;
				if((frl->newRe * frl->newRe + frl->newIm * frl->newIm) > 4) 
					break;
			}
    		frl->color = 0x100045 + i * 0x070500;
   			img->addr[frl->x + (frl->y * WIN)] = frl->color;
  		}
	}
  return 0;
}

int     mandelbrod(t_frl *frl, t_img *img)
{
	int		i;

	while (frl->y++ < WIN)
	{
		frl->x = 0;
		while (frl->x++ < WIN)
		{
			frl->cRe = 1.5 * (frl->x - WIN / 2) / (0.5 * frl->zoom * WIN) + frl->moveX;
			frl->cIm = (frl->y - WIN / 2) / (0.5 * frl->zoom * WIN) + frl->moveY;
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
    		frl->color = 0x100045 + i * 0x070500;
   			img->addr[frl->x + (frl->y * WIN)] = frl->color;
  		}
	}
  return 0;
}

void		initForMandelbrod(t_frl *frl)
{
			frl->newIm = 0;
			frl->newRe = 0;
			frl->oldIm = 0;
			frl->oldRe = 0;
}
