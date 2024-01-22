#pragma once

#include <iostream>

# define	RESET	"\x1b[0m"
# define	GREEN	"\x1b[1;32m"
# define	RED		"\x1b[1;31m"
# define	ORANGE	"\x1b[1;38;5;208m"
# define	PURPLE	"\x1b[1;38;5;93m"

template <typename T, typename F>
void	iter(T &array, int len, F fun)
{
	int i = 0;
	while (i < len)
	{
		fun(array[i]);
		i++;
	}
}
