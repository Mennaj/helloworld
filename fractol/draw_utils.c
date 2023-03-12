/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:36:22 by mennaji           #+#    #+#             */
/*   Updated: 2023/03/12 03:38:47 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//calculates the memory address of the pixel that we want to modify.
//The memory address is computed by adding an offset to the base address of the image data
// data->addr is the base address of the image data. It is a pointer to the beginning of the image buffer.
// y * data->line_length is the offset of the row that contains the pixel. y is the vertical coordinate of the pixel,
//and data->line_length is the number of bytes per row.
// x * (data->bits_per_pixel / 8) is the offset of the pixel within the row. x is the horizontal coordinate of the pixel,
// and data->bits_per_pixel is the number of bits per pixel.
//  We divide by 8 to convert bits to bytes.
int pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	return 0;
}
int	ft_isdigit(int arg)
{
	return (arg >= '0' && arg <= '9');
}

//function to convert int to double
double ft_strtod(const char *str, char **endptr)
{
	double result;
	double factor;
	int sign;
	int exponent;
	int saw_digit;

	result = 0.0;
	factor = 1.0;
	sign = 1;
	exponent = 0;
	saw_digit = 0;
	//skip leading  whitespace
	while(isspace(*str))
		str++;
	//handle optional sign
	if(*str == '+')
		str++;
	else if(*str == '-'){
		sign = -1;
		str++;
	}
	while(ft_isdigit(*str)){
		result = result *10.0 + (*str - 48);
		saw_digit = 1;
		str++;
	}
	//process exponent
	if(saw_digit && (*str == 'e'  || *str == 'E')){
		str++;
		if(*str == '+')
			str++;
		else if(*str == '-')
		{
			sign = -1;
			str++;
		}
		while(ft_isdigit(*str)){
			exponent = exponent * 10 +(*str - 48);
		}
	}
	//calculate the final result
	result *= sign * pow(10.0, exponent);
	result *= factor;
	if(endptr != 0)
		*endptr = (char *)str;
	return result;

// fuction to set the starting value for julia fractal based on user input
void get_julia_starting_values(t_data *data,  int argc, char** argv)
{
	if(data->fractol == 1 && argc == 2){ // 1 indicate that the fractal being rendered is the julia set
		data->reim.c_re = 0;
		data->reim.c_im = -0,8;
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
// function to generate and display julia fractal
int julia_init(t_data *data)
{
	//set the real and imaginary parts of
	//Z (a complex number used in the Julia set algorithm) to zero,
	data->color = 0xFF0000;
	data->reim.Z_re = 0;
	data->reim.Z_im = 0;
	data->reim.Z_re2 = 0;
	data->reim.Z_im2 = 0;
	data->move_x = 0;
	data->move_y = 0;
	julia_set(data);
	return (0);
}
// function to draw lines on window using the DDA ALGORITHM  (digital differential analyzer)
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
	data->reim.Re_fractol = (data->reim.MaxRe  - data->reim.MinRe) / (WIDTH - 1);
	data->reim.Im_fractol = (data->reim.MaxIm - data->reim.MinIm) / (HEIGHT - 1);
	mandel_B(data);
	return 0;
}
// function to initialize the para needed for tdrawing the julia set set int the image
//function is used to select which fractal set to draw based on the command-line arguments provided to the program.int fract_select(int argc, char **argv, t_d *d)
//function is used to determine which fractal set to draw based on the "fractol" variable in the "t_d" struct, which is set by the "fract_select
//function handles various key presses for controlling the fractals displayed on the screen
//the function zoom hook
int zoom_hook(int keycode, t_data *data)
{
	if(keycode == 78)
	{
		data->zoom -= 0.01;
		whichfractal(data);
	}
	else if(keycode == 69)
	{
		data->zoom -+ 0.01;
		whichfractal(data);
	}
	return 0;
}
//function mouse hook for the fractol project
int mouse_hook(int keyword, t_data *data){
	int x;
	int y;
	if(keyword == 5){
		data->god = 1;
		x -= WIDTH/2;
		y -= HEIGHT/2;
		data->zoom -= 0.05;
		ft_zoom(data);

		if(x < 0){
			ft_move(data, (double)x * -1 / WIDTH, 'L');
		}else if(x > 0)
			ft_move(data, (double)x  / HEIGHT, 'R');
		if(y < 0){
			ft_move(data, (double)y * -1 / WIDTH, 'U');
		}else if(x > 0)
			ft_move(data, (double)x  / HEIGHT, 'D');
		whichfractal(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_data, 0, 0);

	}
	if(keyword == 4){
		data->god = -1;
		data->zoom += 0.1;
		ft_zoom(data);
		whichfractal(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_data, 0, 0);

	}
	return 0;
}
void ft_move(t_data *data, double dist, char dir)
{
	//hese lines compute the values of delta_re and delta_im based on the specified direction of movement
	double delta_re;
	double delta_im;

	delta_re = 0;
	delta_im = 0;
	if(dir == 'R') //move right
		delta_re = dist * (data->reim.MaxRe - data->reim.MinRe);
	else if(dir == 'L') //move left
		delta_re = -dist * (data->reim.MaxRe - data->reim.MinRe);
	else if(dir == 'U') //move up
		delta_im = dist * (data->reim.MaxIm - data->reim.MinIm);
	else if(dir == 'D') //move down
		delta_im = -dist *(data->reim.MaxIm - data->reim.MinIm);
//These lines adjust the reim member of the t_d struct to move the fractal image by the specified amount in the specified direction
	data->reim.MaxRe += delta_re;
	data->reim.MinRe += delta_re;
	data->reim.MaxIm += delta_im;
	data->reim.MinIm += delta_im;
	//The values of delta_re and delta_im are added to the minimum and maximum real and imaginary values
	// to update the position of the fractal image.

}
void ft_zoom(t_data *data)
{
	double width = data->reim.MaxRe - data->reim.MinRe;
    double height = data->reim.MaxIm - data->reim.MinIm;

    double newWidth = width / data->zoom;
    double newHeight = height / data->zoom;

    double diffWidth = newWidth - width;
    double diffHeight = newHeight - height;

    double centerR = (data->reim.MaxRe + data->reim.MinRe) / 2.0;
    double centerI = (data->reim.MaxIm + data->reim.MinIm) / 2.0;

    data->reim.MinRe = centerR - (newWidth / 2.0);
    data->reim.MaxRe = centerR + (newWidth / 2.0);

    data->reim.MinIm = centerI - (newHeight / 2.0);
    data->reim.MaxIm = centerI + (newHeight / 2.0);
}

//function to update the display of the fractal whenever the user performs an action that requires redrawing the image, such as zooming, panning, or changing the color scheme.
//
