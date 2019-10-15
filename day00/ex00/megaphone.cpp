#include <iostream>
#include <cctype>
#include <string.h>

void    up_string(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {

        for (int j = 0; j < strlen(av[i]); j++) {

            std::cout << (char)toupper(av[i][j]);
        } 
    }
}

int     main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    up_string(ac, av);

    return 0;
}