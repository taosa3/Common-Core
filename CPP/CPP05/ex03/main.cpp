#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

static void title(std::string const &text)
{
	std::cout << std::endl << "===== " << text << " =====" << std::endl;
}

static void tryForm(Intern &intern, Bureaucrat &boss,
					std::string const &name, std::string const &target)
{
	AForm *form = intern.makeForm(name, target);

	if (form == NULL)
	{
		std::cout << "-> got NULL for \"" << name << "\" (nothing to sign/execute)" << std::endl;
		return;
	}
	std::cout << *form << std::endl;
	boss.signAForm(*form);
	boss.executeForm(*form);
	delete form;
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Bureaucrat boss("Boss", 1);

	title("1. Example from the subject");
	{
		Intern someRandomIntern;
		AForm *rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			std::cout << *rrf << std::endl;
			delete rrf;
		}
	}

	title("2. All three valid forms, signed and executed");
	{
		Intern intern;

		tryForm(intern, boss, "shrubbery creation", "garden");
		tryForm(intern, boss, "robotomy request", "Marvin");
		tryForm(intern, boss, "presidential pardon", "Arthur");
		std::cout << "-> check that garden_shrubbery exists" << std::endl;
	}

	title("3. Unknown form names (expect an error message + NULL)");
	{
		Intern intern;

		tryForm(intern, boss, "coffee order", "Boss");
		tryForm(intern, boss, "tax refund", "Tomas");
	}

	title("4. Name must match exactly (case, spaces, empty)");
	{
		Intern intern;

		tryForm(intern, boss, "Robotomy Request", "Bender");
		tryForm(intern, boss, "robotomy  request", "Bender");
		tryForm(intern, boss, "robotomy request ", "Bender");
		tryForm(intern, boss, "robotomy", "Bender");
		tryForm(intern, boss, "", "Bender");
	}

	title("5. Empty target is still a valid target");
	{
		Intern intern;

		tryForm(intern, boss, "presidential pardon", "");
	}

	title("6. Low-grade bureaucrat with an intern-made form");
	{
		Intern intern;
		Bureaucrat newbie("Newbie", 150);
		AForm *form = intern.makeForm("presidential pardon", "Ford");

		if (form)
		{
			newbie.signAForm(*form);
			newbie.executeForm(*form);
			delete form;
		}
	}

	title("7. Several forms alive at once (same intern, deleted after)");
	{
		Intern intern;
		AForm *forms[3];

		forms[0] = intern.makeForm("shrubbery creation", "multi");
		forms[1] = intern.makeForm("robotomy request", "Multi");
		forms[2] = intern.makeForm("presidential pardon", "Multi");

		for (int i = 0; i < 3; i++)
		{
			if (forms[i])
				boss.signAForm(*forms[i]);
		}
		for (int i = 0; i < 3; i++)
		{
			if (forms[i])
				boss.executeForm(*forms[i]);
		}
		for (int i = 0; i < 3; i++)
			delete forms[i];
	}

	title("8. Copy constructor and assignment of Intern");
	{
		Intern original;
		Intern copy(original);
		Intern assigned;

		assigned = original;
		tryForm(copy, boss, "presidential pardon", "CopiedIntern");
		tryForm(assigned, boss, "robotomy request", "AssignedIntern");
	}

	return 0;
}