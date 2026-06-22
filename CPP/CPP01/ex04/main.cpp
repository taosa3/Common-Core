#include "Replace.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage: " << av[0] << " <filename> <string to find> <string to replace>" << std::endl;
        return (1);
    }
    Replace replace(av[1], av[2], av[3]);
    if (replace.ft_replace() == 1)
        return 1;

    return 0;
}