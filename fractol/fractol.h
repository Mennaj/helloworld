/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:48:08 by mennaji           #+#    #+#             */
/*   Updated: 2023/03/12 01:44:34 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
#include  <stdbool.h>
#include <complex.h>
#include <string.h>
# include "minilibx_mms_20191025_beta/mlx.h"
# define MAX_ITERATIONS 1000
# define HEIGHT 800
# define WIDTH 800
# define SIZE 800
# define BLUE       0x10069F
# define RED        0xEF3340
#define COLOR(r, g, b) ((r) << 16 | (g) << 8 | (b))

typedef struct s_data
{
	/* data */
	void	*img_data;
	void	*mlx;
	void	*mlx_ptr;
	void	*win_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
	int 	fractol;
	double x;
	double y;
	int n;
	double move_x;
	double move_y;
	int color;
    int ImageWidth;
    int ImageHeight;
    int MaxIterations;
	int zoom;
	t_complex	reim;

}			t_data;

typedef struct s_complex
{
	double		c_im;
	double		c_re;
	double		Z_re;
	double		Z_im;
	double		Z_re2;
	double		Z_im2;
	double	MinRe;
    double	MaxRe;
    double	MinIm;
    double	MaxIm;
	float	Re_fractol;
	float	Im_fractol;
}			t_complex;

int mandel_B(t_data *img_data, int x, int y, t_fractal *fractal);
int pixel_put(t_data *data, int x, int y, int color);
int julia_P(t_data *data, float x, float y, int radius, int MaxNumIterations, int max, double _Complex z, double _Complex c);
void get_julia_starting_values(t_data *data,  int argc, char** argv);
#endif
