/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:48:08 by mennaji           #+#    #+#             */
/*   Updated: 2023/03/25 05:53:32 by mennaji          ###   ########.fr       */
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
#define MLX_ERROR 1
# define HEIGHT 800
# define WIDTH 800
# define SIZE 800
# define BLUE       0x10069F
# define RED        0xEF3340
#define COLOR(r, g, b) (((r) << 16) | ((g) << 8) | (b))

typedef struct s_data
{
	/* data */
	void	*img_data;
	void	*mlx;
	void	*mlx_ptr;
	void 	*win_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
	int 	fractol;
	int 	ImageWidth;
    int 	ImageHeight;
    int 	MaxIterations;
	double	MinRe;
    double	MaxRe;
    double	MinIm;
    double	MaxIm;
	double		c_im;
	double		c_re;
	double		Z_re;
	double		Z_im;
	double		Z_re2;
	double		Z_im2;
	double x;
	double y;
	double x0;
	double y0;
	double xtemp;
	int n;
	int god;
	int num;
	int bits;
	int perPixel;
	double move_x;
	double move_y;
	int color;
	int zoom;
	int move;
	int b;
	int pixel_x1;
	int pixel_x2;
	int pixel_y1;
	int pixel_y2;
	float	Re_fractol;
	float	Im_fractol;
	int	MaxIteration;
	double  _Complex c;
	int radius;
	int DpixelRes;

}			t_data;

int 	mandel_B(t_data *img_data, int x, int y);
void	my_pixel_put(t_data *data, int x, int y, int color);
void	julia(t_data *data);
void get_julia_starting_values(t_data *data,  int argc, char** argv);
double ft_strtod(const char *str, char **endptr);
int	ft_isdigit(int arg);
int julia_init(t_data *data);
int mandel_init(t_data *data);
int zoom_hook(int keycode, t_data *data);
int mouse_hook(int keyword, t_data *data);
void ft_move(t_data *data, double dist, char dir);
void ft_zoom(t_data *data);
#endif
