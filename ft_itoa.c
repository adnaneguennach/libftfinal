/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguennac <aguennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:10:06 by aguennac          #+#    #+#             */
/*   Updated: 2025/10/20 14:37:57 by aguennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_intlen(int n)
{
	long	num;
	int		len;

	num = n;
	if (num < 0)
		num = -num;
	len = 1;
	while (num / 10)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;

	num = n;
	len = ft_intlen(n);
	if (n < 0)
		len++;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';

	if (num < 0)
		num = -num;

	while (len-- > 0)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
		if (len == 0 && n < 0)
			str[0] = '-';
	}

	return (str);
}
