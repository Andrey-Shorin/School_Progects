/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 17:13:21 by nposidon          #+#    #+#             */
/*   Updated: 2021/12/24 17:31:06 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h> 
# include <stdlib.h> 

typedef struct s_list
{
	char			text[BUFFER_SIZE];
	struct s_list	*next;
	int				len;
}t_list;

char	*get_next_line(int fd);
char	*ft_free(t_list **start, char **out);
int		ft_coppy(t_list **start, char *out, int *len);
int		ft_start_coppy(t_list **start, char *out, int *len);
int		fd_len( t_list *a);
int		read_text(int fd, t_list **next);
#endif