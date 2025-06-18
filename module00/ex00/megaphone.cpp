#include <string>
#include <iostream>


//#include <iostream>
#include <cctype> // para isalpha, islower, toupper

/*int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 1;
	}

	for (int i = 1; i < argc; ++i)
	{
		for (int j = 0; argv[i][j]; ++j)
		{
			char c = argv[i][j];
			std::cout << static_cast<char>(std::toupper(c));
		}
	}
	std::cout << std::endl;
	return 0;
}*/

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return(1);
	}

	char c;
	for (int i = 1; i < argc; ++i)
	{
		for (int j = 0; argv[i][j]; ++j)
		{
			c = argv[i][j];
			if (std::isalpha(c) && std::islower(c))
			{
				c = std::toupper(c);
			}
			std::cout << c;	 		
		}
		if (argv[i + 1])
		{
			std::cout << " ";
		}
	}
	std::cout << "\n";
	return (0);
}
