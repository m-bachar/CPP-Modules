#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for (int j = 1; av[j]; j++)
		{
			std::string	argv(av[j]);
			for (int i = 0; argv[i]; i++)
			{
				if (argv[i] >= 'a' && argv[i] <= 'z')
					argv[i] = std::toupper(argv[i]);
				std::cout << argv[i];
			}
		}
		std::cout << '\n';
	}
	return (0);
}
