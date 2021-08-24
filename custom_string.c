/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:30:56 by slight            #+#    #+#             */
/*   Updated: 2021/08/22 17:32:39 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "custom_string.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;
	int	end_of_line;

	i = 0;
	end_of_line = 0;
	while (!end_of_line)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
			end_of_line = 1;
		i++;
	}
	return (dest);
}

char	*ft_realloc(char *src, int new_size)
{
	char	*new;

	new = (char *) malloc(sizeof(char) * new_size);
	if (new == NULL)
		return (NULL);
	new = ft_strcpy(new, src);
	free (src);
	return (new);
}

char	*ft_char_push_back(char *src, char symbol, int *memsize)
{
	int	strsize;

	strsize = ft_strlen(src);
	if (strsize + 1 >= *memsize)
	{
		*memsize *= 2;
		src = ft_realloc(src, *memsize);
	}
	if (src == NULL)
		return (NULL);
	src[strsize] = symbol;
	src[strsize + 1] = '\0';
	return (src);
}

void	ft_empty_string(char *str, int memsize)
{
	int	i;

	i = 0;
	while (i < memsize)
	{
		str[i] = '\0';
		i++;
	}
}
