#include "../minishell.h"
t_g* glo = 0;
void ft_open_fail(t_global *global, int *fd_read, t_env **A)
{
    if ((global->fail).out != 0 && *A != 0)
    {
        *fd_read = open((global->fail).out,O_CREAT | O_WRONLY | O_TRUNC,0644);
        if ( *fd_read < 0)
        {
            ft_free_env(A);
            ft_free_fail(&(global->fail));
            write(2,"cant open fail ",ft_strlen("cant open fail "));
            write(2,(global->fail).out,ft_strlen((global->fail).out));
        }
    }
    else if ( (global->fail).out_append != 0 && *A != 0)
    {
        *fd_read = open((global->fail).out_append,O_CREAT | O_WRONLY | O_APPEND,0644);
        if ( *fd_read < 0)
        {
            ft_free_env(A);
            ft_free_fail(&(global->fail));
            write(2,"cant open fail ",ft_strlen("cant open fail "));
            write(2,(global->fail).out_append,ft_strlen((global->fail).out_append));
        }
    }
}
void open_read(t_global *global,t_env **A,int *fdin)
{
    *fdin = open((global->fail).in,O_RDONLY );
        if (*fdin < 0)
        {
            ft_free_env(A);
            ft_free_fail(&(global->fail));
            write(2,"cant open fail ",ft_strlen("cant open fail "));
            write(2,(global->fail).in,ft_strlen((global->fail).in));
        }
}
void open_file2(int *tmpin,t_global *global,t_env **A,int *fdin,int *fdout)
{
    char *temp2;
    int pip[2];
    if ((global->fail).in != 0 && *A != 0)
       open_read(global,A,fdin);
    else if ((global->fail).limit != 0 && *A != 0 && (global->fail).in == 0)
    {
        pipe(pip);
        *fdout = pip[1];
        *fdin = pip[0];
        temp2 = get_next_line(0);
        while(ft_strncmp((global->fail).limit,temp2,ft_strlen((global->fail).limit)) != 0)
        {
            write(pip[1],temp2,ft_strlen(temp2));
            free(temp2);
            temp2 = get_next_line(0);
        } 
        free(temp2); 
        close(pip[1]);
    }
    else 
        *fdin = dup(*tmpin);
}
void for_every_command1(int *fdin,int *fd_read, int *tmpout,t_env *A,int *fdout)
{
    int		pip[2];
    dup2(*fdin, 0);
        close(*fdin);
        if ( A->next == 0)
        {
            if ( *fd_read != -1)
                *fdout = *fd_read;
            else
                *fdout = dup(*tmpout);
        }
        else
        {
            pipe(pip);
            *fdout = pip[1];
            *fdin = pip[0];
        }
}
void for_every_command2(int *tmpin,int *tmpout, int *fdin, t_global *global, t_env *A)
{
    int ret;
    ret = fork();
    if (ret == 0)
    {
        glo->par = 0;
        close(*tmpin);
        close(*tmpout);
        close(*fdin);
        ft_execve(global, A);
        exit(1);
    }
    A->end = ret; 
}
int pip_fd(t_global *global)
{
    t_env *A = global->list_of_command;
    int tmpin = dup(0);
    int tmpout = dup(1);
    int fdin;
    int fd_read = -1;
    int fdout;
    ft_open_fail(global, &fd_read,&A);
    open_file2(&tmpin,global,&A,&fdin,&fdout);
    while (A != 0 )
    {
        for_every_command1(&fdin,&fd_read, &tmpout,A,&fdout);
        dup2(fdout,1);
        close(fdout);
        for_every_command2(&tmpin,&tmpout, &fdin, global, A);
         A = A->next;
    }
    dup2(tmpin,0);
    dup2(tmpout,1);
    close(tmpout);
    close(tmpin);
    return 1;
}
 t_env* make_history(char *str)
 {
     t_env *a = malloc(sizeof(t_env));
     if ( a == 0)
        return 0;
     a->content = ft_strdup(str);
     a->next = 0;
     return (a);
 }
 void add_to_history(char *str, t_env **start)
 {
     if ( *start == 0)
     {
         *start = make_history(str);
         return ;
     }
    t_env *temp = *start;
    while(temp->next != 0)
        temp = temp->next;
    temp->next =  make_history(str);
 }
 


int ft_chec_in(t_env *A)
{
    if (A->comand != 0 && ft_strncmp("exit",A->comand[0],5) == 0)
        return 1;
    if (A->comand != 0 && ft_strncmp("export",A->comand[0],7) == 0)
        return 1;
    if (A->comand != 0 && ft_strncmp("cd",A->comand[0],3) == 0)
        return 1;
    if (A->comand != 0 && ft_strncmp("unset",A->comand[0],6) == 0)
        return 1;
    return 0;
}
void ft_exit(t_global *global)
{
    (void) global;
    exit (0);
}
int ft_go_in(t_global *global,t_env *A)
{
    if (A->comand != 0 && ft_strncmp("exit",A->comand[0],5) == 0)
        ft_exit(global);
    if (A->comand != 0 && ft_strncmp("export",A->comand[0],7) == 0)
        global->exit_code = (export_env(global,A));
    if (A->comand != 0 && ft_strncmp("cd",A->comand[0],3) == 0)
        global->exit_code = (fd_cd(global, A));
    if (A->comand != 0 && ft_strncmp("unset",A->comand[0],6) == 0)
        global->exit_code = (unset_env(global,A));
    return 1;
}
int pre_exquve(t_global *global,t_env *A)
{
    if (A == 0)
        return 0;
    if ( A->next == 0 && ft_chec_in(A)== 1)
        return (ft_go_in(global,A));
    pip_fd(global);
    t_env *temp = global->list_of_command;
     while (temp != 0 )
    {
        global->wait_now = temp->end;
        waitpid(temp->end, &(global->exit_code), 0);
        global->exit_code = WEXITSTATUS(global->exit_code);
        temp = temp->next;
    }
    free_env(A);
    global->wait_now = 0;
    return 0;
}

void	sig_int(int code)
{
	(void) code;
    if (glo->par == 1)
		 ft_printf("\nmini->");
    glo->exit_status = 1; 
}

void	sig_quit(int code)
{
	//char	*nbr;
(void) code;
    if (glo->par == 1)
        return;
		 //ft_printf("\nmini->");
    else
    ft_printf ("QUIT %d\n",code);
    glo->exit_status = 1; 
}
int main(int a, char **argv, char *env[])
{
    (void) a;
    (void) argv;
    (void) env;
    t_g gl;
    glo = &gl;
    gl.exit = 0;
    gl.par= 1;
    gl.exit_status = 0;
    t_global global;
    global.history = 0;
     global.wait_now = 0;
    global.envn = make_env(env);
    (global.exit_code) = 0;
    global.list_of_command = NULL; //A
    signal(SIGINT, &sig_int);
	signal(SIGQUIT, &sig_quit);
    while (gl.exit == 0)
    {
        if(  gl.exit_status == 0)
            ft_printf("mini->");
         gl.exit_status = 0;
        global.comand_line = get_input();  
        if(global.comand_line == 0)
            break;
        if (ft_isallspase(global.comand_line) == 1)
        {
            free(global.comand_line);          
            continue;
        }      
        add_to_history(global.comand_line, &(global.history)); 
        global.list_of_command = make_command(global.comand_line ,&(global)); 
        pre_exquve(&global,global.list_of_command);
        ft_free_void(global.comand_line);       
    }
    ft_free_fail(&(global.fail));
    free_env(global.envn );
    free_env(global.history);
    
}