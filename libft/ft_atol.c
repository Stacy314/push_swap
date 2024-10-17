/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anastasiia <anastasiia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:29:23 by apechkov          #+#    #+#             */
/*   Updated: 2024/09/30 12:58:07 by anastasiia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long    ft_atol(const char *str)
{
    long    result;
    int     sign;
    int     i;

    result = 0;
    sign = 1;
    i = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
        sign = (str[i++] == '-') ? -1 : 1;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i++] - '0');
        if (result * sign > INT_MAX || result * sign < INT_MIN)
            break;
    }
    return (result * sign);
}
