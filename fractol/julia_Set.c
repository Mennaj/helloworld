/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_Set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:27:11 by mennaji           #+#    #+#             */
/*   Updated: 2023/03/05 14:37:35 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int julia_P(t_data *data, float x, float y, int radius, int MaxNumIterations, int max, double _Complex z, double _Complex c)
{
	// dimensions of the image or the window being drawn to
	int X;
	int Y;

	X = WIDTH;
	Y = HEIGHT;
	if(cabs(z) > 4){
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, COLOR(255 - 255 * ((max - MaxNumIterations) * (max - MaxNumIterations)) % (max * max), 0, 0));
		MaxNumIterations = 0;
    }
	/*calculates the distance from the point (x, y) to the center of the image (X/2, Y/2),
	 and if it is greater than Y/2, the point is outside the circle centered at (X/2, Y/2) with radius Y/2.*/
	if(sqrt(pow((x - X / 2), 2) + pow((x - Y / 2), 2) > Y/2)){
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x,y,0);
		return (1);
	}
	if(MaxNumIterations < max)
		return (1);
	return julia_P(data, x, y, radius, MaxNumIterations-1, max, cpow(z,2) + c, c);
}

void julia_Set(t_data *data, int MaxIteration, double _Complex c, int radius, int DpixelRes)
{
	float x, X;
	float y, Y;
	int max;

	X = 0.0;
	Y = 0.0;
	max = MaxIteration;
	x = X/2 - Y/2;
	while(x < X/2 + Y/2)
	{
		x += DpixelRes;
		y = 0;
		while(y < Y)
		{
			y += DpixelRes;
			julia_P(data, x, y,radius,  MaxIteration,max, (2*radius*(x-X/2)/Y) + (2*radius*(y-Y/2)/Y) * _Complex_I, c);//create a complexe number with the real part
			/*complex number that represents the starting point for the Julia set iteration,
			calculated from the pixel coordinates and the size and position of the window.*/
		}
	}
}

