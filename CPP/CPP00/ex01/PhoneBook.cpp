#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook(void)
{
	std::cout << "Welcome to the PhoneBook!" << std::endl;
	index = 0;
	count = 0;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destroying PhoneBook..." << std::endl;
}

void PhoneBook::add_contact(void)
{
	std::cout << "\n--- ADD NEW CONTACT ---" << std::endl;
	contacts[index].input_contact();

	// Move to next position for circular buffer
	index = (index + 1) % 8;

	// Increment count until we reach 8
	if (count < 8)
		count++;

	std::cout << "Contact saved!" << std::endl;
}

void PhoneBook::display_contacts(void) const
{
	if (count == 0)
	{
		std::cout << "No contacts saved yet." << std::endl;
		return;
	}

	std::cout << "\n--- CONTACTS LIST ---" << std::endl;
	std::cout << std::setw(10) << std::right << "Index" << "|"
		  << std::setw(10) << std::right << "First" << "|"
		  << std::setw(10) << std::right << "Last" << "|"
		  << std::setw(10) << std::right << "Nickname" << std::endl;

	for (int i = 0; i < count; i++)
		contacts[i].display_short(i);
}

void PhoneBook::search_contact(void) const
{
	if (count == 0)
	{
		std::cout << "No contacts saved yet." << std::endl;
		return;
	}

	display_contacts();

	std::cout << "\nEnter the index of the contact to display: ";
	std::string input;
	std::getline(std::cin, input);

	// Convert string to int
	int contact_index;
	std::istringstream iss(input);
	if (!(iss >> contact_index) || contact_index < 0 || contact_index >= count)
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}

	std::cout << "\n--- CONTACT DETAILS ---" << std::endl;
	contacts[contact_index].display_all();
}