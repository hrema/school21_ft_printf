/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:46:04 by hrema             #+#    #+#             */
/*   Updated: 2020/07/07 16:17:30 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*split(const char *nptr, int *sign)
{
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
	{
		*sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	return (char *)(nptr);
}

int			ft_atoi(const char *nptr)
{
	int					sign;
	unsigned long long	number;
	char				*ptr;

	number = 0;
	sign = 1;
	ptr = split(nptr, &sign);
	while (*ptr >= '0' && *ptr <= '9')
	{
		number = number * 10 + (*ptr++ - '0');
		if (number > 9223372036854775807 && sign == -1)
			return (0);
		if (number > 9223372036854775807 && sign == 1)
			return (-1);
	}
	return (number * sign);
}
