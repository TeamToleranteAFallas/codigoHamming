#ifndef Menu_h
#define Menu_h

#include "Hamming.h"
#include <iostream>
#include <string>
class Menu{
public:
    Menu();
    ~Menu();
    void mainMenu();
private:
    Hamming hamming;
    std::string mensaje;
};

#endif //Menu_h