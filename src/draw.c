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

#include "fractol.h"

void      init_value(t_frl *frl)
{
    frl->color = 0x00FF9632;
    frl->zx = 1;
	frl->zy = 1;
	frl->cx = 1;
	frl->cy = 1;
	frl->x = 0;
	frl->y = 0;
}

int   draw(int i)
{
    void	*mlx_ptr;
	void	*win_ptr;
    t_img	img;
    t_frl   frl;
    
    mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN, WIN, "Fractol");
    img.img = mlx_new_image(mlx_ptr, WIN, WIN);
    img.addr = (unsigned int *)mlx_get_data_addr(img.img, &img.bts, &img.size_line, &img.endian);
    init_value(&frl);
    //what_is_fractol();
    make_fractal(&frl, &img);
    mlx_put_image_to_window(mlx_ptr, win_ptr, &img.img, 0, 0);
    mlx_hook(win_ptr, 2, 0, hook, (void*)(&frl));
    mlx_loop(mlx_ptr);
    return (0);
} 

int     make_fractal(t_frl *frl, t_img *img)
{
    int iteration = 0;
    int max_iteration = 20;
    int xtemp;

    while(frl->x < WIN)
    {   
        frl->y = 0;
        while(frl->y < WIN)
        {
            xtemp = 0;
            while ((frl->x * frl->x + frl->y * frl->y) <= 4 && (iteration < max_iteration))
            {
                xtemp = frl->x * frl->x - frl->y * frl->y;
                frl->y =2 * frl->x * frl->y;
                frl->x = xtemp;
                iteration++;
            }
            // while ((frl->zx * frl->zx + frl->zy * frl->zy) < 4  &&  (iteration < max_iteration)) 
            // {
            //     xtemp = frl->zx * frl->zx - frl->zy * frl->zy;
            //     frl->zy = 2 * frl->zx * frl->zy  + frl->cy ;
            //     frl->zx = xtemp + frl->cx;
            //     iteration++;
            // }
            img->addr[((int)frl->x * WIN + (int)frl->y)] = frl->color;
            //printf("x= %d, y= %d", frl->x ,frl->y);
            frl->y++;
        }
        frl->x++;
    }
    return (0);
}