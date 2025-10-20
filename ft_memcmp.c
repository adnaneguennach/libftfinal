/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguennac <aguennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:53:10 by aguennac          #+#    #+#             */
/*   Updated: 2025/10/18 14:57:11 by aguennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s;
	const unsigned char	*d;

	s = (const unsigned char *)s1;
	d = (const unsigned char *)s2;
	while (n--)
	{
		if (*s != *d)
			return (*s - *d);
		s++;
		d++;
	}
	return (0);
}
