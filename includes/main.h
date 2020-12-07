/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 03:30:59 by lsoulier          #+#    #+#             */
/*   Updated: 2020/12/07 12:39:44 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include "libasm.h"
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# define BUFFER_SIZE 5000

int		map_function(int arg_input);
int		test_all_functions(void);
int		test_ft_strlen(void);
int		test_ft_strcpy(void);
int		test_ft_strcmp(void);
int		test_ft_write(void);
int		test_ft_read(void);
int		test_ft_strdup(void);
void	valid_test(int return_value);
void	print_title(char *str);
#endif
