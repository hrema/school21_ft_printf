/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:27:31 by hrema             #+#    #+#             */
/*   Updated: 2020/07/14 14:01:14 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	conditions(unsigned int x, char type, char *c)
{
	if (type == 'x')
		*c = 'a';
	else
		*c = 'A';
	if (x == 0)
		ft_putchar_fd('0', 1);
}

int			print_hex_number(unsigned int x, char type)
{
	int		temp;
	char	c;
	int		len;
	char	*hex_number;

	len = len_hex_number(x);
	if (!(hex_number = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	hex_number[len] = '\0';
	conditions(x, type, &c);
	while (x > 0)
	{
		len--;
		temp = x % 16;
		if (temp < 10)
			hex_number[len] = temp + '0';
		else
			hex_number[len] = c + (temp - 10);
		x /= 16;
	}
	ft_putstr_fd(hex_number, 1);
	free(hex_number);
	return (0);
}

void		ft_put_u_number(unsigned int number, int fd)
{
	if (number >= 10)
		ft_putnbr_fd(number / 10, fd);
	ft_putchar_fd((number % 10) + '0', fd);
	return ;
}

void		print_ul_number(size_t number, int fd)
{
	if (number >= 10)
		ft_putnbr_fd(number / 10, fd);
	ft_putchar_fd((number % 10) + '0', fd);
	return ;
}
