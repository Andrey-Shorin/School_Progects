/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 17:13:11 by nposidon          #+#    #+#             */
/*   Updated: 2021/12/24 17:13:13 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int				error;
	int				len;
	char			*out;
	static void		*start[1024];

	error = 0;
	if (fd < 0 || fd > 1023)
		return (0);
	if (start[fd] == 0 || fd_len((t_list *) start[fd]) == -1)
		error = read_text(fd, (t_list **) &(start[fd]));
	if (error == -1)
	{
		ft_free((t_list **) &(start[fd]), 0);
		return (0);
	}
	len = fd_len((t_list *) start[fd]);
	if (len == 0)
		return (ft_free((t_list **) &(start[fd]), 0));
	out = malloc(len + 1);
	if (out && !ft_coppy((t_list **) &(start[fd]), out, &len))
		ft_free((t_list **) &(start[fd]), &out);
	return (out);
}

char	*ft_free(t_list **start, char **out)
{
	t_list	*temp;

	while (*start != 0)
	{
		temp = (*start)->next;
		free(*start);
		*start = temp;
	}
	if (out != 0 && *out != 0)
	{
		free(*out);
		*out = 0;
	}
	return (0);
}

int	ft_coppy(t_list **start, char *out, int *len)
{
	int		i;
	int		l;
	t_list	*a;

	l = 0;
	i = ft_start_coppy(start, out, len);
	if (*start == 0 || (*start)->len == 0)
		return (1);
	a = malloc(sizeof(t_list));
	if (a == 0)
		return (0);
	a->next = 0;
	while ((*start)->len > l && ((*start)->text)[l] != '\n')
		out[i++] = ((*start)->text)[l++];
	if (((*start)->text)[l] == '\n')
		out[i++] = ((*start)->text)[l++];
	out[i] = 0;
	i = 0;
	while ((*start)->len > l)
		(a->text)[i++] = ((*start)->text)[l++];
	a->len = i;
	free(*start);
	*start = a;
	return (1);
}

int	ft_start_coppy(t_list **start, char *out, int *len)
{
	t_list	*temp;
	int		i;
	int		rest;

	i = 0;
	while (*start != 0 && *len >= (*start)->len)
	{
		rest = 0;
		*len -= (*start)->len;
		while ((*start)->len > rest)
			out[i++] = ((*start)->text)[rest++];
		temp = ((*start)->next);
		free(*start);
		*start = temp;
	}
	if (*start == 0 || (*start)->len == 0)
		out[i++] = 0;
	return (i);
}

int	read_text(int fd, t_list **next)
{
	t_list	*a;

	while (*next != 0)
		next = &((*next)->next);
	a = malloc(sizeof(t_list));
	if (a == 0)
		return (-1);
	a->next = 0;
	a->len = read(fd, &(a->text), BUFFER_SIZE);
	*next = a;
	if (a->len < 0)
		return (-1);
	if (fd_len(a) == -1)
		return (read_text(fd, &(a->next)));
	return (1);
}
