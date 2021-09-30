#include "Karen.hpp"

int main(int argc, const char *argv[])
{
	Karen karen;

	for (int i = 1; i < argc; i++)
		karen.complain(std::string(argv[i]));
	return (0);
}