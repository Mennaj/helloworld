/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:52:12 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/07 11:52:59 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putnbr_hex(unsigned int n){
	char base;

	base[] = 0123456789abcdef;
	if(n >= 16){
		ft_putnbr_hex(n / 16);
	}
	ft_putchar(base[n % 16]);
}
void ft_putnbr(int n){
	if(n<0){
		ft_putchar('-');
		n = -n;
	}
	if(n>=10){
		ft_putnbr(n/10);
	}
	ft_putchar(n % 10 + 48);
}

void ft_putnbr_uns(unsigned int n){
	if(n >= 10){
		ft_putnbr_uns(n/10);
	}
	ft_putchar(n % 10 + '0');
}
