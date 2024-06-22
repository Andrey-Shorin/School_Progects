#include "../minishell.h"
int ft_chec_str(const char *str1, const char *str2)
{
    int i = 0;
    while (str1[i] == str2[i] && str1[i] != 0)
        i++;
    if (str1[i] == 0 && str2[i] == 0)
        return (OK);
    return (ERROR);
}
int add_to_ft_str(t_str *s,char a)
{
    int j;
    
    j = 0;
    if (s->str == 0)
        return 0;
    if (s->len < s->i + 5)
        {
            char *temp = malloc(s->len * 5);
            if (temp == 0)
            {
                free(s->str);
                return 0;
            }
            while (j <= s->i)
            {
                temp[j] = (s->str)[j];
                j++;
            }
            free(s->str);
            s->str = temp;
            s->len = s->len * 5; 
        }
    s->str[s->i] = a;
    (s->i) ++;
    s->str[s->i] = 0;
    return (1);
}
int add_to_ft_str_of_str(t_str_of_str *s,char *a)
{
    int j;
    
    j = 0;
    if (s->str == 0)
        return (ft_free_void(a));
    if (s->len < s->i + 5)
        {
            char **temp = malloc(s->len * 5 *sizeof(char *));
            if (temp == 0)
            {
                ft_free_char(s->str);
                return 0;
            }
            while (j <= s->i)
            {
                temp[j] = (s->str)[j];
                j++;
            }
            free(s->str);
            s->str = temp;
            s->len = s->len * 5; 
        }
    s->str[s->i] = a;
    (s->i) ++;
    s->str[s->i] = 0;
    return (1);
}
void ft_add_int(int a,t_str *str)
{
    char	s[100];
	int		i;
	int		d;

	i = 0;
	d = 0;
	s[i] = 0;
	i++;
	if (a < 0)
	{
		d = -1;
		a = -a;
	}
	while ((a != 0 || i == 1) && i < 99)
	{
		s[i] = (a % 10) + '0';
		a = a / 10;
		i ++;
	}
	if (d == -1)
		s[i++] = '-';
    i--;
    while ( i != 0)
        add_to_ft_str(str,s[i--]);
}
int find_dollar(t_env *env,char *str,t_str *result,int *i, int exit)
{
    int end = 1;
    int j = 1;
    while(str[end] != '\0'&& str[end] != '\'' && str[end] != '"' 
            && str[end] != '$' &&str[end] != ' ' )
        end++;
    *i = *i + end;
    t_str ft_str;
    ft_str.str = malloc(10);
    if (ft_str.str == 0)
        return 0;
    ft_str.i = 0;
    ft_str.len = 10;
    if (ft_str.str == 0)
        return (ERROR);
    while (j < end)
        add_to_ft_str(&ft_str,str[j++]);
    if (ft_chec_str("?", ft_str.str ) == OK)
        {
            ft_add_int(exit,result);
            free(ft_str.str);
            return (OK);
        }
    while (env && ft_chec_str(env->name, ft_str.str))
		env = env->next;
    free(ft_str.str);
	if (!env)
		return (OK);
    j = 0;
    while ((env->content)[j] != 0)
         add_to_ft_str(result,(env->content)[j++]);
    return(OK);
}

char **command_6777(char *command, t_env *env,int exit)
{
    int i = 0;
    t_str str;
    t_str_of_str str_of_str;
    str_of_str.str =  malloc(10 *sizeof(char *));
    str.str = malloc(10);
    str_of_str.len = 10;
    str.len = 10;
    str_of_str.i = 0;
    str.i = 0;
    while (command[i] != 0 )
    {
        while (command[i] != '\'' && command[i] != '"' && command[i] != '$' && command[i] != '\0' && command[i] != ' ')
            add_to_ft_str(&str,command[i++]);
        if (command[i] == '\'')
        {
            i++;
            while (command[i] != '\'')
            add_to_ft_str(&str,command[i++]);
            i++;
            continue;
        }
        if (command[i] == '"')
        {
            i++;
            while (command[i] != '"')
            {
                if (command[i] == '$')
                    find_dollar(env,command + i,&str,&i,exit);
                else 
                    add_to_ft_str(&str,command[i]);
                i++;
            }
            i++;
            continue;
        }
        if (command[i] == ' ') 
        {
            if (str.i != 0)
            {
                add_to_ft_str_of_str(&str_of_str,str.str);
                str.str = malloc(100);
                str.len = 100;
                str.i = 0;
            }
            while (command[i] == ' ')
                i++;
            continue;
        }
        if (command[i] == '$')
            find_dollar(env,command + i,&str,&i,exit);

    }
        if (str.i > 0) 
            add_to_ft_str_of_str(&str_of_str,str.str);
    return (str_of_str.str);
}