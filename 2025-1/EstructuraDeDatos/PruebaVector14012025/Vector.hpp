#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#include <iostream>



class Vector{

    friend Vector operator*(double escalar, const Vector v);
    friend std::ostream & operator<<(std::ostream &salida, const Vector v);
    friend std::istream & operator>>(std::istream &entrada, Vector &v);

public:

    //Constructor por default
    //Constructor con un parametro Un constructor de un solo parametro es un convertidor del tipo de dato a la clase que pertenece
    explicit Vector(int dim = 1 ,double valor = 0); //Constructor con dos parametros
    Vector(const Vector & v);
    ~Vector();
    Vector & operator=(const Vector &v);

    void ImprimirVector() const; //Metodo para imprimir un vector, ahora se le puede aplicar a vectores constantes
    void CapturarVector(); //Metodo para capturar los valores de un vector
    Vector operator+(const Vector v) const; //Metodo para sumar dos vectores
    Vector operator-(const Vector w) const; //Metodo para restar dos vectores
    double operator*(const Vector v) const; //Metodo para calcular el producto punto de dos vectores
    Vector operator*(const double escalar) const; //Metodo para calcular el producto entre un escalar y un vector
    double SacarNorma() const;

    double operator[](int i) const;
    double & operator[](int i);



private:
    int dimension;
    double *componente;
    void EstablecerDim(int dimension); //Metodo de utileria




};



#endif // VECTOR_HPP_INCLUDED
