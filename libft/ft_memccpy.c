/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:30:47 by hrema             #+#    #+#             */
/*   Updated: 2020/05/08 12:02:01 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;
	unsigned char		sym;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	sym = (unsigned char)c;
	while (n--)
	{
		if (*ptr_src == sym)
		{
			*ptr_dest++ = *ptr_src++;
			return (void *)(ptr_dest);
		}
		*ptr_dest++ = *ptr_src++;
	}
	return (void *)(NULL);
}
