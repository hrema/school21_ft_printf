/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:37:48 by hrema             #+#    #+#             */
/*   Updated: 2020/07/09 17:22:26 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_s_with_flags(t_struct *var, int *n)
{
	if (var->accurary)
	{
		var->count = 0;
		while (var->count != var->accurary && var->s[var->count] != '\0')
		{
			ft_putchar_fd(var->s[var->count], 1);
			var->count++;
			(*n)++;
		}
	}
	ft_putstr_fd(var->string, 1);
	*n += ft_strlen(var->string);
}

static void	print_s_without_flags(t_struct *var, int *n)
{
	ft_putstr_fd(var->string, 1);
	*n += ft_strlen(var->string);
	if (var->accurary)
	{
		var->count = 0;
		while (var->count != var->accurary && var->s[var->count] != '\0')
		{
			ft_putchar_fd(var->s[var->count], 1);
			var->count++;
			(*n)++;
		}
	}
}

int			print_s(t_struct *var, int *n)
{
	if (var->s == NULL || var->s == 0)
		var->s = "(null)";
	if (var->accurary != -1)
	{
		if (var->accurary < (int)ft_strlen(var->s))
			var->width = var->width - var->accurary;
		else
			var->width = var->width - ft_strlen(var->s);
	}
	else
		var->width = var->width - ft_strlen(var->s);
	if (var->width < 0)
		var->width = 0;
	if (!(var->string = (char *)malloc(sizeof(char) * (var->width + 1))))
		return (-1);
	var->string = ft_memset(var->string, ' ', var->width);
	var->string[var->width] = '\0';
	if (var->minus == '-')
		print_s_with_flags(var, n);
	else
		print_s_without_flags(var, n);
	free(var->string);
	return (0);
}
