/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrishna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:36:45 by hkrishna          #+#    #+#             */
/*   Updated: 2021/08/25 18:36:47 by hkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../BSQ.h"
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putstr(const char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
		write(1, &str[counter++], 1);
}
