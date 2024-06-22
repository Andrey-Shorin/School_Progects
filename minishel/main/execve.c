
#include "../minishell.h"
char *find_command(char **path,char *name)
{
    char *str;
    char **temp;
    if (name == 0)
        return 0;
	if (access(name, X_OK) == 0)
		return (name);
    if (path == 0)
		return 0;
	temp = path;
	str = ft_strjoin2(*path,"/", name);
	while (temp && *temp && access(str, X_OK) == -1)
	{
		ft_free_void(str);
		temp++;
		str = ft_strjoin2(*temp,"/", name);
	}
	ft_free_char(path);
	if (access(str, X_OK) == 0)
		return (str);
	ft_free_void(str);
	write(2,"can't find command",ft_strlen("can't find command"));
	return (0);
}

int ft_echo(char **comand)
{
	int i = 1;
	if (ft_strnstr( "-n",comand[i],3))
	{
		i++;
		while (comand[i] != 0)
		{
			ft_printf("%s",comand[i]);
			i++;
			if (comand[i] != 0)
				ft_printf( " ");
		}
		return 0;
	}
	while (comand[i] != 0)
	{
		ft_printf("%s",comand[i]);
		i++;
		if (comand[i] != 0)
			ft_printf( " ");
	}
	ft_printf("\n");
	return 0;
}
int ft_env(char **comand)
{
	int i = 0;
	while (comand[i] != 0)
	{
		ft_printf("%s",comand[i]);
		i++;
		ft_printf( "\n");
	}
	return 0;
}
int ft_print_hystory(t_global *global)
{
	t_env *temp;
	temp = global->history;
	while (temp != 0)
	{
		ft_printf ("%s\n",temp->content);
		temp = temp->next;
	}
	return 0;

}
void chec_comand(char **comand, char **en, t_global *global, t_env *A)
{
	if (ft_strncmp(comand[0], "echo", 5) == 0)
		exit (ft_echo(comand));
	if (ft_strncmp(comand[0], "env", 4)== 0)
		exit (ft_env(en));
	if (ft_strncmp(comand[0], "hystory", 8) == 0)
		exit (ft_print_hystory(global));
	if (ft_strncmp("exit",comand[0],5) == 0)
        exit(0);
    if (ft_strncmp("export",comand[0],7) == 0)
        exit(export_env(global,A));
    if (ft_strncmp("cd",comand[0],3) == 0)
        exit(fd_cd(global,A));
    if (ft_strncmp("unset",comand[0],6) == 0)
        exit(unset_env(global,A));
}
int ft_execve(t_global *global, t_env *A)
{   

    char *y;
    char **en = remake_env(global->envn);
	if (A->comand == 0)
		exit(1);
	chec_comand(A->comand ,en,global,A);
	y = find_command(ft_PATH(global->envn),(A->comand)[0]);
	if (y != 0)
		execve(y, A->comand, en);
	write(2, (A->comand )[0],ft_strlen((A->comand)[0]));
	write(2, " command not found \n",ft_strlen(" command not found \n"));
	ft_free_char(A->comand);
    ft_free_char(en);
    exit(1);
}