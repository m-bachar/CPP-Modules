/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benito <benito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:00:10 by mbachar           #+#    #+#             */
/*   Updated: 2023/09/17 21:05:46 by benito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for (int j = 1; av[j]; j++)
		{
			for (int i = 0; av[j][i]; i++)
			{
				if (av[j][i] >= 'a' && av[j][i] <= 'z')
					av[j][i] = std::tolower(av[j][i]);
				std::cout << av[j][i];
			}
		}
		std::cout << '\n';
	}
	return (0);
}
