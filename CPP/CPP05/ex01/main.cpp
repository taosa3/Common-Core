#include "Bureaucrat.hpp"

int main() {
            //Invalid grade, grade too high
    try {
        Bureaucrat ze("Ze", 0);
        std::cout << ze << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
            //Valid grade
    try {
        Bureaucrat lilbrobro("lilbrobro", 129);
        std::cout << lilbrobro << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
            //Invalid grade, grade too low
    try {
        Bureaucrat zeToze("Ze toze", 167);
        std::cout << zeToze << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
            //Incrementing and decrementing grades
    try {
        Bureaucrat lilbrobro("lilbrobro", 129);
        std::cout << lilbrobro << std::endl;
        lilbrobro.gradeIncrement();
        std::cout << lilbrobro << std::endl;
        lilbrobro.gradeDecrement();
        std::cout << lilbrobro << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}