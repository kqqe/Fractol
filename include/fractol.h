/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:07:59 by adoyle            #+#    #+#             */
/*   Updated: 2019/05/23 18:43:34 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define ABS(a) (a >= 0) ? a : -a
# define MIN(a, b) a < b ? a : b
# define MAX(a, b) a > b ? a : b
# define WIN  700
# include "mlx.h"

# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_img
{
	void			*img;
	int				bts;
	int				endian;
	int 			size_line;
	void			*win_ptr;
	void			*mlx_ptr;
	unsigned int	*addr;
}					t_img;

  typedef struct 	s_frl
  {
	int				color;
	double 			zoom;
	double 			moveX;
	double			moveY;
	double 			cRe;
	double 			cIm;  
	double			newRe; 
	double			newIm; 
	double			oldRe; 
	double			oldIm;	
	int				x;
	int				y;
	int 			maxIteration;
	t_img			*img;

  }					t_frl;


int			close_window(void *param);
int  		hook(int key, void *param);
void      	init_value(t_frl *frl);
int   		draw(int i);
int     	julia(t_frl *frl, t_img *img);
int     	mandelbrod(t_frl *frl, t_img *img);
void 		initForMandelbrod(t_frl *frl);
int   		burnship(t_frl *frl, t_img *img);

#endif
