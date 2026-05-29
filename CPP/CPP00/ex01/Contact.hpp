#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact {
	private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenumber;
	std::string darkestsecret;

	public:
	Contact( void );
	~Contact( void );
	void input_contact();
	void display_short(int index) const;
	void display_all() const;
};

#endif