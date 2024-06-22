/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   units2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nposidon <nposidon>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:10:44 by nposidon          #+#    #+#             */
/*   Updated: 2022/04/06 17:33:49 by nposidon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strnstr(const char *str, const char *need, int len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	ft_free1(void *a);

char	**env(char *envp[])
{
	char	*patch;

	while (*envp && !ft_strnstr(*envp, "PATH=/", -1))
	{
		envp++;
	}
	if (!*envp)
		return (0);
	patch = *envp + 5;
	return (ft_split(patch, ':'));
}

void	ft_free_char(char **m)
{
	char	**temp;

	if (!m)
		return ;
	temp = m;
	while (*temp)
		ft_free1(*(temp++));
	ft_free1(m);
}

char	*find(char *name, char **environ)
{	
	char	**temp;
	char	**path;
	char	*str;

	if (access(name, X_OK) == 0)
		return (name);
	path = env(environ);
	temp = path;
	str = ft_strjoin(*path, name);
	while (path && *path && access(str, X_OK))
	{
		ft_free1(str);
		path++;
		str = ft_strjoin(*path, name);
	}
	ft_free(temp);
	if (access(str, X_OK) == 0)
		return (str);
	perror("can't find command");
	ft_free1(str);
	return (0);
}

void	ft_free1(void *a)
{
	if (a)
		free(a);
}

void	error0(char *str)
{
	perror(str);
	exit(1);
}
