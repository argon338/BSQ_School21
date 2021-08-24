/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_string.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:33:07 by slight            #+#    #+#             */
/*   Updated: 2021/08/22 17:33:09 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_STRING_H
# define CUSTOM_STRING_H

int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_realloc(char *src, int new_size);
char	*ft_char_push_back(char *src, char symbol, int *memsize);
void	ft_empty_string(char *str, int memsize);

#endif //CUSTOM_STRING_H
