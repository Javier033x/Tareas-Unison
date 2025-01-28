#include <cmath>
#include "Vector.hpp"




void Vector::ImprimirVector()const{

    std::cout << "(";
    for(int i = 0; i < dimension; i++){

        std::cout << componente[i] << ", ";

    }

    std::cout << "\b\b)";

}


//Constructor con dos parametros y asignacion de valor al vector.
Vector::Vector(int dim/* = MAX_DIM*/, double valor/* = 0*/){

    EstablecerDim(dim);
    try {
        componente = new double [dimension];

        for(int i = 0; i < dimension; i++){
            componente[i] = valor;

        }
    }catch(std::bad_alloc){
        throw "Porblemas de asignacion de memoria";
    }

}

//Capturamos los valores de un vector
void Vector::CapturarVector(){

    for(int i = 0; i < dimension; i++){
        std::cout << "Componente " << i+1 << ": ";
        std::cin >> componente[i];

    }

}

//Metodo para calcular la suma de dos vectores
Vector Vector::operator+(const Vector v) const{

    if(dimension != v.dimension) throw "Vectores incompatibles para la suma";

    Vector s(dimension);

    for(int i = 0; i < dimension; i++){
        s.componente[i] = componente[i] + v.componente[i];


    }

    return s;

}


//Metodo para calcular la resta de dos vectores
Vector Vector::operator-(const Vector w) const{

    if(dimension != w.dimension) throw "Vectores incompatibles para la resta";

    Vector r(dimension);

    for(int i = 0; i < dimension; i++){
        r.componente[i] = componente[i] - w.componente[i];


    }

    return r;

}


//Metodo para calcular el producto punto de dos vectores
double Vector::operator*(const Vector w) const{

    if(dimension != w.dimension) throw "Vectores incompatibles para el producto punto";

    double f = 0;

    for(int i = 0; i < dimension; i++){

      f = (componente[i] * w.componente[i]) + f;

    }

    return f;

}

//Metodo para calcular el producto de un escalar y un vector
Vector Vector::operator*(const double escalar) const{

    Vector p(dimension);

    for(int i = 0; i < dimension; i++){

        p.componente[i] = componente[i] * escalar;



    }

    return p;

}

//Metodo para calcular la norma de un vector
double Vector::SacarNorma() const{

    double SumaNorma = 0;
    for(int i = 0; i < dimension; i++){

        SumaNorma = (componente[i]*componente[i]) + SumaNorma;

    }
        double Norma = std::sqrt(SumaNorma);
        return Norma;
}





//Metodo para calcular un escalar por producto

Vector operator*(double escalar, const Vector v){

    Vector q(v.dimension);

    for(int i = 0; i < v.dimension; i++){

        q.componente[i] = v.componente[i] * escalar;

    }

    return q;


}


//Metodo de utileria
void Vector::EstablecerDim(int dim){
    if(dim < 1){
        throw "Dimension invalida";
    }else{
        dimension = dim;
    }

}

std::ostream & operator<<(std::ostream &salida, const Vector v)
{
    salida << "(";
    for(int i = 0; i < v.dimension; i++){
        salida << v.componente[i] << ", ";
    }
    salida << "\b\b)";
    return salida;
}

std::istream & operator>>(std::istream &entrada, Vector &v){

    for(int i = 0; i < v.dimension; i++){
        std::cout << "Componente " << i+1 << ": ";
        entrada >> v.componente[i];

    }
    return entrada;

}

double Vector::operator[](int i) const{

    if(i < 0 || i > dimension) throw "Indice invalido";

    return componente[i];


}


double & Vector::operator[](int i){

    if(i < 0 || i > dimension) throw "Indice invalido";

    return componente[i];

}


Vector::~Vector(){

    delete [] componente;

}

Vector::Vector(const Vector &v){
    componente = NULL;
    *this = v;
}

Vector & Vector::operator=(const Vector &v){

    if(this == &v) return *this;
    delete [] componente;
    dimension = v.dimension;
    try {
        componente = new double [dimension];

        for(int i = 0; i < dimension; i++){
            componente[i] = v.componente[i];
        }
    }catch(std::bad_alloc){
        throw "Porblemas de asignacion de memoria";
    }

    return *this;

}



