#include "../minishell.h"
void	ft_free_char(char **m)
{
	char	**temp;

	if (!m)
		return ;
	temp = m;
	while (*temp)
		ft_free_void(*(temp++));
	ft_free_void(m);
}
int ft_free_void(void *A)
{
    if (A != 0)
        free(A);
	return 0;
}
void ft_free_fail(t_fail *fail)
{
	ft_free_void(fail->in);
	ft_free_void(fail->out);
	ft_free_void(fail->out_append);
	ft_free_void(fail->limit);
	fail->in = 0;
	fail->out = 0;
	fail->out_append = 0;
	fail->limit = 0;
}
void ft_free_env(t_env **f)
{
	t_env *temp;
	t_env *a = *f;
	*f = 0;
	while ( a != 0)
	{
		ft_free_void(a->name);
		ft_free_void(a->content);
		ft_free_char(a->comand);
		temp = a->next;
		free(a);
		a = temp;
	}
}
void ft_free_one_env(t_env *a)
{

		ft_free_void(a->name);
		ft_free_void(a->content);
		free(a);
}