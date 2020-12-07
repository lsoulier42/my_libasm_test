/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:09:48 by lsoulier          #+#    #+#             */
/*   Updated: 2020/12/07 12:16:15 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void valid_test(int return_value)
{
	if (return_value == 1)
		printf("\x1b[32m[OK]\x1b[0m\n");
	else
		printf("\x1b[31m[KO]\x1b[0m\n");
}

void print_title(char *str)
{
	printf("\x1b[33m%s\x1b[0m\n", str);
}
