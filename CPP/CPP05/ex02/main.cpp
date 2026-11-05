#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void title(std::string const &text)
{
	std::cout << std::endl << "===== " << text << " =====" << std::endl;
}

static void signAndExecute(Bureaucrat &b, AForm &f)
{
	try
	{
		b.signAForm(f);
		b.executeForm(f);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught in main: " << e.what() << std::endl;
	}
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	title("1. Invalid bureaucrat grades");
	try
	{
		Bureaucrat tooHigh("TooHigh", 0);
		std::cout << tooHigh << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat tooLow("TooLow", 151);
		std::cout << tooLow << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	title("2. Top bureaucrat: every form signs and executes");
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Arthur");

		std::cout << boss << std::endl;
		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << pardon << std::endl;

		signAndExecute(boss, shrub);
		signAndExecute(boss, robot);
		signAndExecute(boss, pardon);
		std::cout << "-> check that the file home_shrubbery exists and has trees" << std::endl;
	}

	title("3. Robotomy 50%: execute 10 times, expect both outcomes");
	{
		Bureaucrat boss("Boss", 1);
		RobotomyRequestForm robot("Marvin");

		boss.signAForm(robot);
		for (int i = 0; i < 10; i++)
			boss.executeForm(robot);
	}

	title("4. Executing a form that is NOT signed");
	{
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm pardon("Ford");

		try
		{
			boss.executeForm(pardon);
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught in main: " << e.what() << std::endl;
		}
	}

	title("5. Grade too low to SIGN (150 vs 25)");
	{
		Bureaucrat intern("Newbie", 150);
		PresidentialPardonForm pardon("Trillian");

		signAndExecute(intern, pardon);
		std::cout << pardon << std::endl;
	}

	title("6. Can sign but grade too low to EXECUTE (25 signs, 5 needed)");
	{
		Bureaucrat middle("Middle", 25);
		PresidentialPardonForm pardon("Zaphod");

		signAndExecute(middle, pardon);
	}

	title("7. Boundary values for Shrubbery (sign 145, exec 137)");
	{
		ShrubberyCreationForm shrub("boundary");
		Bureaucrat low("Low", 145);
		Bureaucrat better("Better", 137);

		signAndExecute(low, shrub);
		std::cout << "-- now a better bureaucrat executes it --" << std::endl;
		better.executeForm(shrub);
	}

	title("8. Increment / decrement then try again");
	{
		Bureaucrat b("Climber", 6);
		PresidentialPardonForm pardon("Slartibartfast");

		b.signAForm(pardon);
		b.executeForm(pardon);
		b.gradeIncrement();
		std::cout << b << std::endl;
		b.executeForm(pardon);
	}

	title("9. Polymorphism: AForm pointers + virtual destructor");
	{
		Bureaucrat boss("Boss", 1);
		AForm *forms[3];

		forms[0] = new ShrubberyCreationForm("poly");
		forms[1] = new RobotomyRequestForm("Poly");
		forms[2] = new PresidentialPardonForm("Poly");

		for (int i = 0; i < 3; i++)
		{
			std::cout << *forms[i] << std::endl;
			signAndExecute(boss, *forms[i]);
		}
		for (int i = 0; i < 3; i++)
			delete forms[i];
	}

	title("10. Copy constructor and assignment operator");
	{
		PresidentialPardonForm original("Original");
		Bureaucrat boss("Boss", 1);

		boss.signAForm(original);

		PresidentialPardonForm copy(original);
		PresidentialPardonForm assigned("Other");
		assigned = original;

		std::cout << "original: " << original << std::endl;
		std::cout << "copy:     " << copy << std::endl;
		std::cout << "assigned: " << assigned << std::endl;
		boss.executeForm(copy);
		boss.executeForm(assigned);
	}

	return 0;
}