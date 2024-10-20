/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apechkov <apechkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:34:04 by apechkov          #+#    #+#             */
/*   Updated: 2024/10/20 17:36:02 by apechkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int ft_putstr_fd(char *s, int fd)
// {
//     int len;
//     ssize_t result;

//     if (!s)
//         return (write(fd, "(null)", 6));
//     len = 0;
//     while (s[len])
//         len++;
//     result = write(fd, s, len);
//     if (result == -1)
//         return (-1); // Помилка запису
//     return ((int)result);
// }


int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	if (fd < 0)
    	return (-1); // Невалідний файловий дескриптор
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}
/*int	main(void)
{
	char *my_string = "Hello, World!"; 
	int fd = 2;
	ft_putstr_fd(my_string, fd);
	return(0);
}*/
