/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 12:11:52 by hrema             #+#    #+#             */
/*   Updated: 2020/05/15 17:06:34 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	size_t	len_l;

	len_l = ft_strlen(l);
	if (*l == '\0')
		return (char *)(b);
	if (!l)
		return ((char *)(b));
	while (len_l <= len && *b != '\0' && b)
	{
		if (*b == *l && ft_strncmp(b, l, len_l) == 0)
			return (char *)(b);
		b++;
		len--;
	}
	return (NULL);
}
