#include <stdlib.h>

static int	ft_len(const char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != 0)
	{
		i++;
	}
	return (i);
}

static void	ft_cop(const char *s1, char *s2, int len)
{
    int i = 0;
    while ( i != len)
    {
        s2[i] = s1[i];
        i++;
    }
}

char	*ft_strjoin2(char const *s1, char const *s2 ,char const *s3 )
{
	int		i;
	int		j;
    int k;
	char	*ret;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = ft_len(s1);
	j = ft_len(s2);
    k = ft_len(s3);
	ret = malloc(i + j + k + 1);
	if (ret == 0)
		return (0);
	ft_cop(s1, ret, i);
	ft_cop(s2, ret + i, j);
    ft_cop(s3, ret + i + j, k );
    ret[i+j+k] = 0;
	return (ret);
}
