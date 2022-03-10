#ifndef Hamming_h
#define Hamming_h
#include <string>

class Hamming{
    public:
        Hamming();
        ~Hamming();

        void setMensaje(std::string);
        std::string getMensaje();

        int* getCodes();

        void codificacionHamming(std::string);
        //void decodificacionHamming();

        
        //void corregir();
        //void agregarRuido();

    private:
        std::string mensaje;
        int *caracter;

        int* HammingCode(char);
        unsigned int pow_of_two(int);
        int calcularP1(int data[11]);
        int calcularP2(int data[11]);
        int calcularP4(int data[11]);
        int calcularP8(int data[11]);
};

#endif //Haming_h