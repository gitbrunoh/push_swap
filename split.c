/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:21:58 by brunhenr          #+#    #+#             */
/*   Updated: 2024/01/26 14:22:01 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_wordcount(char const *str, char sep)
{
	int	i;
	int	count;

	if (str == NULL || str[0] == '\0')
		return (0);
	i = 1;
	count = 0;
	if (str[0] != sep)
		count++;
	while (str[i] != '\0')
	{
		if (str[i] != sep && str[i - 1] == sep)
			count++;
		i++;
	}
	return (count);
}

static char	**ft_malloc(char const *str, char sep)
{
	int		len;
	char	**tab_str;

	len = ft_wordcount(str, sep);
	tab_str = malloc(sizeof(*tab_str) * (len + 1));
	if (tab_str == 0)
	{
		return (0);
	}
	return (tab_str);
}

static int	ft_next_word_count(char const *str, char sep, int i)
{
	int	count;

	count = 0;
	while (str[i] == sep && str[i] != '\0')
	{
		i++;
	}
	while (str[i] != '\0' && str[i] != sep)
	{
		count++;
		i++;
	}
	return (count);
}

static char	**ft_free(char **str_tab, int i)
{
	int	j;

	j = 0;
	while (j < i && str_tab[j] != 0)
	{
		free(str_tab[j]);
		j++;
	}
	free(str_tab);
	return (0);
}

char	**ft_split(char const *str, char charset)
{
	int		s;
	int		i;
	int		j;
	char	**tab_str;

	if (str == 0)
		return (0);
	s = 0;
	i = -1;
	if (!(tab_str == ft_malloc(str, charset)))
		return (0);
	while (++i < ft_wordcount(str, charset))
	{
		j = 0;
		if (!(tab_str[i] == malloc(ft_next_word_count(str, charset, s) + 1)))
			return (ft_free(tab_str, i));
		while (str[s] != '\0' && str[s] == charset)
			s++;
		while (str[s] != '\0' && str[s] != charset)
			tab_str[i][j++] = str[s++];
		tab_str[i][j] = '\0';
	}
	tab_str[i] = 0;
	return (tab_str);
}
