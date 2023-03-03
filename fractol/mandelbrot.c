/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:43:36 by mennaji           #+#    #+#             */
/*   Updated: 2023/03/03 17:11:10 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

//fractal algorithms like the Mandelbrot set
//the algorithm iteratively computes a mathematical formula for a given point on the complex plane,
//and continues to iterate until the formula converges or until a maximum number of iterations is reached
/*int mandel_B(int x, int y)
{
	t_data data;
	int n;
	double minRe;
	double maxRe;
	double minIm;
	double maxIm = minIm+(maxRe-minRe)*HEIGHT/WIDTH;
	double ImageHeight = HEIGHT;
	double ImageWidth = WIDTH;
	int MaxIterations = 60;

	while(y < ImageHeight){
		double c_im = maxIm - y * (maxIm-minIm) / (ImageHeight-1);
		x = 0;
		while(x < ImageWidth)
		{
			double  c_re = minRe + y * (maxIm-minIm) / (ImageWidth-1);
			double Z_re = c_re, Z_im = c_im;
			bool isInside = true;
			n = 0;
			while(n < MaxIterations){
				double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
				if(Z_re2 + Z_im2>4)
				{
					isInside = false;
					break;
				}
				Z_im = 2*Z_re*Z_re + c_im;
				Z_re = Z_re*Z_re - Z_im2 + c_re;
				n++;
			}
			if(isInside){
				int color;
				//n*255, which gives a value between 0 and 255 * "MaxIterations".
				//scales the value down to a range between 0 and 255.
				color = n * 255 / MaxIterations; // represents the intensity of the color for that pixel
				my_mlx_pixel_put(&data, x,y,color);
			}
			x++;
		}
		y++;
	}
	return 0;

}*/
int mandel_B(int x, int y)
{
	t_data data;
	int n;
	double minRe = -2.0;
	double maxRe = 1.0;
	double minIm = -1.5;
	double maxIm = minIm+(maxRe-minRe)*HEIGHT/WIDTH;
	double ImageHeight = HEIGHT;
	double ImageWidth = WIDTH;
	int MaxIterations = 60;

	while(y < ImageHeight){
		double c_im = maxIm - y * (maxIm-minIm) / (ImageHeight-1);
		x = 0;
		while(x < ImageWidth)
		{
			double  c_re = minRe + x * (maxRe-minRe) / (ImageWidth-1);
			double Z_re = c_re, Z_im = c_im;
			bool isInside = true;
			n = 0;
			while(n < MaxIterations){
				double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
				if(Z_re2 + Z_im2>4)
				{
					isInside = false;
					break;
				}
				Z_im = 2*Z_re*Z_im + c_im;
				Z_re = Z_re2 - Z_im2 + c_re;
				n++;
			}
			if(isInside){
				int color;
				//n*255, which gives a value between 0 and 255 * "MaxIterations".
				//scales the value down to a range between 0 and 255.
				color = n * 255 / MaxIterations; // represents the intensity of the color for that pixel
				my_mlx_pixel_put(&data, x,y,color);
			}
			x++;
		}
		y++;
	}
	return 0;
}
// (x, y) is the location at witch pixel is to be put
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
