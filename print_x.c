/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:25:50 by hrema             #+#    #+#             */
/*   Updated: 2020/07/09 14:55:30 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	conditions(t_struct *var, int *c_accurary)
{
	if (var->accurary != -1 || var->minus == '-')
		var->nol = '\0';
	if (var->x == 0 && var->accurary != 0)
	{
		var->width--;
		(*c_accurary)--;
	}
	var->width -= len_hex_number(var->x);
	*c_accurary -= len_hex_number(var->x);
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
	while (c_accurary > 0)
	{
		(*n)++;
		ft_putchar_fd('0', 1);
		c_accurary--;
	}
	if (var->accurary != 0 || (var->accurary == 0 && var->x != 0))
	{
		print_hex_number(var->x, var->type);
		if (var->x == 0)
			(*n)++;
		*n += len_hex_number(var->x);
	}
}

int			print_x(t_struct *var, int *n)
{
	int	c_accurary;

	c_accurary = var->accurary;
	conditions(var, &c_accurary);
	if (!(var->string = (char *)malloc(sizeof(char) * (var->width + 1))))
		return (-1);
	var->string = ft_memset(var->string, ' ', var->width);
	var->string[var->width] = '\0';
	if (var->minus == '-')
		print(var, c_accurary, n);
	ft_putstr_fd(var->string, 1);
	(*n) += ft_strlen(var->string);
	if (var->minus != '-')
		print(var, c_accurary, n);
	free(var->string);
	return (0);
}
