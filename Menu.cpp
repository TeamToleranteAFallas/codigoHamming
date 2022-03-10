#include "Menu.h"

Menu::Menu(){
    mainMenu();
}
Menu::~Menu(){}

Menu::mainMenu(){
    std::cout << "Escriba un mensaje: " << std::endl;
    std::cin >> this->mensaje;
    
    hamming.setMensaje(this->mensaje);
    //agregar ruido

    std::cout << "Mensaje con 'ruido': " << this->mensaje << std::endl;
    
    /*
        imprimir aqui los errores detectados en formato
        caracter con ruido| codigo Hamming || caracter original| Hamming corregido
    1-
    2-
    3-
    ...
    n- 
    */
    std::cout << "Mensaje original: " << this->mensaje;   
    
}
