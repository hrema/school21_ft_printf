/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 16:13:02 by hrema             #+#    #+#             */
/*   Updated: 2020/05/05 18:53:59 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicat;
	int		size;

	size = 0;
	while (s[size] != '\0')
		size++;
	if (!(duplicat = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	size = 0;
	while (s[size] != '\0')
	{
		duplicat[size] = s[size];
		size++;
	}
	duplicat[size] = '\0';
	return (duplicat);
}
