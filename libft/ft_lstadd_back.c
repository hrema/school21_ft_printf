/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:35:16 by hrema             #+#    #+#             */
/*   Updated: 2020/05/07 12:14:54 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *ptr_lst;

	ptr_lst = *lst;
	if ((*lst) == NULL)
		(*lst) = new;
	else
	{
		while (ptr_lst->next)
			ptr_lst = ptr_lst->next;
		ptr_lst->next = new;
	}
}
