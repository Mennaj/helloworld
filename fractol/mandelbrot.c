/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:43:36 by mennaji           #+#    #+#             */
/*   Updated: 2023/03/01 14:22:08 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//fractal algorithms like the Mandelbrot set
//the algorithm iteratively computes a mathematical formula for a given point on the complex plane,
//and continues to iterate until the formula converges or until a maximum number of iterations is reached
int mandel_B(int x, int y)
{
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
				putpixel(x,y,color, data);
			}
			x++;
		}
		y++;
	}
	return 0;

}
// (x, y) is the location at witch pixel is to be put
void putpixel(int x, int y, int color, t_data *data)
{
	   int index;
		if(x>=0 && y>=0 && x<data->width && y<data->height)
		{
			index = y * data->width + x;
			data->img_data[index] = color;
		}
}
