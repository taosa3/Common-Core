#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {

}

Intern::Intern(const Intern &other) {
    (void)other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

Intern::~Intern() {

}

AForm *Intern::makeShrubberyForm(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyForm(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialForm(const std::string &target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*forms[3])(const std::string &) = {
        &Intern::makeShrubberyForm,
        &Intern::makeRobotomyForm,
        &Intern::makePresidentialForm
    };
    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i](target);
        }
    }
    std::cout << "Intern couldn't create the form: '" << formName << "' does not exist." << std::endl;
    return NULL;
}