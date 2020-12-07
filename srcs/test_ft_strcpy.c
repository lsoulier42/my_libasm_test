/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:07:19 by lsoulier          #+#    #+#             */
/*   Updated: 2020/12/07 12:24:21 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	test_ft_strcpy(void)
{
	char dest_real[1000];
	char dest_ft[1000];
	char *test_strs[] = {"Batman et Robin", "", "Je ne crois pas qu'il y ait de bonnes ou de mauvaises situations moi si je devais resumer ma vie aujourd'hui, je dirais que c'est avant des rencontres. Des gens qui m'ont tendu la main a un moment ou je ne pouvais pas ou j'etais seul chez moi. Et c'est marrant de se dire que c'est les rencontres qui forgent une destinee parce que lorsqu'on a le gout de la chose, le gout de la chose bien faite, le beau geste, on ne trouve pas forcement l'interlocuteur a qui parler. Alors moi ce n'est pas mon cas puisque moi j'ai pu et je dis merci a la vie je chante la vie je danse la vie. Et quand les gens me demandent mais comment faites vous pour avoir cette humanite ?, je leur reponds que c'est l'amour. L'amour du peuple qui m'a pousse, aujourd'hui a entreprendre une construction mecanique mais, qui sait, peut-etre demain me mettre au service de la communaute, a faire le don de l'autre, le don de... de soi", NULL};
	int i = -1;

	
	print_title("Tests for ft_strcpy function :");
	while (test_strs[++i])
	{
		bzero(dest_real, 1000);
		bzero(dest_ft, 1000);
		printf("For the following string   : |%s|\n", test_strs[i]);
		printf("The return of strcpy is    : |%s|\n", strcpy(dest_real, test_strs[i]));
		printf("The return of ft_strcpy is : |%s|\n", ft_strcpy(dest_ft, test_strs[i]));
		valid_test(strcmp(dest_real, dest_ft) == 0);
	}
	return (1);
}
