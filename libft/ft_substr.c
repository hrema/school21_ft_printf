/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 20:35:42 by hrema             #+#    #+#             */
/*   Updated: 2020/05/09 17:49:00 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	const char	*ptr_s;
	char		*sub_str;
	int			i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	i = 0;
	ptr_s = s;
	if (!(sub_str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len-- > 0 && ptr_s)
		sub_str[i++] = ptr_s[start++];
	sub_str[i] = '\0';
	return (sub_str);
}
