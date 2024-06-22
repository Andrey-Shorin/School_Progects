/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:34:01 by nposidon          #+#    #+#             */
/*   Updated: 2021/11/12 16:51:36 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	list_va;
	t_list	*start;

	va_start(list_va, str);
	start = ft_make_start(str, &list_va);
	va_end(list_va);
	return (ft_end_itter(start));
}

t_list	*ft_make_start(const char *str, va_list *list_va)
{
	t_list	*end;
	t_list	*start;
	int		k;
	int		i;

	start = ft_newlist('\0');
	if (!start)
		return (0);
	end = start;
	i = 0;
	while (str[i])
	{
		k = ft_new_element(str + i, &end, list_va);
		if (k == 0)
		{
			ft_delit_list(start);
			return (0);
		}
		i = i + k;
	}
	return (start);
}

int	ft_new_element(const char *str, t_list **end, va_list *list_va)
{
	int		i;
	char	*str2;

	i = 0;
	if (*str == '%')
	{
		i = ft_chek(str, end, list_va);
		return (i);
	}
	while (str[i] != '%' && str[i] != '\0')
	{
		i++;
	}
	str2 = malloc(i + 1);
	if (!str2)
		return (0);
	ft_strlcpy(str2, str, i + 1);
	*end = ft_newlist_end('s', str2, *end, i);
	return (i);
}

int	ft_chek(const char *str, t_list **end, va_list *list_va)
{
	char	i;

	i = str[1];
	if (i == 'c')
		return (ft_newlist_c(end, list_va));
	if (i == 's')
		return (ft_newlist_s(end, list_va));
	if (i == 'p')
		return (ft_newlist_p(end, list_va));
	if (i == 'd')
		return (ft_newlist_d(end, list_va));
	if (i == 'i')
		return (ft_newlist_d(end, list_va));
	return (ft_chek2(str, end, list_va));
}

int	ft_chek2(const char *str, t_list **end, va_list *list_va)
{
	char	i;

	i = str[1];
	if (i == 'u')
		return (ft_newlist_u(end, list_va));
	if (i == 'x')
		return (ft_newlist_x(end, list_va));
	if (i == 'X')
		return (ft_newlist_xx(end, list_va));
	if (i == '%')
		return (ft_newlist_pr(end, list_va));
	return (0);
}
