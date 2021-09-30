#include "classContact.hpp"

void command_add(int id, contact *contacts)
{
	std::string s;

	contacts[id].set_id(id + 1);
	std::cout << "First name: ";
	std::getline(std::cin, s);
	contacts[id].set_first_name(s);
	std::cout << "Second name: ";
	std::getline(std::cin, s);
	contacts[id].set_second_name(s);
	std::cout << "Nickname: ";
	std::getline(std::cin, s);
	contacts[id].set_nickname(s);
	std::cout << "Phone number: ";
	std::getline(std::cin, s);
	contacts[id].set_phone_number(s);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, s);
	contacts[id].set_secret(s);
}

std::string condition_str(std::string s)
{
	if (s.length() > 10)
	{
		s.resize(9, ' ');
		s += ".";
	}
	if (s.length() < 10)
		s.resize(10, ' ');
	return (s);
}

void command_search(contact *contacts, int len_contact)
{
	int id;
	std::string s_id;

	if (len_contact == 0)
	{
		std::cout << "Error: no contacts found" << std::endl;
		return ;
	}
	for (int i = 0; i < len_contact; i++)
	{
		std::cout << "|    id    |First name|Second name| Nickname |" << std::endl;
		std::cout << "|     " << contacts[i].get_id() << "    |";
		std::cout <<  condition_str(contacts[i].get_first_name()) << "|";
		std::cout <<  condition_str(contacts[i].get_second_name()) << " |";
		std::cout <<  condition_str(contacts[i].get_nickname()) << "|" << std::endl;
	}
	std::cout << "ID: ";
	std::getline(std::cin, s_id);
	id = atoi(s_id.c_str());
	if (id < 0 || id > len_contact)
	{
		std::cout << "Error: id not found" << std::endl;
		return ;
	}
	std::cout << "First name: " << contacts[id - 1].get_first_name() << std::endl;
	std::cout << "Second name: " << contacts[id - 1].get_second_name() << std::endl;
	std::cout << "Nickname: " << contacts[id - 1].get_nickname() << std::endl;
	std::cout << "Phone number: " << contacts[id - 1].get_phone_number() << std::endl;
	std::cout << "Darkest secret: " << contacts[id - 1].get_secret() << std::endl;
}

void parser(std::string command, int *id, contact *contacts)
{
	static int len_contact;

	if (command == "ADD" || command == "add")
	{
		if (*id == 8)
			*id = 0;
		command_add(*id, contacts);
		if (len_contact != 8)
			len_contact++;
		*id += 1;
	}
	if (command == "EXIT" || command == "exit")
		exit(0);
	if (command == "SEARCH" || command == "search")
		command_search(contacts, len_contact);
}

int main()
{
	contact contacts[8];
	std::string command;
	int id = 0;

	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, command);
		parser(command, &id, contacts);
	}
	return (0);
}