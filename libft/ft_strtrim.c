/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 21:27:51 by hrema             #+#    #+#             */
/*   Updated: 2020/05/13 15:53:17 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	begin_string(const char *s, const char *set)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_strchr(set, s[i]) == NULL)
			break ;
		i++;
	}
	return (i);
}

static int	end_string(const char *s, const char *set, int start)
{
	int i;

	i = ft_strlen(s) - 1;
	while (i > start)
	{
		if (ft_strchr(set, s[i]) == NULL)
			break ;
		i--;
	}
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char		*copy_s1;
	int			finish;
	int			start;
	int			i;

	if (!set)
		return (char *)(s1);
	if (!s1)
		return (NULL);
	start = begin_string(s1, set);
	finish = end_string(s1, set, start);
	if (!(copy_s1 = (char *)malloc(sizeof(char) * (finish - start + 2))))
		return (NULL);
	i = 0;
	while (start <= finish)
	{
		copy_s1[i] = s1[start];
		i++;
		start++;
	}
	copy_s1[i] = '\0';
	return (copy_s1);
}
