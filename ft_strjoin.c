/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguennac <aguennac@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:10:39 by aguennac          #+#    #+#             */
/*   Updated: 2025/10/20 13:10:39 by aguennac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int ft_strlen(char const *s){
    int i = 0;
    while(*s){
        s++;
        i++;
    }
    return i;
}

char *ft_strjoin(char const *s1, char const *s2)
{
    if(!s1 || !s2){
        return NULL;
    }

    size_t s1_len = ft_strlen(s1);
    size_t s2_len = ft_strlen(s2);
    size_t i = 0;
    size_t j = 0;
    size_t total_len = s1_len + s2_len;
    char *res = malloc(sizeof(char) * (total_len + 1));
    if(!res){
        return NULL;
    }

    while(i < s1_len){
        res[i++] = s1[j++];
    }
    j = 0;
    while(j < s2_len){
        res[i++] = s2[j++];
    }
    res[i] = '\0';
    return res;


}