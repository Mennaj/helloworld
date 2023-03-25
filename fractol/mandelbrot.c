/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:43:36 by mennaji           #+#    #+#             */
/*   Updated: 2023/03/25 04:02:19 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandel_B(t_data *data, int x, int y)
{
	int n = 0;
	while(y < data->ImageHeight){
		double c_im = data->MaxIm - y * (data->MaxIm-data->MinIm) / (data->ImageHeight-1);
		x = 0;
		while(x < data->ImageWidth)
		{
			double  c_re = data->MinRe + x * (data->MaxRe-data->MinRe) / (data->ImageWidth-1);
			double Z_re = c_re, Z_im = c_im;
			bool isInside = true;
			n = 0;
			while(n < data->MaxIterations){
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
				color = n * 255 / data->MaxIterations;// represents the intensity of the color for that pixel
				my_pixel_put(data, x, y, color);
			}
			x++;
		}
		y++;
	}
	return 0;
}
