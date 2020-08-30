/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:24:32 by hrema             #+#    #+#             */
/*   Updated: 2020/07/15 13:36:30 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_c_with_flags(t_struct *var, int *n)
{
	if (!(var->string = (char *)malloc(sizeof(char) * (var->width + 1))))
		return (-1);
	if (var->minus != '-' && var->nol == '0')
		var->string = ft_memset(var->string, '0', var->width);
	else
		var->string = ft_memset(var->string, ' ', var->width);
	var->string[var->width] = '\0';
	if (var->minus == '-')
		ft_putchar_fd(var->c, 1);
	ft_putstr_fd(var->string, 1);
	if (var->minus != '-')
		ft_putchar_fd(var->c, 1);
	*n += ft_strlen(var->string) + 1;
	free(var->string);
	return (0);
}

int			print_c(t_struct *var, int *n)
{
	var->width--;
	if (var->width > 0)
	{
		if (print_c_with_flags(var, n) == -1)
			return (-1);
	}
	else
	{
		ft_putchar_fd(var->c, 1);
		(*n)++;
	}
	return (0);
}
