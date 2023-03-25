/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 00:36:16 by mennaji           #+#    #+#             */
/*   Updated: 2023/03/25 04:06:26 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// function to initialize the para needed for tdrawing the mandelbrot set int the image
int mandel_init(t_data *data)
{
	//set initial values for various variable in the struct
	data->n = 0;
	data->x = 0;
	data->y = 0;
	data->move_x = 0;
	data->move_y = 0;
	data->color = 0x0000FF;

	//calculate the re_factor and im_factor based on max  and min values
	data->Re_fractol = (data->MaxRe  - data->MinRe) / (WIDTH - 1);
	data->Im_fractol = (data->MaxIm - data->MinIm) / (HEIGHT - 1);
	mandel_B(data, data->x, data->y);
	return 0;
}

// function to generate and display julia fractal
int julia_init(t_data *data)
{
	//set the real and imaginary parts of
	//Z (a complex number used in the Julia set algorithm) to zero,
	data->color = 0xFF0000;
	data->Z_re = 0;
	data->Z_im = 0;
	data->Z_re2 = 0;
	data->Z_im2 = 0;
	data->move_x = 0;
	data->move_y = 0;
	julia_Set(data);
	return (0);
}

// fuction to set the starting value for julia fractal based on user input
void get_julia_starting_values(t_data *data,  int argc, char** argv)
{
	if(data->fractol == 1 && argc == 2){ // 1 indicate that the fractal being rendered is the julia set
		data->c_re = 0;
		data->c_im = -0,8;
		return ;
	}
	if(argc < 4)
	{
		printf("Error: Missing argument\n");
		return ;
	}
	char *endptr;
	double c_re = strtod(argv[2], &endptr);
	if(*endptr != '\0' || isnan(c_re) || fabs(c_re) > 2,0){
		printf("Error: invalid argument c_re = %s\n", argv[2]);
		return ;
	}
	double c_im = strtod(argv[3], &endptr);
	if(*endptr != '\0' || isnan(c_im) || fabs(c_im) > 2,0){
		printf("Error: invalid argument c_re = %s\n", argv[3]);
		return ;
	}
}

//function is used to select which fractal set to draw based on the command-line arguments provided to the program.int fract_select(int argc, char **argv, t_d *d)
int fract_select(int argc, char **argv, t_data *data){
	(void)argc;
	if(ft_strcmp(argv[1], "mandelbrot") == 0)
		data->fractol = 0;
	else if(ft_strcmp(argv[1], "julia") == 1)
		data->fractol = 1;
	return (1);
}

int wichfractol(t_data *data)
{
	if(data->fractol == 0)
		mandel_init(data);
	else if(data->fractol == 1)
		julia_init(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_data, 0, 0);
}
