/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_new2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:34:18 by nposidon          #+#    #+#             */
/*   Updated: 2021/11/15 17:28:30 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_newlist_d(t_list **end, va_list *list_va)
{
	long	p;
	t_union	arg;
	char	*str;

	arg.d = va_arg(*list_va, int);
	p = (long) arg.d;
	str = malloc(100);
	if (!str)
		return (0);
	int_to_str(p, str);
	*end = ft_newlist_end('d', str, *end, ft_strlen(str));
	if (!end)
		return (0);
	return (2);
}

int	ft_newlist_u(t_list **end, va_list *list_va)
{
	t_union			arg;
	unsigned long	p;
	char			*str;

	arg.u = va_arg(*list_va, unsigned int);
	p = (unsigned long) arg.u;
	str = malloc(100);
	if (!str)
		return (0);
	un_int_to_str(p, str);
	*end = ft_newlist_end('u', str, *end, ft_strlen(str));
	if (!end)
		return (0);
	return (2);
}

int	ft_newlist_x(t_list **end, va_list *list_va)
{
	t_union	arg;
	long	p;
	char	*str;

	arg.u = va_arg(*list_va, int);
	p = (long) arg.u;
	str = malloc(100);
	if (!str)
		return (0);
	int_to_str16(p, str);
	*end = ft_newlist_end('x', str, *end, ft_strlen(str));
	if (!end)
		return (0);
	return (2);
}

int	ft_newlist_xx(t_list **end, va_list *list_va)
{
	long	p;
	t_union	arg;
	char	*str;

	arg.u = va_arg(*list_va, int);
	p = (long) arg.u;
	str = malloc(100);
	if (!str)
		return (0);
	int_to_str16a(p, str);
	*end = ft_newlist_end('x', str, *end, ft_strlen(str));
	if (!end)
		return (0);
	return (2);
}

int	ft_newlist_pr(t_list **end, va_list *list_va)
{
	char	*str;

	(void) list_va;
	str = malloc(2);
	if (!str)
		return (0);
	str[0] = '%';
	str[1] = 0;
	*end = ft_newlist_end('c', str, *end, 1);
	if (!end)
		return (0);
	return (2);
}
