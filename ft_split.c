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

static char	*ft_strlcpy(char *str1, char *str2, int n)
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
         
char    **ft_split(char *str)
{
    int	i = 0;
    int	j = 0;
    int	k = 0;
    char	**out;

    out = malloc((count_w(str) + 1) * sizeof(char *));
    if (out == NULL)
        return (NULL);
    while (str[i])
    {
        while (str[i] == ' ')
            i++;
        j = i;
        while (str[i] != '\0' && str[i] != ' ')
            i++;
        if (i > j)
        {
            out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
            if (out[k] == NULL)
            {  
                while (k >= 0)
                    free(out[k--]);
                free(out);
                return (NULL);
            }
            ft_strlcpy(out[k], str + j, i - j);
            out[k][i - j] = '\0';
            k++;
        }
    }
    out[k] = NULL;
    return (out);
}  