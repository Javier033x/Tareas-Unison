#include "Matriz.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

//Constructor
Matriz::Matriz(int renglon /* = 1*/,int columna/* = 1*/){
    this->renglon = renglon;
    this->columna = columna;
}

//Operador sobrecargado de extraccion
std::istream & operator>>(std::istream &entrada, Matriz &v){
    std::cout << "Ingrese los valores de la matriz:\n";
    for(int i = 0; i < v.renglon; ++i){
        for(int j = 0; j < v.columna; ++j){
            std::cout << "Elemento: [" << i+1 <<"][" << j+1 << "]:\n";
            std::cin >> v.elemento[i][j];
        }
    }
    return entrada;
}

//Operador sobrecargado de insercion
std::ostream & operator<<(std::ostream &salida, Matriz &v){
    //Primera Fila
    std::cout << (char)ESI << (char)ESP;
    for(int j = 0; j < v.columna; j++){
        std::cout << std::setw(3) << v.elemento[0][j] << (char)ESP;
    }
    std::cout << (char)ESD << "\n" ;

    //Filas del medio
    for(int i = 1; i < v.renglon -1; ++i){
        std::cout << (char)BV << (char)ESP;
        for(int j = 0; j < v.columna; ++j){
            std::cout << std::setw(3) << v.elemento[i][j] << (char)ESP;
        }
        std::cout << (char)BV << "\n";
    }

    //Ultima fila
    for(int j = 0; j < v.columna; ++j){
            std::cout << std::setw(3) << v.elemento[v.renglon - 1][j] << (char)ESP;
    }
    std::cout << (char)EID << "\n";


    return salida;


}

//Suma de dos matrices
Matriz Matriz::operator+ (const Matriz v) const{
    if(renglon != v.renglon || columna != v.columna) throw "Suma incompatible";

    Matriz m(renglon,columna);

    for(int i = 0; i < v.renglon; ++i){
        for(int j = 0; j < v.columna; ++j){
            m.elemento[i][j] = elemento[i][j] + v.elemento[i][j];
        }
    }

    return m;
}

//Resta de dos matrices
Matriz Matriz::operator- (const Matriz v) const{
    if(renglon != v.renglon || columna != v.columna) throw "Resta incompatible";

    Matriz m(renglon,columna);

    for(int i = 0; i < v.renglon; ++i){
        for(int j = 0; j < v.columna; ++j){
            m.elemento[i][j] = elemento[i][j] - v.elemento[i][j];
        }
    }

    return m;
}

//Multiplicacion matriz por escalar
Matriz Matriz::operator* (const double escalar) const{

    Matriz m(renglon,columna);

    for(int i = 0; i < renglon; ++i){
        for(int j = 0; j < columna; ++j){
            m.elemento[i][j] = elemento[i][j] * escalar;
        }
    }
    return m;
}

//Multiplicacion matriz por escalar (Conmutativo)
Matriz operator*(double escalar, const Matriz v){

    Matriz m(v.renglon,v.columna);

    for(int i = 0; i < v.renglon; ++i){
        for(int j = 0; j < v.columna; ++j){
            m.elemento[i][j] = escalar * v.elemento[i][j];
        }
    }
    return m;
}

double* Matriz::operator[](int i){

    if(i < 0 || i > renglon) throw "Indice invalido";

    return elemento[i];

}


Matriz Matriz::GaussJordan(){
    if(renglon != columna) throw "No es matriz cuadrada";
    double pivote, aux;
    Matriz identidad(renglon,columna);

    //Inicializacion de la matriz identidad
    for(int i = 0; i < renglon; ++i){
        for(int j = 0; j < columna; ++j){
            if(i==j){
                identidad[i][j] = 1;
            }else{
                identidad[i][j] = 0;
            }


        }

    }

    //Reduccion por renglones
    for(int i; i < renglon; ++i ){
        pivote = elemento[i][i];
        for(int k = 0; k < renglon; ++k){
            elemento[i][k] = elemento[i][k]/pivote;
            identidad[i][k] = identidad[i][k]/pivote;
        }
        for(int j = 0; j < renglon; ++j){
            if(i!=j){
                aux = elemento[j][i];
                for(int k = 0; k < renglon; ++k){
                    elemento[j][k] = elemento[j][k] - aux * elemento[i][k];
                    identidad[j][k] = identidad[j][k] - aux * identidad[i][k];
                }
            }
        }


    }

    if(std::isinf(identidad[0][0]) || (-1)*std::isinf(identidad[0][0]) ) throw "No tiene inversa";

    return identidad;

}








