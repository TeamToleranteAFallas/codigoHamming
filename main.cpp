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
int sevenBi[10];
int cantidadLet,c1,c2,c3,c4,c5;


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
    cout<<"codigo ascci\n";
    for (int i = 0;i<cantidadLet;i++){
        ascci=c[i];
        cout<<ascci<<" = "<<c[i]<<"\n";
        bitset<5> bs2(ascci);
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
    int aux[100],a[10];

    for(int k=0;k<10;k++){
        a[k]==0;
    }
    cout<<"\ntamanio del binario\n";
    longi = co.size();
    cout<<longi<<"\n";
    for(int j=0;j<longi;j++){
        datos[j]=co[j];
        cout<<datos[j];
        datosInt[j]= (int)datos[j];
    }
    cout<<"\n\n";
    cout<<"Se supone que es el arreglo en enteros\n";
    for(int k=0;k<longi;k++){
        bitset<1>bs3 (datosInt[k]);
        aux[k]=(int)(bs3.to_ulong());
        cout<<" "<<aux[k];
    }
    cout<<"\n";
    //aux contiene los elementos introducidos
    a[2]=aux[2];
    a[4]=aux[4];
    a[5]=aux[5];
    a[6]=aux[6];
    //a[7]=aux[4];
    a[8]=aux[8];
    a[9]=aux[9];
    a[10]=aux[10];
    a[11]=aux[11];
    a[12]=aux[12];
    a[13]=aux[13];
    a[14]=aux[14];
    //a[15]=aux[12];
    a[16]=aux[16];
    a[17]=aux[17];
    a[18]=aux[18];
    a[19]=aux[19];

    a[0]=a[0]^a[2]^a[4]^a[6]^a[8]^a[10]^a[12]^a[14]^a[16]^a[18];
    a[1]=a[1]^a[2]^a[5]^a[6]^a[9]^a[10]^a[13]^a[14]^a[17]^a[18];
    a[3]=a[3]^a[4]^a[5]^a[6]^a[11]^a[12]^a[13]^a[14]^a[19];
    a[7]=a[7]^a[8]^a[9]^a[10]^a[11]^a[12]^a[13]^a[14];
    a[15]=a[15]^a[16]^a[17]^a[18]^a[19];

    cout<<"\ntotal\n";
    for(int k=1;k<=20;k++)
        cout<<" "<<a[k];

    cout<<"\nse ingresan los 20 bits\n";
    for (int i=0;i<20;i++){
        cin>>sevenBi[i];
    }
    c1=sevenBi[0]^sevenBi[2]^sevenBi[4]^sevenBi[6]^a[8]^sevenBi[10]^sevenBi[12]^sevenBi[14]^sevenBi[16]^sevenBi[18];
    c2=sevenBi[1]^sevenBi[2]^sevenBi[5]^sevenBi[6]^a[9]^sevenBi[10]^sevenBi[13]^sevenBi[14]^sevenBi[17]^sevenBi[18];
    c3=sevenBi[3]^sevenBi[4]^sevenBi[5]^sevenBi[6]^a[11]^sevenBi[12]^sevenBi[13]^sevenBi[14]^sevenBi[19];
    c4=sevenBi[7]^sevenBi[8]^sevenBi[9]^sevenBi[10]^a[11]^sevenBi[12]^sevenBi[13]^sevenBi[14];
    c5=sevenBi[15]^sevenBi[16]^sevenBi[17]^sevenBi[18]^sevenBi[19];

    int p = c1*1+c2*2+c3*4+c4*6+c5*8;
    if(p==0){
            cout<<"\n no hay error\n";
    }
    else{
            cout<<"\n Hay error en la posicion "<<p<<"\n";
            if(sevenBi[p]==0)
                sevenBi[p]=1;
            else
                sevenBi[p]=0;
            for (int i=0;i<20;i++)
                cout<<" "<<sevenBi[i];
    }
}
