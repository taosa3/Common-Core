#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main(void)
{
	PhoneBook phonebook;
	std::string command;

	std::cout << "=== MY AWESOME PHONEBOOK ===" << std::endl;
	std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;

	while (1)
	{
		std::cout << "\nEnter command: ";
		if (!std::getline(std::cin, command))
		{
			std::cout << "EOF detected. Exiting..." << std::endl;
			break;
		}
		if (command == "ADD" || command == "add")
		{
			phonebook.add_contact();
		}
		else if (command == "SEARCH" || command == "search")
		{
			phonebook.search_contact();
		}
		else if (command == "EXIT" || command == "exit")
		{
			std::cout << "Goodbye!" << std::endl;
			break;
		}
		else if (!command.empty())
		{
			std::cout << "Unknown command. Try ADD, SEARCH, or EXIT." << std::endl;
		}
	}

	return 0;
}
