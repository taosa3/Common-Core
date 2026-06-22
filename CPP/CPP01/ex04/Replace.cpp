#include "Replace.hpp"

Replace::Replace(std::string filename, std::string s1, std::string s2) {
    this->filename = filename;
    this->s1 = s1;
    this->s2 = s2;
}

Replace::~Replace() {
    return ;
}

int Replace::ft_replace() {
    if (s1.empty())
    { 
        std::cout << "Error: string to find is empty" << std::endl;
        return 1;
    }
    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cerr << "Error opening the file" << std::endl;
        return (1);
    }
    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile)
    {
        std::cerr << "Error creating output file" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(infile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outfile << line << std::endl;
    }
    infile.close();
    outfile.close();
    return 0;
}