#include <windows.h>
#include <iostream>
#include <conio.h>
#include "WinCon.h"

INT WINAPI WinMain(
    HINSTANCE /*hInstance*/,
    HINSTANCE /*hPrevInstance*/,
    PSTR      /*lpCmdLine*/,
    INT       /*cmdShow*/)
{
    if (CreateNewConsole(1024))
    {
        int i;

        // test stdio
        fprintf(stdout, "Test output to stdout\n");
        fprintf(stderr, "Test output to stderr\n");
        fprintf(stdout, "Enter an integer to test stdin: ");
        scanf("%d", &i);
        printf("You entered %d\n", i);

        // test iostreams
        std::cout << "Test output to std::cout" << std::endl;
        std::cerr << "Test output to std::cerr" << std::endl;
        std::clog << "Test output to std::clog" << std::endl;
        std::cout << "Enter an integer to test std::cin: ";
        std::cin >> i;
        std::cout << "You entered " << i << std::endl;

        std::cout << std::endl << "Press any key to continue..." << std::endl;
        _getch();

        ReleaseConsole();
    }

    return 0;
};
