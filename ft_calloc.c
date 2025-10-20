/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguennac <aguennac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:28:19 by aguennac          #+#    #+#             */
/*   Updated: 2025/10/20 14:51:22 by aguennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t total_size;
	void *ptr;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return NULL;

	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);

	ft_memset(ptr, 0, total_size);

	return (ptr);
}
