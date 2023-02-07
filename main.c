/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:52:05 by mennaji           #+#    #+#             */
/*   Updated: 2023/02/06 13:03:56 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char ft_putchar(char c){
	write(1, &c, 1);
}

void  ft_putstr(char *str){
	int i;

	i = 0;
	while(str[i] != '\0'){
		ft_putchar(str[i]);
		i++;
	}
}
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




