/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 05:27:32 by mennaji           #+#    #+#             */
/*   Updated: 2023/03/25 05:51:01 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_strcmp(char *s1, char *s1){
	int i;

	i = 0;
	while(s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s1[i]);
}
int ft_isspace(int c){
	if((c >= 9 && c <= 13) || c == ' ')
		return(c);
	return (0);
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
	while(ft_isspace(*str))
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
}
