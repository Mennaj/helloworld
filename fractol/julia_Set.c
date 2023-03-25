/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_Set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:27:11 by mennaji           #+#    #+#             */
/*   Updated: 2023/03/25 00:38:24 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int julia_P(t_data *data, float x, float y, int radius, int MaxNumIterations, int max, double _Complex z, double _Complex c)
// {
// 	// dimensions of the image or the window being drawn to
// 	int X;
// 	int Y;

// 	X = WIDTH;
// 	Y = HEIGHT;
// 	if(cabs(z) > 4){
// 		my_pixel_put(data->mlx_ptr, data->win_ptr, x, y, COLOR(255 - 255 * ((max - MaxNumIterations) * (max - MaxNumIterations)) % (max * max)), 0, 0);
// 		MaxNumIterations = 0;
//     }
// 	/*calculates the distance from the point (x, y) to the center of the image (X/2, Y/2),
// 	 and if it is greater than Y/2, the point is outside the circle centered at (X/2, Y/2) with radius Y/2.*/
// 	if(sqrt(pow((x - X / 2), 2) + pow((x - Y / 2), 2) > Y/2)){
// 		my_pixel_put(data->mlx_ptr, data->win_ptr, x,y);
// 		return (1);
// 	}
// 	if(MaxNumIterations < max)
// 		return (1);
// 	return julia_P(data, x, y, radius, MaxNumIterations-1, max, cpow(z,2) + c, c);
// }

void julia(t_data *data)
{
	int i;

	data->y = -1;
	while(++data->y < HEIGHT)
	{
		data->x = -1;
		while(++data->x < WIDTH)
		{
			data->Z_re = 1.5 * (data->x - WIDTH / 2) / (0,5 * data->zoom * WIDTH) + data->move_x;
			data ->Z_im = (data->y - HEIGHT/2) / (0,5 * data->zoom * HEIGHT) + data->move_y;
			data->n = -1;
			while(++data->n < MAX_ITERATIONS){
				i = julia_algo(data);
				if((data->Z_re * data->Z_re + data->Z_im) > 4){
					my_pixel_put(data, data->x, data->y, (data->color * i / 100));
					break;
				}
			}
		}
	}
}

int julia_algo(t_data *data)
{
	int i;

	i = 0;
	while(i < MAX_ITERATIONS && pow(data->Z_re, 2) + pow(data->Z_im, 2) < 4){
		double Z_re2 = data->Z_re;
		double Z_im2 = data->Z_im;
		data->Z_re = pow(Z_re2, 2) - pow(Z_im2, 2) + data->c_re;
		data->Z_im = 2 * Z_re2 * data->Z_im +data->c_im;
		i++;
	}
	return (i);
}
// void julia_Set(t_data *data)
// {
// 	float x, X;
// 	float y, Y;
// 	int max;

// 	X = 0.0;
// 	Y = 0.0;
// 	max = data->MaxIteration;
// 	x = X/2 - Y/2;
// 	while(x < X/2 + Y/2)
// 	{
// 		x += data->DpixelRes;
// 		y = 0;
// 		while(y < Y)
// 		{
// 			y += data->DpixelRes;
// 			julia_P(data, x, y,data->radius,  data->MaxIteration,max, (2*data->radius*(x-X/2)/Y) + (2*data->radius*(y-Y/2)/Y) * _Complex_I, data->c);//create a complexe number with the real part
// 			/*complex number that represents the starting point for the Julia set iteration,
// 			calculated from the pixel coordinates and the size and position of the window.*/
// 		}
// 	}
// }
