#include <iostream>
#include <stdint.h>
#include "Data.hpp"
#include "Serializer.hpp"

static void check(const char *label, bool ok)
{
	std::cout << (ok ? "[PASS] " : "[FAIL] ") << label << std::endl;
}

static void title(std::string const &text)
{
	std::cout << std::endl << "===== " << text << " =====" << std::endl;
}

int main()
{
	title("1. Round trip: pointer -> number -> same pointer");
	Data a;
	a.value = 42;
	uintptr_t raw = Serializer::serialize(&a);
	Data *back = Serializer::deserialize(raw);
	std::cout << "original: " << &a << "\nraw hex : 0x" << std::hex << raw
		<< std::dec << "\nreturned: " << back << std::endl;
	check("same address", back == &a);
	check("raw is not zero", raw != 0);
	check("int readable through returned pointer", back->value == 42);

	title("2. Write via returned pointer changes the original");
	back->value = 99;
	check("write via returned pointer changes the original", a.value == 99);
}