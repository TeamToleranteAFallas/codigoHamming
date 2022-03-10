#include "Menu.h"

Menu::Menu(){
    mainMenu();
}

Menu::~Menu(){}

void Menu::mainMenu(){
    std::cout << "Escriba un mensaje: " << std::endl;
    std::getline(std::cin,this->mensaje);
    
    hamming.setMensaje(this->mensaje);

    //imprimir decodificacion Hamming del mensaje
    for (int i = 0; i < hamming.getMensaje().length(); i++) {
        std::cout << hamming.getMensaje()[i] << "|";
        for (int j = 0; j < 11; j++) {
            std::cout<<hamming.getCodes()[i][j];
        }
        std::cout << std::endl;
    }

    hamming.agregarRuido();

    std::cout << "Mensaje con 'ruido': " << hamming.getMensaje() << std::endl;
    
    int error_count = 0;
    
    for (int i = 0; i < hamming.getMensaje().length(); i++) {
        std::cout << hamming.getMensaje()[i] << "|";
        int error = hamming.encontrarError(hamming.getCodes()[i]);
        for (int j = 0; j < 11; j++) {
            if (j == error-1) {
                error_count++;
                std::cout <<'*'<< hamming.getCodes()[i][j]<<'*';
            }
            else
                std::cout << hamming.getCodes()[i][j];
        }
        std::cout << std::endl;
    }
    
    std::cout <<error_count <<" errore(s) encontrados." << std::endl;
    
    std::cout << "--Corrigiendo errores--" << std::endl;
    
    hamming.corregir();

    std::cout << "Mensaje original: " << hamming.getMensaje()<<std::endl;

    for (int i = 0; i < hamming.getMensaje().length(); i++) {
        std::cout << hamming.getMensaje()[i] << "|";
        for (int j = 0; j < 11; j++) {
            std::cout << hamming.getCodes()[i][j];
        }
        std::cout << std::endl;
    }
}
