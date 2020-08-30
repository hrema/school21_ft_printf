/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 11:23:05 by hrema             #+#    #+#             */
/*   Updated: 2020/07/15 14:15:49 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	struct_null(t_struct *var)
{
	var->minus = '\0';
	var->nol = '\0';
	var->width = 0;
	var->accurary = -1;
	var->type = '\0';
	var->count = 0;
}

static int	choose_1(t_struct *var, va_list arg, int *n)
{
	if (var->type == '%')
	{
		var->c = '%';
		if (print_c(var, n) == -1)
			return (-1);
	}
	else if (var->type == 'c')
	{
		var->c = va_arg(arg, int);
		if (print_c(var, n) == -1)
			return (-1);
	}
	else if (var->type == 's')
	{
		var->s = va_arg(arg, char *);
		if (print_s(var, n) == -1)
			return (-1);
	}
	else if (var->type == 'p')
	{
		var->p = va_arg(arg, void *);
		if (print_p(var, n) == -1)
			return (-1);
	}
	return (0);
}

static int	choose_2(t_struct *var, va_list arg, int *n)
{
	if (var->type == 'd' || var->type == 'i')
	{
		var->di = va_arg(arg, int);
		if (print_di(var, n) == -1)
			return (-1);
	}
	else if (var->type == 'u')
	{
		var->u = va_arg(arg, unsigned int);
		if (print_u(var, n) == -1)
			return (-1);
	}
	else if (var->type == 'x' || var->type == 'X')
	{
		var->x = va_arg(arg, unsigned int);
		if (print_x(var, n) == -1)
			return (-1);
	}
	else if (var->type == 'n')
	{
		var->n = va_arg(arg, int *);
		initialization_number(var->n, n);
	}
	return (0);
}

static int	print_argument(t_struct *var, va_list arg, char **ptr_string,
							int *n)
{
	int		temp;

	struct_null(var);
	while (**ptr_string != '%' && **ptr_string != '\0')
	{
		ft_putchar_fd(**ptr_string, 1);
		(*n)++;
		(*ptr_string)++;
	}
	if (**ptr_string == '\0')
		return (-2);
	(*ptr_string)++;
	if ((temp = get_struct(*ptr_string, var, arg)) == -1)
		return (-1);
	if (choose_1(var, arg, n) == -1)
		return (-1);
	if (choose_2(var, arg, n) == -1)
		return (-1);
	*ptr_string += temp;
	return (0);
}

int			ft_printf(char *string, ...)
{
	int			temp;
	t_struct	*var;
	va_list		arg;
	char		*ptr_string;
	int			n;

	va_start(arg, string);
	ptr_string = string;
	n = 0;
	if (!(var = (t_struct *)malloc(sizeof(t_struct))))
		return (-1);
	while (*ptr_string != '\0')
	{
		if ((temp = print_argument(var, arg, &ptr_string, &n)) == -2)
			break ;
		if (temp == -1)
		{
			free(var);
			return (-1);
		}
	}
	free(var);
	ft_putchar_fd('\0', 0);
	return (n);
}
