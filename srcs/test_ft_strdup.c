/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:09:29 by lsoulier          #+#    #+#             */
/*   Updated: 2020/12/07 12:53:06 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	test_ft_strdup(void)
{
	char *str_returned_real;
	char *str_returned_ft;
	char *test_strs[] = {"a", "", "T'es tendue comme une crampe... Si t'es tendue... Si je te dis t'es tendue, t'es tendue !! C'est pas à toi de dire je ne suis pas tendue !! Je te dis t'es tendue Natacha c'est tout ! Alors tu me dis oui Claudy, c'est vrai je suis tendue, je ne suis pas à mon aise. Il faut que tu te laisses venir vers moi, et je viendrais te chercher t'inquiète pas..", NULL};
	int i = -1;

	print_title("Tests for ft_strdup function :");
	while (test_strs[++i])
	{
		printf("For the following string   : |%s|\n", test_strs[i]);
		str_returned_real = strdup(test_strs[i]);
		if (!str_returned_real)
			return (0);
		str_returned_ft = ft_strdup(test_strs[i]);
		if (!str_returned_ft)
		{
			free(str_returned_real);
			return (0);
		}
		printf("The return of strdup is    : |%s|\n", str_returned_real);
		printf("The return of ft_strdup is : |%s|\n", str_returned_ft);
		valid_test(strcmp(str_returned_real, str_returned_ft) == 0);
		free(str_returned_real);
		free(str_returned_ft);
	}
	return (1);
}
