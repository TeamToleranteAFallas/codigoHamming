#include "Hamming.h"

Hamming::Hamming(){
    this->mensaje = "";
    this->caracter = nullptr;
}

Hamming::~Hamming(){
    delete []this->caracter;
    this->caracter = nullptr;
}

void Hamming::setMensaje(std::string mensaje){
    this->mensaje = mensaje;
    this->caracter = new char[this->mensaje.length()][11];
    codificacionHamming(this->mensaje);
}

std::string Hamming::getMensaje(){
    return this->mensaje;
}

int* Hamming::getCodes(){
    return this->caracter;
}

void Hamming::codificacionHamming(){
    for(int i = 0; i < this->mensaje.length(); i++){
        for(int k = 10, j = 0; k >= 0; k--){
            if(k == 0 || k == 1 || k == 3 || k == 7)
                this->caracter[i][k] = 0;
            else{
                this->caracter[i][k] =  a & pow_of_two(j)? 1 : 0;
                j++;
            }                
        }
        this->caracter[i][0] = calcularP1(this->caracter[i]);
        this->caracter[i][1] = calcularP2(this->caracter[i]);
        this->caracter[i][3] = calcularP3(this->caracter[i]);
        this->caracter[i][7] = calcularP4(this->caracter[i]);
    }
}

unsigned int Hamming::pow_of_two(int i){
    return 1 << i;
}

int Hamming::calcularP1(int data[11]){    
    return data[2]^data[4]^data[6]^data[8]^data[10];
}

int Hamming::calcularP2(int data[11]){
    return data[2]^data[5]^data[6]^data[9]^data[10];
}

int Hamming::calcularP3(int data[11]){
    return data[4]^data[5]^data[6];
}

int Hamming::calcularP4(int data[11]){
    return data[8]^data[9]^data[10];
}
