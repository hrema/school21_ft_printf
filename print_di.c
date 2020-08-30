/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:18:14 by hrema             #+#    #+#             */
/*   Updated: 2020/07/15 14:21:29 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	conditions(t_struct *var, int *c_accurary)
{
	if (var->accurary != -1 || var->minus == '-')
		var->nol = '\0';
	if (var->di < 0)
		(*c_accurary)++;
	if (var->di == 0 && var->accurary != 0)
	{
		var->width--;
		(*c_accurary)--;
	}
	var->width -= len_number(var->di);
	*c_accurary -= len_number(var->di);
	if (*c_accurary > 0)
		var->width -= *c_accurary;
	if (var->width < 0)
		var->width = 0;
	if (var->nol == '0')
	{
		*c_accurary = var->width;
		var->width = 0;
	}
}

static void	print(t_struct *var, int c_accurary, int *n)
{
	if (var->di < 0 && (var->accurary != 0 ||
		(var->accurary == 0 && var->di != 0)))
	{
		ft_putchar_fd('-', 1);
		if (var->di == -2147483648)
		{
			ft_putchar_fd('2', 1);
			(*n)++;
			var->di = -147483648;
		}
		var->di *= -1;
	}
	while (c_accurary > 0)
	{
		(*n)++;
		ft_putchar_fd('0', 1);
		c_accurary--;
	}
	if (var->accurary != 0 || (var->accurary == 0 && var->di != 0))
	{
		ft_putnbr_fd(var->di, 1);
		if (var->di == 0)
			(*n)++;
		*n += len_number(var->di);
	}
}

int			print_di(t_struct *var, int *n)
{
	int	c_accurary;

	c_accurary = var->accurary;
	conditions(var, &c_accurary);
	if (!(var->string = (char *)malloc(sizeof(char) * (var->width + 1))))
		return (-1);
	var->string = ft_memset(var->string, ' ', var->width);
	var->string[var->width] = '\0';
	if (var->di < 0)
		(*n)++;
	if (var->minus == '-')
		print(var, c_accurary, n);
	ft_putstr_fd(var->string, 1);
	*n += ft_strlen(var->string);
	if (var->minus != '-')
		print(var, c_accurary, n);
	free(var->string);
	return (0);
}
