/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:07:46 by lsoulier          #+#    #+#             */
/*   Updated: 2020/12/07 12:25:09 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char	*ret_cmp(int return_value)
{
	char	*ret_str;

	ret_str = NULL;
	if (return_value == 0)
		ret_str = "is 0";
	else if (return_value < 0)
		ret_str = "is a negative value";
	else
		ret_str = "is a positive value";
	return (ret_str);	
}

int			test_ft_strcmp(void)
{
	char	*test_strs[] = {"", "", "a", "", "", "b",
		"a", "b", "aa", "dd", "test", "test", "zest", 
		"best", "djfndjfadfj", "ejfnjweifnfiw", "abc", "abd", 
		"\xff", "\xff\xff", "anticonstitutionnellement", 
		"anticonstitutionnellement", "anticonstitutionnellement1", 
		"anticonstitutionnellement", NULL};
	int i = 0;
	char *ret_real;
	char *ret_ft;
		
	print_title("Tests for ft_strcmp function :");
	while(test_strs[i])
	{
		ret_real = NULL;
		ret_ft = NULL;
		printf("Test with the following strings s1=|%s| et s2=|%s|\n", 
			test_strs[i], test_strs[i + 1]);
		ret_real = ret_cmp(strcmp(test_strs[i], test_strs[i + 1]));
		printf("The return of strcmp %s\n", ret_real);
		ret_ft = ret_cmp(ft_strcmp(test_strs[i], test_strs[i + 1]));
		printf("The return of ft_strcmp %s\n", ret_ft);
		valid_test(strcmp(ret_real, ret_ft) == 0);
		i += 2;
	}
	return (1);
}
