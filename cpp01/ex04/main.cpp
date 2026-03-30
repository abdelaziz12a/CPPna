
#include <iostream>
#include <fstream>

void MyReplace(std::string *line, std::string Old, std::string New)
{
    size_t pos = 0;
    while(1)
    {
        pos = line->find(Old, pos);
        if (pos == std::string::npos)
            break;
        line->erase(pos, Old.size());
        line->insert(pos, New);
        pos += New.size();
    }
}

int main(int ac, char **av)
{
    if (ac != 4 || !av[2][0])
    {
        std::cout << "error: invalide input" << std::endl;
        return 1;
    }

    std::string Old = av[2];
    std::string New = av[3];
    std::ifstream file(av[1]);

    if (!file.is_open())
    {
        std::cout << "error: invalide input" << std::endl;
        return 1;
    }

     std::string content ;
    if(!std::getline(file, content, '\0'))
    {
        std::cout << "error : cant read from " << av[1] << std::endl;
        file.close();
        return 1;
    }
    file.close();

    std::ofstream outFile((std::string(av[1]) + ".replace").c_str());
    if (!outFile.is_open())
    {
        std::cout << "error: open file\n";
        file.close();
        return 1;
    }

    MyReplace(&content, Old, New);
    outFile << content;

    outFile.close();
    return (0);
}