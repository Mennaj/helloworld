/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:36:22 by mennaji           #+#    #+#             */
/*   Updated: 2023/03/25 05:33:54 by mennaji          ###   ########.fr       */
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
int my_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->bits + x * (data->num / 8));
	*(unsigned int*)dst = color;
	return 0;
}

// function to draw lines on window using the DDA ALGORITHM  (digital differential analyzer)
int abs(int n) { return ((n > 0) ? n : (n * (-1))); }

void draw_line(t_data *data)
{
	float dx;
	float dy;
	float steps;

	dx = abs(data->pixel_x2 - data->pixel_x1);
	dy = abs(data->pixel_y2 - data->pixel_y1);
	if(dx>=dy)
		steps = dx;
	else
		steps = dy;
	dx /= steps;
	dy /= steps;
	data->x = data->pixel_x1;
	data->y = data->pixel_y1;
	my_pixel_put(data, data->x, data->y, RED);
	int i = 0;
	while(i < steps)
	{
		if(data->x >= 0 && data->x < WIDTH && data->y >= 0 && data->y < HEIGHT)
			pixel_put(data, data->x, data->y, data->color);
		data->x += dx;
		data->y += dy;
		i++;
	}
	  mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_data, 0, 0);

}

void clear(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	data->img_data = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img_data, &(data->num), &(data->bits), &(data->perPixel));
}

