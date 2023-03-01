/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:48:08 by mennaji           #+#    #+#             */
/*   Updated: 2023/03/01 13:53:11 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>
# define HEIGHT 500
# define WIDTH 500

typedef struct s_data
{
	/* data */
	int *img_data;
	int height;
	int width;
}			t_data;

int mandel_B(int x, int y);
void putpixel(int x, int y, int color, t_data *data);
#endif
