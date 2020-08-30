/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:35:22 by hrema             #+#    #+#             */
/*   Updated: 2020/07/15 13:35:59 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_flags(char *string, t_struct *var)
{
	char	*ptr_string;

	ptr_string = string;
	while (*ptr_string == '-' || *ptr_string == '0')
	{
		if (*ptr_string == '-')
			var->minus = '-';
		else if (*ptr_string == '0')
			var->nol = '0';
		ptr_string++;
	}
	return (ptr_string - string);
}

static int	get_width(char *string, t_struct *var, va_list arg)
{
	char *ptr_string;

	ptr_string = string;
	if (*ptr_string == '*')
	{
		var->width = va_arg(arg, unsigned int);
		if (var->width < 0)
		{
			var->width *= -1;
			var->minus = '-';
		}
		ptr_string++;
	}
	else if (*ptr_string >= '0' && *ptr_string <= '9')
	{
		var->width = ft_atoi(ptr_string);
		ptr_string += len_number(var->width);
	}
	return (ptr_string - string);
}

static int	get_accurary(char *string, t_struct *var, va_list arg)
{
	char *ptr_string;

	ptr_string = string;
	if (*ptr_string == '.')
	{
		var->accurary = 0;
		ptr_string++;
		if (*ptr_string == '*')
		{
			var->accurary = va_arg(arg, int);
			if (var->accurary < 0)
				var->accurary = -1;
			ptr_string++;
		}
		else if (*ptr_string >= '0' && *ptr_string <= '9')
		{
			while (*ptr_string >= '0' && *ptr_string <= '9')
			{
				var->accurary = var->accurary * 10 + (*ptr_string - '0');
				ptr_string++;
			}
		}
	}
	return (ptr_string - string);
}

static int	get_type(char string, t_struct *var)
{
	if (string == 'c' || string == 's' || string == 'p' ||
		string == 'd' || string == 'i' || string == 'u' ||
		string == 'x' || string == 'X' || string == 'n' ||
		string == '%')
	{
		var->type = string;
	}
	else
		return (-1);
	return (1);
}

int			get_struct(char *string, t_struct *var, va_list arg)
{
	char	*ptr_string;
	int		temp;

	ptr_string = string;
	ptr_string += get_flags(ptr_string, var);
	ptr_string += get_width(ptr_string, var, arg);
	ptr_string += get_accurary(ptr_string, var, arg);
	if ((temp = get_type(*ptr_string, var)) == -1)
		return (-1);
	ptr_string += temp;
	return (ptr_string - string);
}
