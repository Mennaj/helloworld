/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:31:25 by mennaji           #+#    #+#             */
/*   Updated: 2023/03/25 04:32:50 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_window(t_data *data){
	mlx_destroy_image(data->mlx_ptr, data->win_ptr);
	exit(EXIT_SUCCESS);
}
//function handles various key presses for controlling the fractals displayed on the screen
int key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		close_window(data);
	else if (keycode == 125)
	{
		data->b += 1; // down arrow key
		whichfractal(data);
	}
	else if(keycode == 126)
	{
		data->b -= 1;// up arrow key
		wichfractol(data);
	}
	else if(keycode == 123)
	{
		data->move += 0.1;//left arraw key
		wichfractol(data);
	}
	else if(keycode == 124)
	{
		data->move -= 0.1;//right arraw key
		wichfractol(data);
	}
	else
		zoom_hook(keycode, data);

}

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
