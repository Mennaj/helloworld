/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:43:36 by mennaji           #+#    #+#             */
/*   Updated: 2023/03/05 16:50:53 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandel_B(t_data *img_data, int x, int y, t_fractal *fractal)
{
	int n = 0;
	while(y < fractal->ImageHeight){
		double c_im = fractal->maxIm - y * (fractal->maxIm-fractal->minIm) / (fractal->ImageHeight-1);
		x = 0;
		while(x < fractal->ImageWidth)
		{
			double  c_re = fractal->minRe + x * (fractal->maxRe-fractal->minRe) / (fractal->ImageWidth-1);
			double Z_re = c_re, Z_im = c_im;
			bool isInside = true;
			n = 0;
			while(n < fractal->MaxIterations){
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
				color = n * 255 / fractal->MaxIterations; // represents the intensity of the color for that pixel
				pixel_put(img_data, x, y, color);
			}
			x++;
		}
		y++;
	}
	return 0;
}
int pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	return 0;
}

