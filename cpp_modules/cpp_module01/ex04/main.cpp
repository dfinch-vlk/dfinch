#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

std::string change_str(std::string line, std::string s1, std::string s2)
{
	std::string::size_type itr = line.find(s1);
	while (itr != std::string::npos)
	{
		line.erase(itr, s1.length());
		line.insert(itr, s2);
		itr = line.find(s1);
	}
	return (line);
}

int main(int argc, char const *argv[])
{
	if (argc != 4)
	{
		std::cout << "Error: argument" << std::endl;
		return (1);
	}
	std::string s1 = std::string(argv[2]);
	std::string s2 = std::string(argv[3]);
	std::string new_file, line;
	std::ifstream f1((std::string(argv[1])));
	std::ofstream f2(std::string(argv[1]) += ".replace");
	while (getline(f1, line))
		new_file += change_str(line, s1, s2);
	f2 << new_file << std::endl;
	f1.close();
	f2.close();
	return (0);
}