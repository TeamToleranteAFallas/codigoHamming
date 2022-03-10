#ifndef Hamming_h
#define Hamming_h
#include <string>
#include <stdlib.h>
#include <random>//posiblemente sea necesario cambiar esta librería por <rand.h>
#include <time.h>
class Hamming{
    public:
        Hamming();
        ~Hamming();

        void setMensaje(std::string);
        std::string getMensaje();

        int** getCodes();

        void codificacionHamming(std::string);
        char decodificacionHamming(int data[]);
       
        void agregarRuido();
        void corregir();

        int encontrarError(int data[]);
    private:
        std::string mensaje;
        int **asciiHamming;

        unsigned int pow_of_two(int);

        int calcularP1(int data[]);
        int calcularP2(int data[]);
        int calcularP4(int data[]);
        int calcularP8(int data[]);

        int calcularC1(int data[]);
        int calcularC2(int data[]);
        int calcularC4(int data[]);
        int calcularC8(int data[]);
};

#endif //Haming_h