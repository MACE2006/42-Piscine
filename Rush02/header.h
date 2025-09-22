/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmarsha <evmarsha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:18:51 by evmarsha          #+#    #+#             */
/*   Updated: 2025/09/21 21:18:55 by evmarsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char	*read_file(char *dict_name);
char	*ft_strcat(char *dest, char *src);
char	*ft_strstr(char *str, char *to_find);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
char	*make_nbr_str(char *argv);
void	print_aword(char *needle);
void	str_len_three(char *my_buff, char *str);
void	str_len_two(char *my_buff, char *str);
void	print_three_word(char *my_buff, char *str);
char	*my_strncpy(char *dest, char *src, unsigned int n);
void	print_powers(char *my_buff, int level);
void	make_substr(char *my_buff, char *str);
void	main_helper(char *my_buff, int argc, char *argv[], char *nbr_str);
char	*ft_atoi(char *str);

#endif
