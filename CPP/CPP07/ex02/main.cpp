#include <iostream>
#include <string>
#include "Array.hpp"

static void title(const std::string &s)
{
	std::cout << "\n=== " << s << " ===" << std::endl;
}

template <typename T>
static void printArray(const std::string &name, const Array<T> &arr)
{
	std::cout << name << " (size " << arr.size() << "): [";
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i];
		if (i + 1 < arr.size())
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

int main(void)
{
	title("1. Empty array");
	{
		Array<int> empty;
		std::cout << "size = " << empty.size() << " (expected 0)" << std::endl;
		try
		{
			std::cout << empty[0] << std::endl;
			std::cout << "FAIL: no exception thrown" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "OK, exception caught: " << e.what() << std::endl;
		}
	}

	title("2. Sized array is default-initialized (expected all 0)");
	{
		Array<int> a(5);
		printArray("a", a);
		Array<std::string> s(3);
		std::cout << "string array size = " << s.size() << " (elements are empty strings)" << std::endl;
	}

	title("3. Write and read with []");
	{
		Array<int> a(5);
		for (unsigned int i = 0; i < a.size(); i++) 
			a[i] = i * 10;
		printArray("a", a);
		std::cout << "expected: [0, 10, 20, 30, 40]" << std::endl;
	}

	title("4. Out of bounds");
	{
		Array<int> a(5);
		try
		{
			a[5] = 1;
			std::cout << "FAIL: a[5] did not throw" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "OK, a[5]: " << e.what() << std::endl;
		}
		try
		{
			a[-1] = 1;
			std::cout << "FAIL: a[-1] did not throw" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "OK, a[-1]: " << e.what() << std::endl;
		}
		try
		{
			a[4] = 1;
			std::cout << "OK, a[4] is valid (last element)" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "FAIL: a[4] threw: " << e.what() << std::endl;
		}
	}

	title("5. Copy constructor is a DEEP copy");
	{
		Array<int> original(3);
		for (unsigned int i = 0; i < 3; i++)
			original[i] = i + 1;
		Array<int> copy(original);
		copy[0] = 999;
		printArray("original", original);
		printArray("copy    ", copy);
		original[2] = 777;
		printArray("original", original);
		printArray("copy    ", copy);
	}

	title("6. Assignment operator is a DEEP copy");
	{
		Array<int> a(3);
		Array<int> b(3);
		for (unsigned int i = 0; i < 3; i++)
		{
			a[i] = i + 1;
			b[i] = 100;
		}
		b = a;
		b[1] = 555;
		printArray("a", a);
		printArray("b", b);
	}

	title("7. Assignment between different sizes");
	{
		Array<int> small(2);
		Array<int> big(6);
		for (unsigned int i = 0; i < 2; i++)
			small[i] = 1;
		for (unsigned int i = 0; i < 6; i++)
			big[i] = 2;
		small = big;
		printArray("small (was 2, now big's copy)", small);
		big = Array<int>(1);
		printArray("big (assigned a 1-element array)", big);
		Array<int> empty;
		big = empty;
		std::cout << "big assigned an empty array, size = " << big.size() << " (expected 0)" << std::endl;
	}

	title("8. Chained assignment and self-assignment");
	{
		Array<int> a(3);
		Array<int> b(3);
		Array<int> c(3);
		for (unsigned int i = 0; i < 3; i++)
			a[i] = i + 7;
		c = b = a;
		printArray("c", c);
		a = a;
		printArray("a after a = a", a);
    }

	title("9. Const array (tests the const operator[])");
	{
		Array<int> a(3);
		for (unsigned int i = 0; i < 3; i++)
			a[i] = i;
		const Array<int> c(a);
		std::cout << "c[1] = " << c[1] << " (expected 1), size = " << c.size() << std::endl;
		try
		{
			std::cout << c[3] << std::endl;
			std::cout << "FAIL: c[3] did not throw" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "OK, const c[3]: " << e.what() << std::endl;
		}
		//it must NOT compile (c is const):
		// c[0] = 5;
	}

	title("10. Other types");
	{
		Array<std::string> s(3);
		s[0] = "hello";
		s[1] = "template";
		s[2] = "world";
		Array<std::string> t(s);
		t[1] = "copy";
		printArray("s", s);
		printArray("t", t);
		Array<double> d(2);
		d[0] = 3.14;
		d[1] = 2.71;
		printArray("d", d);
	}

	title("11. Big array (check with valgrind)");
	{
		Array<int> big(100000);
		big[99999] = 42;
		std::cout << "big[99999] = " << big[99999] << " (expected 42), big[0] = " << big[0] << " (expected 0)" << std::endl;
	}

	std::cout << "\nDone." << std::endl;
	return 0;
}