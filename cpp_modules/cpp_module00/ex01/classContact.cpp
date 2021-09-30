#include "classContact.hpp"

void	contact::set_id(int id)
{
	this->id = id;
}

void	contact::set_first_name(std::string s)
{
	this->first_name = s;
}

void	contact::set_second_name(std::string s)
{
	this->second_name = s;
}

void	contact::set_nickname(std::string s)
{
	this->nickname = s;
}

void	contact::set_phone_number(std::string s)
{
	this->phone_number = s;
}

void	contact::set_secret(std::string s)
{
	this->secret = s;
}

std::string contact::get_first_name(void)
{
	return (this->first_name);
}

std::string contact::get_second_name(void)
{
	return (this->second_name);
}

std::string contact::get_nickname(void)
{
	return (this->nickname);
}

std::string contact::get_phone_number(void)
{
	return (this->phone_number);
}

std::string contact::get_secret(void)
{
	return (this->secret);
}
std::string contact::get_id(void)
{
	return (std::to_string(this->id));
}