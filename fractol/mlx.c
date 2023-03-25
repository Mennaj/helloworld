/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 05:09:56 by mennaji           #+#    #+#             */
/*   Updated: 2023/03/25 05:25:42 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//function to create a new window , new image in the window  with the same demensions
//also gets the address of the image data
//it  sets up the graphical  envireronment 
int mlx_GraEnv(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if(data->mlx_ptr == NULL)
		return(MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "WELCOME TO MY WORLD!");
	data->img_data = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img_data, &data->num, &data->bits, &data->perPixel);
	if(data->mlx_ptr == NULL){
		free(data->mlx_ptr);
		return(MLX_ERROR);
	}
	RETURN (0);
}
void ft_zoom(t_data *data)
{
	double width = data->MaxRe - data->MinRe;
    double height = data->MaxIm - data->MinIm;

    double newWidth = width / data->zoom;
    double newHeight = height / data->zoom;

    double diffWidth = newWidth - width;
    double diffHeight = newHeight - height;

    double centerR = (data->MaxRe + data->MinRe) / 2.0;
    double centerI = (data->MaxIm + data->MinIm) / 2.0;

    data->MinRe = centerR - (newWidth / 2.0);
    data->MaxRe = centerR + (newWidth / 2.0);

    data->MinIm = centerI - (newHeight / 2.0);
    data->MaxIm = centerI + (newHeight / 2.0);
}
void ft_move(t_data *data, double dist, char dir)
{
	//hese lines compute the values of delta_re and delta_im based on the specified direction of movement
	double delta_re;
	double delta_im;

	delta_re = 0;
	delta_im = 0;
	if(dir == 'R') //move right
		delta_re = dist * (data->MaxRe - data->MinRe);
	else if(dir == 'L') //move left
		delta_re = -dist * (data->MaxRe - data->MinRe);
	else if(dir == 'U') //move up
		delta_im = dist * (data->MaxIm - data->MinIm);
	else if(dir == 'D') //move down
		delta_im = -dist *(data->MaxIm - data->MinIm);
//These lines adjust the reim member of the t_d struct to move the fractal image by the specified amount in the specified direction
	data->MaxRe += delta_re;
	data->MinRe += delta_re;
	data->MaxIm += delta_im;
	data->MinIm += delta_im;
	//The values of delta_re and delta_im are added to the minimum and maximum real and imaginary values
	// to update the position of the fractal image.

}
