/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:50:31 by mennaji           #+#    #+#             */
/*   Updated: 2023/03/04 17:32:53 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(void)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	//return a pointer to the window we have just created
	data->mlx_ptr  = mlx_new_window(data->mlx, WIDTH, HEIGHT, "WELCOME TO MY WORLD");
	data->img_data = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img_data, &data->bits_per_pixel, &data->line_length, &data->endian);
	pixel_put(data, 5, 5, 0x00ff0000);
	mlx_put_image_to_window(data->mlx, data->mlx_ptr, data->img_data, 0, 0);
	mlx_loop(data->mlx);
	free(data);
}



