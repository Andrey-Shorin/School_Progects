#include "../minishell.h"
int ft_len_char2(char ** s)
 {
     int i = 0;
     while (s != 0 && s[i] != 0)
        i++;
    return i;
 }
  void del_env2(t_global *global,char *name1)
 {
    t_env *temp = global->envn;
    if (ft_strncmp(temp->name,name1,ft_strlen(name1)) == 0)
    {
        global->envn = temp->next;
        ft_free_one_env(temp);
        return;
    }
    while(temp->next != 0 && ft_strncmp(temp->next->name,name1,ft_strlen(temp->next->name) + 1) != 0)
        temp = temp->next;
    if (temp->next == 0)
        return;
    t_env *del = temp->next;
    temp->next = del->next;
    ft_free_one_env(del);
 }
 void abdate_env(t_global *global,const char *name, char *str)
{
    t_env* temp = global->envn;
    while (temp != 0 && ft_strncmp(temp->name,name,ft_strlen(name)) != 0)
        temp = temp->next;
    if (temp == 0)
    {
        ft_free_void(str);
        return;
    }
    ft_free_void(temp->content);
    temp->content = str;
}


int export_env(t_global *global,t_env *A)
{
    if ( A->comand == 0 || ft_len_char2(A->comand) != 3)
    {
        write(2,"export :wrong argument\n",ft_strlen("export :wrong argument\n"));
        return 1;     
    }
    t_env *new = malloc(sizeof(t_env));
    if (new == 0)
        return 1;
    new->next = 0;
    new->name = ft_strdup((A->comand)[1]);
    new->content = ft_strdup((A->comand)[2]);
    if (new->name == 0 ||  new->content == 0 )
    {
        ft_free_void(new->name);
        ft_free_void(new->content);
        ft_free_void(new);
        return 1;
    }
    del_env2(global,new->name);
    t_env *temp = global->envn;
    if (temp == 0)
    {
        global->envn = new;
        return 0;
    }
    while (temp->next != 0)
        temp = temp->next;
    temp->next = new;
    return 0;
}
int fd_cd(t_global *global,t_env *A)
{
    char *old = getcwd(0,0);
    
    if ( A->comand == 0 || ft_len_char2(A->comand) != 2)
    {
        write(2,"cd wrong argument\n",ft_strlen("cd wrong argument\n"));
        ft_free_void(old);
        return 1;
    }
    int error = chdir((A->comand)[1]);
    if (error != 0)
        write(2,"cd error\n",ft_strlen("cd error\n"));
    char *pwd = getcwd(0,0);
    if (pwd != 0)
        abdate_env(global,"PWD", pwd);
    if (old != 0)
        abdate_env(global,"OLDPWD", old);
    return 0;
}

int fd_pwd(t_global *global,t_env *A)
{
    if ( A->comand == 0 || ft_len_char2(A->comand) != 1)
    {
        write(2,"pwd wrong argument\n",ft_strlen("pwd wrong argument\n"));
        return 1;
    }
    char *pwd = getcwd(0,0);
    if (pwd == 0)
    {
        write(2,"pwd error\n",ft_strlen("pwd error\n"));
        return 1;
    }
    ft_printf("%s\n",pwd);
    abdate_env(global,"PWD", pwd);
    return 0;
}


 int unset_env(t_global *global,t_env *A)
 {
     if ( global->envn == 0)
        return 0;
    if ( A->comand == 0 || ft_len_char2(A->comand) != 2)
    {
        ft_printf("wrong argument\n");
        return 1;
    }
    del_env2(global,(A->comand)[1]);
    return 0;
    
 }