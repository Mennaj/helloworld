/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:27:25 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/05 12:27:29 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define  FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define TYPES "cspdiuxX"
char ft_putchar(char c);
void  ft_putstr(char *str);
void ft_putnbr(int n);
void ft_putnbr_unsigned_int(unsigned int n);


