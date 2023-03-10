/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:36:22 by mennaji           #+#    #+#             */
/*   Updated: 2023/03/10 19:31:47 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	return 0;
}

// fuction to set the starting value for julia fractal based on user input
// function to generate and display julia fractal
// function to draw lines on window using the DDA ALGORITHM  (digital differential analyzer)
// function to initialize the para needed for tdrawing the mandelbrot set int the image
// function to initialize the para needed for tdrawing the julia set set int the image
//function is used to select which fractal set to draw based on the command-line arguments provided to the program.int fract_select(int argc, char **argv, t_d *d)
//function is used to determine which fractal set to draw based on the "fractol" variable in the "t_d" struct, which is set by the "fract_select
//function handles various key presses for controlling the fractals displayed on the screen
//the function zoom hook
//function mouse hook for the fractol project
//function to update the display of the fractal whenever the user performs an action that requires redrawing the image, such as zooming, panning, or changing the color scheme.
//
