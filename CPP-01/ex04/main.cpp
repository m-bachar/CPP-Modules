#include "Replace.hpp"

void	error(std::string errorMsg)
{
	std::cout << RED << "Error : " << RESET << errorMsg << std::endl;
	exit (1);
}

std::string	readFile(std::string fileName)
{
	std::string		fileContent;
	std::ifstream	myFile(fileName.c_str());

	if (!myFile)
		error("unable to locate or open file.");
	while (myFile)
		std::getline(myFile, fileContent, '\0');
	return (fileContent);
}

std::string	search_and_replace(std::string fileContent, std::string s1, std::string s2)
{
	int	flag = 0;
	for (size_t i = 0; i < fileContent.length(); i++)
	{
		if (fileContent.substr(i, s1.length()) == s1)
		{
			flag++;
			fileContent.erase(i, s1.length());
			fileContent.insert(i, s2);
			i += s2.length();
		}
	}
	if (flag == 0)
	{
		std::cout << RED << "Error : " << RESET << s1 << " not found in file." << std::endl;
		exit (1);
	}
	return (fileContent);
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << RED << "Error : " << RESET << "invalid arguments number." << std::endl;
		return (1);
	}
	std::string		filename = av[1];
	std::string		newContent = search_and_replace(readFile(filename), av[2], av[3]);
	std::string		newfilename = filename + ".replace";
	std::ofstream	newFile(newfilename.c_str());

	newFile << newContent;
	std::cout << GREEN << "Success : " << RESET << "file " << filename + ".replace created successfuly." << std::endl;
	newFile.close();
	return (0);
}
