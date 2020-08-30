/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 12:10:11 by hrema             #+#    #+#             */
/*   Updated: 2020/05/09 10:03:09 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr_s;
	const char	*ptr_ptr_s;

	ptr_s = s;
	ptr_ptr_s = s;
	c = (unsigned char)c;
	while (*ptr_s != '\0')
	{
		if (*ptr_s == c)
			ptr_ptr_s = ptr_s;
		ptr_s++;
	}
	if (*ptr_s == c)
		return (char *)(ptr_s);
	if (*ptr_ptr_s == c)
		return (char *)(ptr_ptr_s);
	return (NULL);
}
