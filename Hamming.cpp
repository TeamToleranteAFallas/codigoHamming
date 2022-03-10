#include "Hamming.h"

Hamming::Hamming(){
    this->mensaje = "";
}

Hamming::~Hamming(){
    for (int i = 0; i < mensaje.length(); i++) {
        delete asciiHamming[i];
    }
    delete []asciiHamming;
}

void Hamming::setMensaje(std::string mensaje){
    this->mensaje = mensaje;
    asciiHamming = new int* [mensaje.length()];
    for (int i = 0; i < mensaje.length(); i++) {
        asciiHamming[i] = new int[11];
    }
    codificacionHamming(this->mensaje);
}

std::string Hamming::getMensaje(){
    return this->mensaje;
}

int** Hamming::getCodes(){
    return asciiHamming;
}

void Hamming::codificacionHamming(std::string mensaje){
    for(int i = 0; i < this->mensaje.length(); i++){
        for(int k = 10, j = 0; k >= 0; k--){
            if(k == 0 || k == 1 || k == 3 || k == 7)
                asciiHamming[i][k] = 0;
            else{
                this->asciiHamming[i][k] =  mensaje[i] & pow_of_two(j)? 1 : 0;
                j++;
            }                
        }
        asciiHamming[i][0] = calcularP1(asciiHamming[i]);
        asciiHamming[i][1] = calcularP2(asciiHamming[i]);
        asciiHamming[i][3] = calcularP4(asciiHamming[i]);
        asciiHamming[i][7] = calcularP8(asciiHamming[i]);
    }
}

char Hamming::decodificacionHamming(int data[]){
    int ascii = 0;
    ascii += data[2] * 64;
    ascii += data[4] * 32;
    ascii += data[5] * 16;
    ascii += data[6] * 8;
    ascii += data[8] * 4;
    ascii += data[9] * 2;
    ascii += data[10] * 1;
    (char)ascii;
    return (char)ascii;
}

int Hamming::encontrarError(int data[]){
    int error = 0;
    error += calcularC8(data) * 8;
    error += calcularC4(data) * 4;
    error += calcularC2(data) * 2;
    error += calcularC1(data) * 1;
    return error;
}

void Hamming::corregir(){
    for (int i = 0; i < mensaje.length(); i++) {
        int error = encontrarError(asciiHamming[i]);
        if(error <=10)
            if (error) {
                asciiHamming[i][error - 1] = !asciiHamming[i][error - 1];
            }
        mensaje[i] = decodificacionHamming(asciiHamming[i]);
    }
}

void Hamming::agregarRuido(){
    srand(time(NULL));

    for (int i = 0; i < mensaje.length(); i++) {
        int coin = rand() % 10;
        int error = rand() % 10;
        if(coin >= 5)
            asciiHamming[i][error] = !asciiHamming[i][error]; 
    }

    for (int i = 0; i < mensaje.length(); i++) {
        mensaje[i] = decodificacionHamming(asciiHamming[i]);
    }
}

unsigned int Hamming::pow_of_two(int i){
    return 1 << i;
}

int Hamming::calcularP1(int data[]){    
    return data[2]^data[4]^data[6]^data[8]^data[10];
}

int Hamming::calcularP2(int data[]){
    return data[2]^data[5]^data[6]^data[9]^data[10];
}

int Hamming::calcularP4(int data[]){
    return data[4]^data[5]^data[6];
}

int Hamming::calcularP8(int data[]){
    return data[8]^data[9]^data[10];
}

int Hamming::calcularC1(int data[]){
    return data[0] ^ data[2] ^ data[4] ^ data[6] ^ data[8] ^ data[10];
}

int Hamming::calcularC2(int data[]){
    return data[1] ^ data[2] ^ data[5] ^ data[6] ^ data[9] ^ data[10];
}

int Hamming::calcularC4(int data[]){
    return data[3] ^ data[4] ^ data[5] ^ data[6];
}

int Hamming::calcularC8(int data[]){
    return data[7] ^ data[8] ^ data[9] ^ data[10];
}
