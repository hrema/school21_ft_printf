/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:34:27 by hrema             #+#    #+#             */
/*   Updated: 2020/07/14 14:01:00 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len_hex_number(unsigned long x)
{
	int	i;

	i = 0;
	while (x > 0)
	{
		i++;
		x /= 16;
	}
	return (i);
}

int		len_number(int number)
{
	int	count;

	count = 0;
	if (number < 0)
	{
		count++;
		if (number == -2147483648)
		{
			count++;
			number /= 10;
		}
		number *= -1;
	}
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

int		len_u_number(unsigned int number)
{
	int	count;

	count = 0;
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

size_t	len_ul_number(size_t number)
{
	int	count;

	count = 0;
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}
