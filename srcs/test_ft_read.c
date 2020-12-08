/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:08:47 by lsoulier          #+#    #+#             */
/*   Updated: 2020/12/08 14:41:02 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	test_ft_read(void)
{
	int fd_real;
	int fd_ft;
	char *test_files[] = {"./test_files/empty_file", 
		"notfound_file", "/bin/", "./test_files/zelda_file", NULL};
	int i = -1;
	int ret_real;
	int ret_ft;
	char buf_real[BUFFER_SIZE + 1];
	char buf_ft[BUFFER_SIZE + 1];
	int errno_real;
	int errno_ft;

	print_title("Tests for ft_read function");
	printf("The BUFFER_SIZE is %d:\n", BUFFER_SIZE);
	while (test_files[++i])
	{
		printf("The file tested is |%s|\n", test_files[i]);
		fd_real = open(test_files[i], O_RDONLY);
		fd_ft = open(test_files[i], O_RDONLY);
		ret_real = -1;
		ret_ft = -1;
		errno_real = 0;
		errno_ft = 0;
		bzero(buf_real, BUFFER_SIZE + 1);
		bzero(buf_ft, BUFFER_SIZE + 1);
		if (strcmp(test_files[i], "notfound_file") != 0
			&& (fd_real == -1 || fd_ft == -1))
		{
			printf("%s\n", strerror(errno));
			if (fd_real != -1)
				close(fd_real);
			if (fd_ft != -1)
				close(fd_ft);
			return (0);
		}
		while ((ret_real = read(fd_real, buf_real, BUFFER_SIZE)) != -2)
		{
			printf("Read returned %d\n", ret_real);
			if (ret_real == -1)
			{
				errno_real = errno;
				printf("Errno for read() from libc was set with %d\n", errno_real);
				printf("Strerror with read() from libc returns |%s|\n", strerror(errno_real));
			}
			else
				buf_real[ret_real] = '\0';
			errno = 0;	
			ret_ft = ft_read(fd_ft, buf_ft, BUFFER_SIZE);
			printf("ft_read returned %d\n", ret_ft);
			printf("The cmp of functions returns is : ");
			valid_test(ret_real == ret_ft);
			if (ret_ft < 0)
			{
				errno_ft = errno;
				printf("Errno for ft_read was set with %d\n", errno_ft);
				printf("Strerror with ft_read() returns |%s|\n", strerror(errno_ft));
			}
			else
				buf_ft[ret_ft] = '\0';
			if (ret_real == -1)
			{
				printf("The cmp of errno values is :");
				valid_test(errno_real == errno_ft);
				break ;
			}
			if (ret_real != -1)
				printf("The buffer was filled with |%s| with read() from libc\n", buf_real);
			if (ret_ft != -1)	
				printf("The buffer was filled with |%s| with ft_read()\n", buf_ft);
			printf("The cmp of the buffers is :");	
			valid_test(strcmp(buf_real, buf_ft) == 0);
			if (ret_real == 0 && ret_ft == 0)
				break ;
		}
		close(fd_real);
		close(fd_ft);
	}
	ret_ft = 0;
	bzero(buf_ft, BUFFER_SIZE + 1);
	print_title("\nThe next part is to test ft_read with STDIN");
	print_title("Press Ctrl+D when you're done");
	while ((ret_ft = ft_read(1, buf_ft, BUFFER_SIZE)) != 0)
	{
		if (ret_ft < BUFFER_SIZE)
			buf_ft[ret_ft - 1] = '\0'; //to trim \n
		else
			buf_ft[ret_ft] = '\0';
		if (ret_ft == -1)
		{
			printf("Error while readind STDIN\n");
			printf("Errno was set to %d\n", errno);
			printf("%s\n", strerror(errno));
			break ;
		}
		printf("Ft_read returns : %d\n", ret_ft);
		printf("And the buffer was filled with |%s|\n", buf_ft);
	}
	return (1);
}
