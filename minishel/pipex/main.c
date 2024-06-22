/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:10:57 by nposidon          #+#    #+#             */
/*   Updated: 2022/04/05 18:34:29 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

char	**ft_split(char const *s, char c);
void	fd_first(char *fd_command, char **env, int file1, int pip);
void	fd_second(char *fd_command, char **env, int file2, int pip);
void	ft_free(char **m);
void	ft_free1(void *a);
void	error0(char *str);
char	*find(char *name, char **environ);

void	fd_close(int a, int b)
{
	close(a);
	close(b);
}

int	main7(int a, char **argv, char *env[])
{
	int		pip[2];
	pid_t	pd;
	int		file1;
	int		file2;

	if (a != 5)
		exit(1);
	file1 = open(argv[1], O_RDONLY);
	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file1 == -1 || file2 == -1 || pipe(pip) == -1)
		error0("Error");
	pd = fork();
	if (pd < 0)
		error0("Error");
	if (pd == 0)
	{
		fd_close(file1, pip[1]);
		fd_second(argv[3], env, file2, pip[0]);
		fd_close(pip[0], file2);
		exit(1);
	}
	fd_close(file2, pip[0]);
	fd_first(argv[2], env, file1, pip[1]);
	fd_close(file1, pip[1]);
	exit(1);
}

void	fd_first(char *fd_command, char **env, int file1, int pip)
{
	char	**command1;
	char	*y;

	if (dup2(file1, 0) == -1 || dup2(pip, 1) == -1)
		error0("dub2");
	command1 = ft_split(fd_command, ' ');
	if (command1 == 0)
		exit(1);
	y = find(command1[0], env);
	if (y != 0)
		execve(y, command1, env);
	ft_free1(y);
	ft_free(command1);
	close(1);
	close(0);
	exit(1);
}

void	fd_second(char *fd_command, char **env, int file2, int pip)
{
	char	*y;
	char	**command1;

	if (dup2(file2, 1) == -1 || dup2(pip, 0) == -1)
		error0("dub2");
	command1 = ft_split(fd_command, ' ');
	if (command1 == 0)
		exit(1);
	y = find(command1[0], env);
	if (y != 0)
		execve(y, command1, env);
	ft_free1(y);
	ft_free(command1);
	close(1);
	close(0);
	exit (1);
}
