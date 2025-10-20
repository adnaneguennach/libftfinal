/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguennac <aguennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:10:31 by aguennac          #+#    #+#             */
/*   Updated: 2025/10/20 13:45:36 by aguennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}

static int	count_words(char *str, char *sep)
{
	int	words;

	words = 0;
	while (*str)
	{
		while (*str && is_sep(*str, sep))
			str++;
		if (*str)
		{
			words++;
			while (*str && !is_sep(*str, sep))
				str++;
		}
	}
	return (words);
}

static char	*word_dup(char *start, char *end)
{
	char	*res;
	int		len;
	int		i;

	len = end - start;
	res = malloc(len + 1);
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

char	**ft_split(char *str, char *sep)
{
	char	**arr;
	int		wc;
	int		i;
	char	*start;

	wc = count_words(str, sep);
	arr = malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && is_sep(*str, sep))
			str++;
		if (*str)
			start = str;
		while (*str && !is_sep(*str, sep))
			str++;
		arr[i++] = word_dup(start, str);
	}
	arr[i] = NULL;
	return (arr);
}
