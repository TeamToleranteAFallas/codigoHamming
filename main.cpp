#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include <cmath>

using namespace std;
string ingresarDatos();
string divDatos(string c);
string concatDatso(string co);
void crearPardad();

int paridad[10];
int cantidadLet;


int main() {
    ingresarDatos();

   return 0;
}

string ingresarDatos(){
    string cadena;
    cout<<"Ingresa la entrada: ";
    cin>>cadena;

    cantidadLet=cadena.size();
    cout<<"cantidad de lettras\n";
    cout<<cantidadLet<<"\n";
    divDatos(cadena);
}

string divDatos(string c){
    int ascci;
    string aux1;
    string aux;
    for (int i = 0;i<cantidadLet;i++){
        ascci=c[i];
        cout<<"\n"<<ascci<<"\n";
        bitset<8> bs2(ascci);
        cout<<bs2<<"\n";
        aux=bs2.to_string();
        aux1 += aux;
        ascci=0;
    }
    concatDatso(aux1);

}

string concatDatso(string co){
    int longi;
    char datos[100];
    int datosInt[100];
    int aux[100];
    cout<<"\ntamanio del binario\n";
    longi = co.size();
    cout<<longi<<"\n\n";
    for(int j=0;j<longi;j++){
        datos[j]=co[j];
        cout<<datos[j]<<"\n";
        datosInt[j]= (int)datos[j];
    }
    cout<<"Se supone que es el arreglo en enteros\n";
    for(int k=0;k<longi;k++){
        bitset<1>bs3 (datosInt[k]);
        cout<<bs3<<"\n";
        aux[k]=(int)(bs3.to_ulong());
    }
    cout<<"Se supone que es el arreglo en enteros\n";
    for(int l=0;l<longi;l++){
        cout<<aux[l]<<"\n";
    }
    crearPardad();
}

void crearPardad(){
    cout<<"paridad\n";
    for(int i =0;i<8;i++){
        paridad[i]=pow(2,i);
    }
}
