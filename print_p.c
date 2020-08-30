/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 16:38:45 by hrema             #+#    #+#             */
/*   Updated: 2020/07/17 11:57:21 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	filling_buf(size_t x, int i)
{
	char	*buf;
	size_t	temp;

	if (!(buf = (char *)malloc(sizeof(char) * (i + 1))))
		return (-1);
	while (x > 0 && i > 0)
	{
		i--;
		temp = x % 16;
		if (temp < 10)
			buf[i] = temp + '0';
		else
			buf[i] = 'a' + (temp - 10);
		x /= 16;
	}
	ft_putstr_fd(buf, 1);
	free(buf);
	return (0);
}

static int	print_adress(t_struct *var, int *n)
{
	size_t	x;
	int		i;

	x = (size_t)var->p;
	i = len_hex_number(x);
	*n += i;
	ft_putstr_fd("0x", 1);
	*n += 2;
	if (var->p == NULL)
	{
		if (var->accurary == 0)
			return (0);
		ft_putchar_fd('0', 1);
		(*n)++;
		return (0);
	}
	if (filling_buf(x, i) == -1)
		return (-1);
	return (0);
}

int			print_p(t_struct *var, int *n)
{
	if (var->p == NULL && var->accurary != 0)
		var->width--;
	var->width -= len_hex_number((size_t)var->p) + 2;
	if (var->width < 0)
		var->width = 0;
	if (!(var->string = (char *)malloc(sizeof(char) * (var->width + 1))))
		return (-1);
	ft_memset(var->string, ' ', var->width);
	var->string[var->width] = '\0';
	if (var->minus == '-')
		if (print_adress(var, n) == -1)
			return (-1);
	ft_putstr_fd(var->string, 1);
	*n += ft_strlen(var->string);
	if (var->minus != '-')
		if (print_adress(var, n) == -1)
			return (-1);
	free(var->string);
	return (0);
}
