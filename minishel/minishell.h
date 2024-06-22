/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 17:13:21 by nposidon          #+#    #+#             */
/*   Updated: 2022/05/13 05:26:33 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H
# define BUFFER_SIZE = 100
#include "gnl/get_next_line.h"
#include "print/ft_printf.h"
#include "libft/libft.h"
#include <fcntl.h>
# define ERROR 1
# define OK 0
typedef struct s_list5
{
	char *name;
    char *content;
    int end;
    char ** comand;
	struct s_list5	*next;
}t_env;

typedef struct s_list60
{
	int exit;
    int par;
    int exit_status;

}t_g;
typedef struct s_list6
{
	char *str;
    int len;
    int i;

}t_str;
typedef struct s_list9
{
	char *in;
    char *out;
    char *out_append;
    char *limit;

}t_fail;
typedef struct s_list7
{
	char **str;
    int len;
    int i;

}t_str_of_str;
typedef struct s_list8
{
	t_env *history;
    t_env *envn;
    int exit_code;
    t_fail fail;
    t_env *list_of_command;
    char *comand_line;
    int wait_now; 
	
}t_global;
void ft_exit(t_global *global);
int export_env(t_global *global,t_env *A);
int fd_cd(t_global *global,t_env *A);
int fd_pwd(t_global *global,t_env *A);
 int unset_env(t_global *global,t_env *A);

void ft_free_fail(t_fail *fail);
void ft_free_env(t_env **f);
int ft_isallspase(char *a);
int chec_last_sym(char *str);
char *get_input();
int chec_str(char *str);
int one_command(char *str);
t_env *t_env_of_command(char*str,int *j,t_global *global);
t_env *make_command(char *str, t_global *global);
void	ft_free_char(char **m);
int ft_free_void(void *A);
void free_env(t_env *G );
int len_env(char * str, char z);
void fool_content_env(char *str,char * name, char * content);
void take_content_env(char *str,char ** name, char ** content);
t_env *make_env(char *env[]);
char	**ft_PATH(t_env *envp);
char **remake_env(t_env *envp);
char * find_command(char **path,char * name);
int ft_execve(t_global *global, t_env *A);
int ft_chec_str(const char *str1, const char *str2);
int add_to_ft_str(t_str *s,char a);
int add_to_ft_str_of_str(t_str_of_str *s,char *a);
int find_dollar(t_env *env,char *str,t_str *result,int *i,int exit);
char **command_6777(char *command, t_env *env,int exit);
void ft_free_one_env(t_env *a);
int ft_chec_in(t_env *A);
#endif