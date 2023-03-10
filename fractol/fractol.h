/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:48:08 by mennaji           #+#    #+#             */
/*   Updated: 2023/03/05 16:40:24 by mennaji          ###   ########.fr       */
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

}			t_data;

typedef struct s_fractal {
    double minRe;
    double maxRe;
    double minIm;
    double maxIm;
    int ImageWidth;
    int ImageHeight;
    int MaxIterations;
} t_fractal;


int mandel_B(t_data *img_data, int x, int y, t_fractal *fractal);
int pixel_put(t_data *data, int x, int y, int color);
int julia_P(t_data *data, float x, float y, int radius, int MaxNumIterations, int max, double _Complex z, double _Complex c);
#endif
