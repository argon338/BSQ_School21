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

//defined in custom_string.c
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_realloc(char *src, int new_size);
char	*ft_char_push_back(char *src, char symbol, int *memsize);
void	ft_empty_string(char *str, int memsize);
//defined in ft_atoi.c
int		ft_atoi(char *str);
int		ft_isspace(int c);
int		ft_is_digit(int c);
int		ft_is_number(const char *str);
int		ft_is_printable(char c);
//defined in ft_string.c
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(const char *str);

#endif //CUSTOM_STRING_H
