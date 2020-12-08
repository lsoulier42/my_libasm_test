/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <lsoulier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:08:21 by lsoulier          #+#    #+#             */
/*   Updated: 2020/12/08 14:38:27 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void ft_putnbr(int n)
{
	long nb;
	char digit;
	
	nb = n;
	if (n < 0)
	{
		write(1, "-", 1);
		nb = -(long)n;
	}
	if (nb > 10)
		ft_putnbr(nb / 10);
	digit = nb % 10 + '0';	
	write(1, &digit, 1);
}

static void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void ft_write_unit(int fd, char *str)
{
	int ret_real;
	int ret_ft;
	int errno_real;
	int errno_ft;
	int len_str;

	len_str = strlen(str);
	errno = 0 ;
	errno_real = 0;
	errno_ft = 0;
	ft_putstr("This test use fd = ");
	ft_putnbr(fd);
	ft_putstr(" and the following str : |");
	ft_putstr(str);
	ft_putstr("|\n");
	if (fd == 1)
		ft_putstr("Let's call write() from libc\n");
	ret_real = write(fd, str, len_str);
	if (ret_real == -1)
	{
		errno_real = errno;
		ft_putstr("Error\nwrite() from libc set errno to ");
		ft_putnbr(errno_real);
		ft_putstr(".\nStrerror is ");
		ft_putstr(strerror(errno_real));
		ft_putstr(".\n");
	}
	errno = 0;
	if (fd == 1)
		ft_putstr("\nLet's call ft_write()\n");
	ret_ft = ft_write(fd, str, len_str);
	ft_putstr("\nThe return of write() from libc is ");
	ft_putnbr(ret_real);
	ft_putstr(".\n");
	ft_putstr("The return of ft_write() is ");
	ft_putnbr(ret_ft);
	ft_putstr(".\n");
	ft_putstr("The cmp of functions return is :");
	valid_test(ret_ft == ret_real);
	if (ret_ft < 0)
	{
		errno_ft = errno;
		ft_putstr("Error\nft_write() set errno to ");
		ft_putnbr(errno_ft);
		ft_putstr(".\nStrerror is ");
		ft_putstr(strerror(errno_ft));
		ft_putstr(".\n");
	}
	if (ret_real == -1)
	{
		printf("The cmp of errno values is :");
		valid_test(errno_ft == errno_real);
	}
}

int	test_ft_write(void)
{
	char *test_strs[] = {"meh", "", " Vincent : You know what they call a Quarter Pounder with Cheese in Paris ?\n Jules : They don't call it a Quarter Pounder with Cheese?\n Vincent : No, man, they got the metric system, they don't know what the fuck a Quarter Pounder is.\n Jules : Then what do they call it ?\n Vincent : They call it a Royal with Cheese.\n Jules : A Royal with cheese. What do they call a Big Mac?\n Vincent : Well, a Big Mac's a Big Mac, but they call it le Big-Mac.\n Jules : Le Big-Mac. Ha ha ha ha. What do they call a Whopper?\n Vincent : I dunno, I didn't go into Burger King.", NULL};
	int i = -1;
	int j = -1;
	int fd_test;
	int read_test;
	char buf_test[BUFFER_SIZE];

	print_title("Tests for function ft_write :");
	print_title("\nFirst tests will write on STDOUT :");
	while (test_strs[++i])
		ft_write_unit(1, test_strs[i]);
	print_title("\nThe next tests will write on write_test_file :");
	fd_test = open("./test_files/write_test_file", O_RDWR);
	if (fd_test == -1)
	{
		printf("Error while opening the test_file\n");
		return (0);
	}
	while (test_strs[++j])
		ft_write_unit(fd_test, test_strs[j]);
	print_title("\nNow let's read the file written :");
	lseek(fd_test, 0, SEEK_SET);
	while ((read_test = read(fd_test, buf_test, BUFFER_SIZE)) != 0)
	{
		if (read_test == -1)
		{
			printf("Error while reading write_test_file\n");
			close(fd_test);
			return (0);
		}
		write(1, buf_test, read_test);
	}
	close(fd_test);
	print_title("\nIt should contain the short string twice then the long string twice.");
	print_title("\nThis test will try to write on a bad file descriptor :");
	ft_write_unit(-1, test_strs[0]);
	return (1);
}
