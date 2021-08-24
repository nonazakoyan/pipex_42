/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nozakoya <nozakoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:57:37 by nozakoya          #+#    #+#             */
/*   Updated: 2021/08/22 16:57:39 by nozakoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	if (!s)
		return (0);
	size_t l;

	l = 0;
	while (s[l] != 0)
		l++;
	return (l);
}


static int	count_words(const char *str, char c)
{
	int i;
	int trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char		**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (!s || !(split = malloc((count_words(s, c) + 1) * sizeof(char *))))
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}


char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(join))
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i] != '\0')
			join[j++] = s1[i++];
	i = 0;
	if (s2)
		while (s2[i] != '\0')
			join[j++] = s2[i++];
	join[j] = '\0';
	//free(s1);
	return (join);
}

void error(void)
{
	perror ("Error");
	exit (EXIT_FAILURE);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*d2;

	d1 = (unsigned char*)s1;
	d2 = (unsigned char*)s2;
	i = 0;
	while ((d1[i] || d2[i]) && i < n)
	{
		if (d1[i] != d2[i])
			return (d1[i] - d2[i]);
		i++;
	}
	return (0);
}
