#include "../minishell.h"
void free_env(t_env *G )
{
    t_env *temp;
    while (G != 0)
    {   
        temp = G;
        G = G->next;
        ft_free_void(temp->name);
        ft_free_void(temp->content);
        free (temp);
    } 
}

int len_env(char * str, char z)
{
    int i = 0;
    while (str != 0 && str[i] != 0 && str[i] != z)
    {
        i++;
    }
    return i;
}
void fool_content_env(char *str,char * name, char * content)
{   
    int i;
    int j;

    j = 0;
    i = 0;
     while (str[i] != 0 && str[i] != '=')
    {
        name[i] = str[i];
        i++;
    }
    name[i] = 0;
    i++;
    while (str[i] != 0 && str[i] != '\n')
    {
        content[j] = str[i];
        i++;
        j++;
    }
    content[j] = 0;
}
void take_content_env(char *str,char ** name, char ** content)
{
    int len_a;
    int len_b;
 
    if (str == 0)
        return ;
    *name = 0;
    *content =0;
    len_a = len_env(str,'=');
    len_b = len_env(str + 1 + len_a,'\0');
    *name = malloc(len_a + 1);
    if (*name == 0)
        return;
    *content = malloc(len_b + 1);
    if (*content == 0)
    {
        free(*name);
        *name = 0;
        return;
    }
    fool_content_env(str, *name, *content);
}

t_env *make_env(char *env[])
{   
    t_env *start;
    t_env *temp;

    if (*env == 0)
        return 0;
    start = malloc(sizeof (t_env));
    if (start == 0)
        return 0;
    start->next = 0;
    take_content_env(*env,&(start->name), &(start->content));
    env++;
    temp = start;
    while (*env != 0)
    {
        temp->next = malloc(sizeof (t_env));
        if (temp->next == 0)
            return start;
        temp->next->next = 0;
        temp = temp->next;
        take_content_env(*env,&(temp->name), &(temp->content));
        env++;
    }
    return start;
}

char	**ft_PATH(t_env *envp)
{
	while (envp && ft_strncmp(envp->name, "PATH", 5)!= 0)
	{
		envp = envp->next;
	}
	if (!envp)
		return (0);
	return (ft_split(envp->content, ':'));
}
int ft_len_env(t_env *envp)
{
    int i = 0;
    while (envp )
	{
		envp = envp->next;
        i++;
	}
	
	return (i);
}
char **remake_env(t_env *envp)
{
    char **en;
    int i = 0;
    int l = ft_len_env(envp);
    en = malloc(sizeof(char*) * (l+1));
    while (envp )
	{
        en[i++] = ft_strjoin2(envp->name,"=", envp->content);
		envp = envp->next;
	}
    en[i] = 0;
    return en;
}