/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:45:22 by hrema             #+#    #+#             */
/*   Updated: 2020/05/10 15:19:52 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *ptr_s, char c)
{
	int	count;

	count = 0;
	while (*ptr_s != '\0')
	{
		if (*ptr_s != c)
		{
			count++;
			while (*ptr_s != c && *ptr_s != '\0')
				ptr_s++;
		}
		else
			ptr_s++;
	}
	return (count);
}

static char		*count_char(const char *ptr_s, char c, int *count)
{
	*count = 0;
	while (*ptr_s == c)
		ptr_s++;
	while (*ptr_s != c && *ptr_s != '\0')
	{
		(*count)++;
		ptr_s++;
	}
	return (char *)(ptr_s);
}

static char		**filling_split_s(char **split_s, const char *ptr_s,
								int count_w, char c)
{
	int			i;
	int			j;
	int			count_c;

	i = 0;
	count_c = 0;
	while (i < count_w)
	{
		j = 0;
		ptr_s = count_char(ptr_s, c, &count_c);
		if (!(split_s[i] = (char *)malloc(sizeof(char) * (count_c + 1))))
		{
			while (i >= 0)
				free(split_s[i--]);
			free(split_s);
			return (NULL);
		}
		ptr_s -= count_c;
		while (*ptr_s != c && *ptr_s != '\0')
			split_s[i][j++] = *(ptr_s)++;
		split_s[i++][j] = '\0';
	}
	split_s[i] = NULL;
	return (split_s);
}

char			**ft_split(char const *s, char c)
{
	const char	*ptr_s;
	char		**split_s;
	int			count_w;

	if (!s)
		return (NULL);
	ptr_s = s;
	count_w = count_words(ptr_s, c);
	if (!(split_s = (char **)malloc(sizeof(char *) * (count_w + 1))))
		return (NULL);
	return (filling_split_s(split_s, ptr_s, count_w, c));
}
