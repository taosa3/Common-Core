#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "\n[Form constructor boundaries]" << std::endl;
    try {
        Form valid("Valid", 1, 150);
        std::cout << valid << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    try {
        Form invalidHigh("Invalid high", 0, 50);
        (void)invalidHigh;
        std::cout << "ERROR: invalid signing grade was accepted" << std::endl;
    }
    catch (const Form::GradeTooHighException &e) {
        std::cout << "Expected form GradeTooHighException: " << e.what() << std::endl;
    }

    try {
        Form invalidLow("Invalid low", 50, 151);
        (void)invalidLow;
        std::cout << "ERROR: invalid execution grade was accepted" << std::endl;
    }
    catch (const Form::GradeTooLowException &e) {
        std::cout << "Expected form GradeTooLowException: " << e.what() << std::endl;
    }

    std::cout << "\n[Form signing]" << std::endl;
    Bureaucrat exact("Exact", 50);
    Bureaucrat better("Better", 49);
    Bureaucrat worse("Worse", 51);
    Form form("Needs grade 50", 50, 100);

    exact.signForm(form);
    std::cout << "Exact grade signs: " << (form.getIsSigned() ? "yes" : "no") << std::endl;

    Form secondForm("Second form", 50, 100);
    better.signForm(secondForm);
    std::cout << "Better grade signs: " << (secondForm.getIsSigned() ? "yes" : "no") << std::endl;

    Form rejected("Rejected", 50, 100);
    worse.signForm(rejected);
    std::cout << "Worse grade remains unsigned: " << (!rejected.getIsSigned() ? "yes" : "no") << std::endl;

    exact.signForm(form);
    std::cout << "Signing an already signed form remains signed: " << (form.getIsSigned() ? "yes" : "no") << std::endl;


    std::cout << "\n[Copy and assignment]" << std::endl;
    Bureaucrat original("Original", 42);
    Bureaucrat copied(original);
    std::cout << "Copied bureaucrat: " << copied << std::endl;

    Bureaucrat assigned("Assigned", 100);
    assigned = original;
    std::cout << "Assigned bureaucrat keeps its name and gets grade 42: " << assigned << std::endl;

    Form source("Source", 50, 75);
    Bureaucrat signer("Signer", 1);
    signer.signForm(source);
    Form formCopy(source);
    std::cout << "Copied form: " << formCopy << std::endl;

    Form target("Target", 100, 100);
    target = source;
    std::cout << "Assigned form keeps its own name and grades, copies signed state: " << target << std::endl;
    
}