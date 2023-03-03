/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:50:31 by mennaji           #+#    #+#             */
/*   Updated: 2023/03/03 18:26:10 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(void)
{
	t_data data;

	data.mxl = mlx_init();
	//return a pointer to the window we have just created
	data.mxl_win  = mlx_new_window(data.mxl, WIDTH, HEIGHT, "WELCOME TO MY WORLD");
	data.img = (void *)mxl_new_image(data.mxl, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	my_mlx_pixel_put(&data, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(data.mxl, data.mxl_win, data.img, 0, 0);
	mxl_loop(data.mxl);
}



