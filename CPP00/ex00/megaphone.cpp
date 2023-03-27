
# include <iostream>

void	print_to_upper(std::string str)
{
	for (unsigned long i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
	std::cout << str;
}

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < ac ; i++)
		{
			print_to_upper(av[i]);
			// if (i < ac -1)
			// 	std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (0);
}

