/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 03:36:05 by lsoulier          #+#    #+#             */
/*   Updated: 2020/12/05 18:06:50 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	test_all_functions(void)
{
	if (!test_ft_strlen() || !test_ft_strcpy()
		|| !test_ft_strcmp() || !test_ft_write()
		|| !test_ft_read() || !test_ft_strdup())
		return (0);
	return (1);
}

int	map_function(int arg_input)
{
	int (*test_functions[7])(void);

	test_functions[0] = &test_ft_strlen;
	test_functions[1] = &test_ft_strcpy;
	test_functions[2] = &test_ft_strcmp;
	test_functions[3] = &test_ft_write;
	test_functions[4] = &test_ft_read;
	test_functions[5] = &test_ft_strdup;
	test_functions[6] = &test_all_functions;
	if (!(*test_functions[arg_input])())
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int arg;

	if (ac == 1)
	{
		printf("Choose a number in param to test libasm:\n");
		printf("0. ft_strlen\n");
		printf("1. ft_strcpy\n");
		printf("2. ft_strcmp\n");
		printf("3. ft_write\n");
		printf("4. ft_read\n");
		printf("5. ft_strdup\n");
		printf("6. all functions\n");
	}
	else if (ac == 2)
	{
		arg = atoi(av[1]);
		if (arg >= 0 && arg <= 6)
		{
			if (!map_function(arg))
				printf("Error\nThe test function failed\n");
		}
		else
			printf("Error\nNo test is matching your number.\n");
	}
	else
		printf("Error\nInvalid number of argument.\n");
	return (0);
}
