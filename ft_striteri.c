/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguennac <aguennac@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:10:36 by aguennac          #+#    #+#             */
/*   Updated: 2025/10/20 13:10:36 by aguennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void to_upper(unsigned int i, char *s)
{
    (void)i;
    if (*s >= 'a' && *s <= 'z')
        *s = *s - ('a' - 'A');
}

void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    size_t i;

    if (!s || !f)
        return ;
    i = 0;
    while (s[i])
    {
        f(i, &s[i]);
        i++;
    }
}
