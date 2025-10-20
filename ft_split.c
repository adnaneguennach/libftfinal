/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguennac <aguennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:10:31 by aguennac          #+#    #+#             */
/*   Updated: 2025/10/20 14:37:13 by aguennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char sep)
{
	if (c == sep){
		return (1);
	}
	return (0);
}

static int	count_words(const char *str, char sep)
{
	int	words;

	words = 0;
	while (*str)
	{
		while (*str && is_sep(*str, sep))
			str++;
		if (*str && !is_sep(*str, sep))
		{
			words++;
			while (*str && !is_sep(*str, sep))
				str++;
		}
	}
	return (words);
}

static char	*word_dup(const char *start, const char *end)
{
	char	*res;
	int		len;
	int		i;

	len = end - start;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = start[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static void	free_all(char **arr, int i)
{
	while (i-- > 0)
		free(arr[i]);
	free(arr);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	int		wc;
	int		i;
	const char	*start;

	if (!s)
		return (NULL);
	wc = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && is_sep(*s, c))
			s++;
		if (*s)
		{
			start = s;
			while (*s && !is_sep(*s, c))
				s++;
			arr[i] = word_dup(start, s);
			if (!arr[i++])
			{
				free_all(arr, i - 1);
				return (NULL);
			}
		}
	}
	arr[i] = NULL;
	return (arr);
}
