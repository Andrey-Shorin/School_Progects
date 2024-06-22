/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_new1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:34:12 by nposidon          #+#    #+#             */
/*   Updated: 2021/11/12 16:47:08 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_newlist(char type)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->type = type;
	new->exit = 0;
	new->next = 0;
	return (new);
}

t_list	*ft_newlist_end(char type, char *exit, t_list *end, int len)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		free(exit);
		return (0);
	}
	new->type = type;
	new->exit = exit;
	new->len = len;
	new->next = 0;
	end->next = new;
	return (new);
}

int	ft_newlist_c(t_list **end, va_list *list_va)
{
	t_union	arg;
	char	*str;

	str = malloc(2);
	arg.c = (unsigned int) va_arg(*list_va, int);
	if (!str)
		return (0);
	str[0] = arg.c;
	str[1] = 0;
	*end = ft_newlist_end('c', str, *end, 1);
	if (!end)
		return (0);
	return (2);
}

int	ft_newlist_s(t_list **end, va_list *list_va)
{
	char	*str;
	int		len;
	t_union	arg;

	arg.s = va_arg(*list_va, char *);
	if (arg.s == 0)
		arg.s = "(null)";
	len = ft_strlen(arg.s);
	str = malloc(len + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, arg.s, len + 1);
	*end = ft_newlist_end('s', str, *end, len);
	if (!end)
		return (0);
	return (2);
}

int	ft_newlist_p(t_list **end, va_list *list_va)
{
	unsigned long long	p;
	t_union				arg;
	char				*str;

	arg.p = va_arg(*list_va, void *);
	p = (unsigned long long) arg.p;
	str = malloc(100);
	if (!str)
		return (0);
	pointer_to_str16(p, str);
	*end = ft_newlist_end('p', str, *end, ft_strlen(str));
	if (!end)
		return (0);
	return (2);
}
