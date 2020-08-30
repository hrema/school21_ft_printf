/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 19:24:13 by hrema             #+#    #+#             */
/*   Updated: 2020/07/07 11:27:36 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	const char *ptr_src;

	if (!src)
		return (0);
	ptr_src = src;
	while (*ptr_src != '\0')
	{
		if (size > 1 && dest)
		{
			*dest++ = *ptr_src;
			size--;
		}
		ptr_src++;
	}
	if (size)
		*dest = '\0';
	return (ptr_src - src);
}
