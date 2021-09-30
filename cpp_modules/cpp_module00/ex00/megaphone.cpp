#include <iostream>

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int q = 1; q < argc; q++)
	{
		for (int i = 0; argv[q][i]; i++)
			std::cout << (char)toupper(argv[q][i]);
	}
	std::cout << std::endl;
	return (0);
}