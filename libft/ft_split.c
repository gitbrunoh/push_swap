/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:59:28 by brunhenr          #+#    #+#             */
/*   Updated: 2023/10/25 15:07:50 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_count(char const *s, char c)
{
	unsigned int	len;
	unsigned int	count;
	unsigned int	i;
	unsigned int	old_i;

	count = 0;
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		while (s[i] == c)
			i++;
		old_i = i;
		while (s[i] != c && s[i])
			i++;
		if (i > old_i)
			count += 1;
	}
	return (count);
}

static void	get_tokens(char **strs, char const *s, char c)
{
	char const	*buffer;

	buffer = s;
	while (*buffer)
	{
		while (*s == c)
			++s;
		buffer = s;
		while (*buffer && *buffer != c)
			++buffer;
		if (buffer > s)
		{
			*strs = ft_substr(s, 0, buffer - s);
			s = buffer;
			++strs;
		}
	}
	*strs = NULL;
	return ;
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		n;

	n = words_count(s, c);
	strings = (char **)malloc(sizeof(char *) * (n + 1));
	if (strings == NULL)
		return (NULL);
	get_tokens(strings, s, c);
	return (strings);
}

/*int	main(void)
{
	char	*str = " 42 born 2 code! ";
	char	c = ' ';
	char	**result;
	char	**temp;

	result = ft_split(str, c);
	temp = result;	
	while (*temp != NULL)
	{
    		printf("%s\n", *temp);
    		free(*temp);
    		temp++;
	}
	free(result);
	return (0);
}*/
