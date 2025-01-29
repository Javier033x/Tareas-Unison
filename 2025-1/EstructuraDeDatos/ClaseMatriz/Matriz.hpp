#ifndef MATRIZ_HPP_INCLUDED
#define MATRIZ_HPP_INCLUDED

#include <iostream>

#define MAX_RENGLON 10
#define MAX_COLUMNA 10

enum {
    ESP=32,     /**< Espacio en blanco */
	BV=179,     /**< Barra vertical */
	ESD=191,    /**< Esquina superior derecha */
	EII,        /**< Esquina inferior izquierda */
	BH=196,     /**< Barra horizontal */
	EID=217,    /**< Esquina inferior derecha  */
	ESI         /**< Esquina superior izquierda */
};

class Matriz {
    friend Matriz operator*(double escalar, const Matriz v);
    friend std::istream & operator>>(std::istream &entrada, Matriz &v);
    friend std::ostream & operator<<(std::ostream &salida, Matriz &v);
public:

   explicit Matriz(int renglon = 1, int columna = 1);    //Contructor con dos parametros
   //~Matriz();    //Destructor
   //Matriz (const Matriz &v);   //Constructor de copias
  // Matriz & operator= (const Matriz &v);   //Operador =


   Matriz operator+ (const Matriz v) const;   //Operador sobrecargado(Suma de dos matrices)
   Matriz operator- (const Matriz v) const;   //Operador sobrecargado(Resta de dos matrices)
   double operator* (const Matriz v) const;   //Operador sobrecargado(Producto de dos matrices)
   Matriz operator* (const double escalar) const;   //Operador sobrecargado(Producto de matriz por escalar)



private:
    int renglon;
    int columna;
    int elemento[MAX_RENGLON][MAX_COLUMNA];





};

#endif // MATRIZ_HPP_INCLUDED
