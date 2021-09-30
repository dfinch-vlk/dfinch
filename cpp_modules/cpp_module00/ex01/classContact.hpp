#ifndef CLASSCONTACT_HPP
# define CLASSCONTACT_HPP

# include <iostream>
# include <string>

class contact
{
private:
	int id;
	std::string first_name;
	std::string second_name;
	std::string nickname;
	std::string phone_number;
	std::string secret;
public:
	void set_id(int id);
	void set_first_name(std::string s);
	void set_second_name(std::string s);
	void set_nickname(std::string s);
	void set_phone_number(std::string s);
	void set_secret(std::string s);
	std::string get_first_name(void);
	std::string get_second_name(void);
	std::string get_nickname(void);
	std::string get_phone_number(void);
	std::string get_secret(void);
	std::string get_id(void);
	std::string get_info(std::string s);
};
#endif
