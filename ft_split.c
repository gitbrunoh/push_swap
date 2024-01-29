#include "push_swap.h"

static int	count_w(char *str)
{
	int	i;
	int	wc;

    i = 0;
	wc = 0;
    while (str[i])
    {
        while (str[i] == ' ')
            i++;
        if (str[i] != '\0')
            wc++;
        while (str[i] != '\0' && str[i] != ' ')
        	i++;
    }
	return(wc);
}

static char	*ft_strcopy(char *str1, char *str2, int n)
{
	int i;

	i = 0;
        while ((n != 0) && (str2[i] != '\0'))
	{
		str1[i] = str2[i];
		n--;
		i++;
	}
        str1[i] = '\0';
	return (str1);
}
         
static char **allocate_memory(char **out, int k, int size)
{
	out[k] = (char *)malloc(sizeof(char) * size);
	if (out[k] == NULL)
	{
		while (k >= 0)
			free(out[k--]);
		free(out);
		return (NULL);
	}
	return out;
}

static char **handle_token(char **out, char *str, int *i, int *k)
{
	int j = *i;
	while (str[*i] != '\0' && str[*i] != ' ')
		(*i)++;
	if (*i > j)
	{
		out = allocate_memory(out, *k, (*i - j) + 1);
		if (out == NULL)
			return (NULL);
		ft_strcopy(out[*k], str + j, *i - j);
		out[*k][*i - j] = '\0';
		(*k)++;
	}
	return out;
}

static char **skip_spaces(char **out, char *str, int *i, int *k)
{
	while (str[*i] == ' ')
		(*i)++;
	out = handle_token(out, str, i, k);
	return out;
}

char **ft_splitpush(char *str)
{
	int i = 0;
	int k = 0;
	char **out;

	out = malloc((count_w(str) + 2) * sizeof(char *));
	if (out == NULL)
		return (NULL);
	out[0] = (char *)malloc(sizeof(char));
	if (out[0] == NULL)
	{
		free(out);
		return (NULL);
	}
	out[0][0] = '\0';
	k++;
	while (str[i])
	{
		out = skip_spaces(out, str, &i, &k);
		if (out == NULL)
			return (NULL);
	}
	out[k] = NULL;
	return (out);
}