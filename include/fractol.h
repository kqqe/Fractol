/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <pben@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:07:59 by adoyle            #+#    #+#             */
/*   Updated: 2019/05/29 17:41:00 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define ABS(a) (a >= 0) ? a : -a
# define MIN(a, b) a < b ? a : b
# define MAX(a, b) a > b ? a : b
# define WIN 1000
# include "mlx.h"

# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_img
{
	void			*img;
	void			*imgm;
	int				bts;
	int				endian;
	int 			size_line;
	void			*win_ptr;
	void			*mlx_ptr;
	unsigned int	*addr;
	unsigned int	*addrm;
}					t_img;

  typedef struct 	s_frl
  {
	int				color;
	int				color1;
	long double 	zoom;
	long double 	moveX;
	long double		moveY;
	long double 	cRe;
	long double 	cIm;  
	long double		newRe; 
	long double		newIm; 
	long double		oldRe; 
	long double		oldIm;	
	int				x;
	int				y;
	int				z;
	int 			maxIteration;
	char 			wtf;
	int 			F;
	t_img			*img;

  }					t_frl;


int			close_window(void *param);
int  		hook(int key, void *param);
void      	init_value(t_frl *frl);
int   		draw(t_frl *frl);
int     	julia(t_frl *frl);
int     	mandelbrod(t_frl *frl);
void 		initForMandelbrod(t_frl *frl);
int   		burnship(t_frl *frl);
int    		tricorn(t_frl *frl);
void		what_is_fractal(char *av);
void		init_mlx(t_frl	*frl);
int			controlms(int key, int x, int y, void *param);
int			mouse_move(int x, int y, void *param);
void		color(int key, t_frl *frl);
void 		wtf_fr(int key, t_frl *frl);
void		move_x_y(int key, t_frl *frl);
void		menu(t_frl *frl);
void		text(t_frl *frl);


#endif
