/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 11:34:42 by hrema             #+#    #+#             */
/*   Updated: 2020/07/07 11:28:21 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*ptr_dest;
	const char	*ptr_src;
	size_t		len_dest;
	size_t		n;

	ptr_dest = dest;
	ptr_src = src;
	n = size;
	while (*ptr_dest != '\0' && n-- != 0)
		ptr_dest++;
	len_dest = ptr_dest - dest;
	n = size - len_dest;
	if (n == 0)
		return (ft_strlen(src) + len_dest);
	while (*ptr_src != '\0')
	{
		if (n != 1)
		{
			*ptr_dest++ = *ptr_src;
			n--;
		}
		ptr_src++;
	}
	*ptr_dest = '\0';
	return ((ptr_src - src) + len_dest);
}
