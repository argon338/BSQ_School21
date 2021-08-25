/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkrishna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:49:58 by hkrishna          #+#    #+#             */
/*   Updated: 2021/08/25 18:50:00 by hkrishna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCER_H
# define PARCER_H

# include "../BSQ.h"
//Defined in parce_line.c
void	free_array(int **a, int i);
int		**parce_line(char *datafile, t_map map_parameters);
//Defined in header_check.c
t_map	ft_check_header(char *memory_stick);
//Defined in body_check.c
int		check_map_body_strings(const char *memory_stick, t_map *to_check);
int		check_map_body_symbols(const char *memory_stick, t_map to_check);
//Defined in stdin_handler.c
char	*stdin_to_string(void);
//Defined in parce_file.c
int		parce_from_data_file(char *datafile, t_map *my_header);
int		ft_display_file(char **filename);

#endif //PARCER_H
