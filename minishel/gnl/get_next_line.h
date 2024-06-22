/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 17:13:21 by nposidon          #+#    #+#             */
/*   Updated: 2022/04/03 19:43:56 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h> 
# include <stdlib.h> 

typedef struct s_list
{
	char			text[100];
	struct s_list	*next;
	int				len;
}t_list2;

char	*get_next_line(int fd);
char	*ft_free(t_list2 **start, char **out);
int		ft_coppy(t_list2 **start, char *out, int *len);
int		ft_start_coppy(t_list2 **start, char *out, int *len);
int		fd_len( t_list2 *a);
int		read_text(int fd, t_list2 **next);
#endif