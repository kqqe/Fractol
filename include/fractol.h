/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:07:59 by adoyle            #+#    #+#             */
/*   Updated: 2019/04/22 21:17:53 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define ABS(a) (a >= 0) ? a : -a
# define MIN(a, b) a < b ? a : b
# define MAX(a, b) a > b ? a : b
# define WIN  100
# include "mlx.h"

# include "libft.h"
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
	double			zx;
	double			zy;
	double 			cx;
	double			cy;
	int				x;
	int				y;

  }					t_frl;

int			close_window(void *param);
int  		hook(int key, void *param);
void      	init_value(t_frl *frl);
int   		draw(int i);
int     	make_fractal(t_frl *frl, t_img *img);

#endif
