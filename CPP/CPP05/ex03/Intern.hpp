#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Intern {
    private:
        static AForm *makeShrubberyForm(const std::string &target);
        static AForm *makeRobotomyForm(const std::string &target);
        static AForm *makePresidentialForm(const std::string &target);

    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm *makeForm(const std::string &formName, const std::string &target) const;
};

#endif