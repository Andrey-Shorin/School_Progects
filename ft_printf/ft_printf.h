/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:34:56 by nposidon          #+#    #+#             */
/*   Updated: 2021/11/12 16:51:53 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h> 
# include <stdarg.h> 
# include <stdlib.h> 

typedef union i_union
{
	unsigned char	c;
	char			*s;
	void			*p;
	int				d;
	int				i;
	unsigned int	u;
	int				x;
	int				xx;
	int				proc;
}	t_union;

typedef struct i_list
{
	int				len;
	char			type;
	char			*exit;
	struct i_list	*next;
}	t_list;

int		ft_printf(const char *str, ...);
int		ft_strlen(const char *d);
int		ft_strlcpy(char *a, const char *b, int n);
t_list	*ft_make_start(const char *str, va_list *a);
int		ft_end_itter(t_list *start);
int		ft_end_print_list(t_list *list);
int		ft_new_element(const char *str, t_list **end, va_list *list_va);
int		ft_chek(const char *str, t_list **end, va_list *list_va);
int		ft_chek2(const char *str, t_list **end, va_list *list_va);
int		ft_end_print_list(t_list *list);
int		ft_delit_list(t_list *start);
t_list	*ft_newlist(char type);
t_list	*ft_newlist_end(char type, char *exit, t_list *end, int len);
int		ft_newlist_p(t_list **end, va_list *list_va);
int		ft_newlist_d(t_list **end, va_list *list_va);
int		ft_newlist_c(t_list **end, va_list *list_va);
int		ft_newlist_s(t_list **end, va_list *list_va);
int		ft_newlist_u(t_list **end, va_list *list_va);
int		ft_newlist_x(t_list **end, va_list *list_va);
int		ft_newlist_xx(t_list **end, va_list *list_va);
int		ft_newlist_pr(t_list **end, va_list *list_va);
void	int_to_str(long a, char *str);
void	un_int_to_str(unsigned long a, char *str);
char	ft_16(int a);
void	int_to_str16(long a, char *str);
void	pointer_to_str16(unsigned long long a, char *str);
char	ft_16a(int a);
void	int_to_str16a(long a, char *str);
void	ft_revers_coppy(const char *s, char *str);

#endif
