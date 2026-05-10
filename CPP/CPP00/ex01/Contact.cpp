#include "Contact.hpp"

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
	for (int i = 0; i < str.length(); i++)
		if (!std::isalpha(str[i]))
			return 1;
	return 0;
}

int		check_numbers(const std::string& str) {
	for (int i = 0; i < str.length(); i++)
		if (!std::isdigit(str[i]))
			return 1;
	return 0;
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
		std::cout << "Invalid input. (has to contain only letters and it can't be empty)" << std::endl;
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
