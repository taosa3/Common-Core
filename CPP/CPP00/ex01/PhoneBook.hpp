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
	void add_contact(void);
	void search_contact(void) const;
	void display_contacts(void) const;

};

#endif