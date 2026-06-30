#include "Contact.hpp"
#include <cctype>
#include <cstdlib>

Contact::Contact(void)
{
	std::cout << "Contact Constructor called" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "Contact Destructor called" << std::endl;
	return ;
}

int		check_letters(const std::string& str) {
	for (size_t i = 0; i < str.length(); i++)
		if (!std::isalpha(str[i]))
			return 0;
	return 1;
}

int		check_numbers(const std::string& str) {
	for (size_t i = 0; i < str.length(); i++)
		if (!std::isdigit(str[i]))
			return 0;
	return 1;
}

void	Contact::input_contact() {
	while (1)
	{
		std::cout << "Enter your first name: ";
		if (!std::getline(std::cin, firstname))
		{
			std::cout << "EOF detected. Leaving.." << std::endl;
			exit (1);
		}
		if (!firstname.empty() && check_letters(firstname))
			break;
		std::cout << "Invalid input. (has to contain only letters and cannot be empty)" << std::endl;
	}
	while (1)
	{
		std::cout << "Enter your last name: ";
		if (!std::getline(std::cin, lastname))
		{
			std::cout << "EOF detected. Leaving.." << std::endl;
			exit (1);
		}
		if (!lastname.empty() && check_letters(lastname))
			break;
		std::cout << "Invalid input. (has to contain only letters and it can't be empty)" << std::endl;
	}
	while (1)
	{
		std::cout << "Enter your nickname: ";
		if (!std::getline(std::cin, nickname))
		{
			std::cout << "EOF detected. Leaving.." << std::endl;
			exit (1);
		}
		if (!nickname.empty() && check_letters(nickname))
			break;
		std::cout << "Invalid input. (has to contain only letters and it can't be empty)" << std::endl;
	}
	while (1)
	{
		std::cout << "Enter your phone number: ";
		if (!std::getline(std::cin, phonenumber))
		{
			std::cout << "EOF detected. Leaving.." << std::endl;
			exit (1);
		}
		if (!phonenumber.empty() && check_numbers(phonenumber))
			break;
		std::cout << "Invalid input. (has to contain only letters and it can't be empty)" << std::endl;
	}
	while (1)
	{
		std::cout << "Enter your darkest secret: ";
		if (!std::getline(std::cin, darkestsecret))
		{
			std::cout << "EOF detected. Leaving.." << std::endl;
			exit (1);
		}
		if (!darkestsecret.empty())
			break;
	}
}

void Contact::display_short(int index) const {
	std::string fname = firstname;
	std::string lname = lastname;
	std::string nick = nickname;

	if (fname.length() > 9)
		fname = fname.substr(0, 9) + ".";
	if (lname.length() > 9) 
		lname = lname.substr(0, 9) + ".";
	if (nick.length() > 9)
		nick = nick.substr(0, 9) + ".";

	std::cout << std::setw(10) << std::right << index << "|"
			  << std::setw(10) << std::right << fname << "|"
			  << std::setw(10) << std::right << lname << "|"
			  << std::setw(10) << std::right << nick << std::endl;
}

void	Contact::display_all() const
{
	std::cout << "First Name: " << firstname << std::endl;
	std::cout << "Last Name: " << lastname << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phonenumber << std::endl;
	std::cout << "Darkest Secret: " << darkestsecret << std::endl;
}