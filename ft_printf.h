/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrema <hrema@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 11:06:30 by hrema             #+#    #+#             */
/*   Updated: 2020/07/14 15:42:20 by hrema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

typedef struct		s_struct
{
	char				minus;
	char				nol;

	int					width;
	int					accurary;
	char				type;

	char				c;
	char				*s;
	int					di;
	unsigned int		x;
	unsigned int		u;
	void				*p;
	int					*n;

	char				*string;
	int					count;
}					t_struct;

int					ft_printf(char *string, ...);
void				initialization_number(int *varn, int *n);
int					get_struct(char *string, t_struct *var, va_list arg);

void				ft_put_u_number(unsigned int number, int fd);
int					print_hex_number(unsigned int x, char type);
void				print_ul_number(size_t number, int fd);

int					len_number(int number);
int					len_u_number(unsigned int number);
int					len_hex_number(unsigned long x);
size_t				len_ul_number(size_t number);

int					print_c(t_struct *var, int *n);
int					print_s(t_struct *var, int *n);
int					print_p(t_struct *var, int *n);
int					print_di(t_struct *var, int *n);
int					print_u(t_struct *var, int *n);
int					print_x(t_struct *var, int *n);

#endif
