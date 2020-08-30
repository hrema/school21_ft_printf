/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:52:54 by hrema             #+#    #+#             */
/*   Updated: 2020/05/09 13:30:19 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*ptr_dest;
	const unsigned char		*ptr_src;
	size_t					i;

	if (src == dest)
		return (dest);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	i = 0;
	if (ptr_dest < ptr_src)
		while (n-- > 0)
			*ptr_dest++ = *ptr_src++;
	else if (ptr_dest > ptr_src)
		while (++i <= n)
		{
			ptr_dest[n - i] = ptr_src[n - i];
		}
	return (void *)(dest);
}
