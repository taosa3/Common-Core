#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook {
	private:
	Contact contacts[8];
	int index;
	int count;

	public:
	PhoneBook( void );
	~PhoneBook( void );
	
};

#endif