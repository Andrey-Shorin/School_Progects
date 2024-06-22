#include "../minishell.h"

int chec_last_sym(char *str)
{
    int i = 0;
    if(str == 0)
        return -1;
    while (str[i] != '\0')
        i++;
    if (str[i - 1] == '\n')
    {
        str[i - 1] = 0;
        i--;
    }
    if (str[i - 1] == '\\' && str[i - 2] != '\\')
    {
        str[i - 1] = 0;
        return 1;
    }
    return 0;
}

char *get_input()
{
    char *out = 0;
    char *temp;
    char *temp2;
    temp = get_next_line(0);
    if (temp == 0)
        return 0;
    while (temp != 0 && chec_last_sym(temp) == 1)
    {
        if (out != 0)
        {
            temp2 = ft_strjoin(out,temp);
            ft_free_void(out);
            out = temp2;
            free(temp);
        }
        else 
            out = temp;
        temp = get_next_line(0);
    }
    if (temp != 0)
    {
        if (out != 0)
        {
        temp2 = ft_strjoin(out,temp);
        free(out);
        free(temp);
        out = temp2;
        }
        else out = temp;
    }
    return out;
}
int chec_str(char *str)
{
    int i = 0;
    while (str[i] != 0)
    {
        if ( str[i] == '"')
        {
            i++;
            while (str[i] != 0 && str[i] !='"')
                i++;
            if (str[i] == 0)
                return (1);
        }
        if (str[i] == '\'')
        {
            i++;
            while (str[i] != 0 && str[i] !='\'')
                i++;
            if (str[i] == 0)
                return (1);
        }
        i++;
    }
    return (0);
}

int one_command(char *str)
{
    int i = 0;
    while (str[i] != 0 && str[i] != '>' && str[i] != '<' && str[i] != '|')
    {
            if (str[i] == '"')
            {
                while (str[++i] != '"')
                {}
            }
            if (str[i] == '\'')
            {
                while (str[++i] != '\'')
                {}
            }
            i++;
    }
    return (i);
}

t_env *t_env_of_command(char*str,int *j,t_global *global)
{
    
    int i = one_command(str + *j);
    if (i == 0)
        return 0;
    t_env *temp = malloc(sizeof (t_env));
    if (temp == 0)
        return 0;
    temp->name = 0;
    temp->end = 0;
    temp->next = 0;
    temp->comand = 0;
    char *out = malloc(i + 1);
    if (out == 0)
    {
        free(temp);
        return (0);
    }
    temp->content = out;
    ft_strlcpy(out, str + *j, i + 1);
    temp->comand = command_6777(out,global->envn,global->exit_code);
    *j = *j + i;
    if (str[*j] == '|')
        {
            *j = *j + 1;
            return temp;
        }
    return temp;
}
int ft_isspase(char a)
{
    if (a == ' ')
        return 1;
    return 0;
}
int ft_isallspase(char *a)
{
    while (*a != 0)
    {
        if (ft_isspase(*a) == 0)
            return 0;
        a++;
    }
    return 1;
}
int take_str(char *str, int i,char **out)
{
    int len = 0;
    while (ft_isspase(str[i + len]))
        i++;  
    while (str[i + len] != 0 && str[i + len] != '<' && str[i + len] != '>' && !ft_isspase(str[i + len] ))
        len++;
    ft_free_void(*out);
    *out = malloc(len + 1);
    ft_strlcpy(*out, str + i, len + 1);
    while (ft_isspase(str[i + len]))
        i++;
    return i + len;

}
void make_fail(char *str, t_fail *fail)
{
    int i  = 0;
    fail->in = 0;
    fail->out = 0;
    fail->out_append = 0;
    fail->limit = 0;
    while( str[i] != 0)
    {
        if (str[i] == '>' && str[i+1] == '>')
            i = take_str(str, i + 2, &(fail->out_append));
        else if (str[i] == '>' )
            i = take_str(str, i + 1, &(fail->out));
        else if (str[i] == '<' &&str[i + 1] == '<' )
            i = take_str(str, i + 2, &(fail->limit));
        else if (str[i] == '<')
            i = take_str(str, i + 1, &(fail->in));
        else 
            i++;
    }
}
t_env *make_command(char *str, t_global *global)
{   
    int i;
    t_env *temp;
    t_env *start;

    i = 0;
    if (chec_str(str) == 1)
    {
        write(2," wrong str\n", ft_strlen(" wrong str\n"));
        return (0);
    }
    temp =  t_env_of_command(str,&i,global);
    start = temp;
    while (temp != 0)
    {
        temp->next = t_env_of_command(str,&i,global);
        temp = temp->next;
    }
    make_fail(str + i,&(global->fail));
    return start;
}
