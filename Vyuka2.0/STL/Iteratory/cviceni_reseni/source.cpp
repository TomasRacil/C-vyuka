#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::vector<std::string> retezec = {"ahoj", "světe", "jak", "se", "máš", "dnes?"};
    std::cout << "Všechny řetězce ve vektoru:" << std::endl;
    for (auto it = retezec.begin(); it != retezec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "První řetězec s délkou větší než 5 znaků: ";
    for (auto it = retezec.begin(); it != retezec.end(); ++it)
    {
        if (it->size() > 5)
        {
            std::cout << *it << std::endl;
            break; // Ukončí cyklus po nalezení prvního řetězce
        }
    }
    retezec.erase(std::remove_if(retezec.begin(), retezec.end(),
                                 [](const std::string &s)
                                 { return s.find('a') != std::string::npos; }),
                  retezec.end());

    std::cout << "Vektor po odstranění řetězců s písmenem 'a':" << std::endl;
    for (auto it = retezec.begin(); it != retezec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}