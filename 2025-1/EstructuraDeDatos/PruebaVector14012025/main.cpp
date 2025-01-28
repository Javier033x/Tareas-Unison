#include <iostream>

#include "Vector.hpp"

using namespace std;

int main()
{

    int  n;
    double f,escalar;

    cout <<  "Programa que suma dos vectores" << endl;

//---------------------- CAPTURA DE VECTORES ----------------------
    do{
        cout << "Dimension [1, " << "x" << "]" << endl;
        cout << "Ingresa la dimension" << endl;
        cin >> n;

    }while(n < 1);

    Vector v(n), w(n), z(n), r(n), p(n), a(n);

    cout << "Capturando el primer vector" << endl;
    cin >> v;

    cout << endl;

    cout << "Capturando el segundo vector" << endl;
    cin >> w;

    cout << "\n" << v[2] << "\n";


//---------------------- SUMA DE DOS VECTORES ----------------------
    z = v + w;

    cout << endl << "----------- Suma -----------\n\n";

    cout << v << " + " << w << " = " << z << "\n\n";

//---------------------- RESTA DE DOS VECTORES ----------------------

    r = v - w;

    cout << endl << "----------- Resta -----------\n\n";

    cout << v << " - " << w << " = " << r << "\n\n";


//---------------------- PRODUCTO PUNTO DE DOS VECTORES ----------------------

    f = v * w;

    cout << endl << "----------- Producto Punto -----------\n\n";

    cout << v << " * " << w << " = " << f << "\n\n";

//---------------------- PRODUCTO POR ESCALAR ----------------------

    cout<<"----------- Producto por Escalar -----------\n\n" << "Para calcular el producto por escalar, ingrese el valor de un real." << endl;

    cin >> escalar;

    p = escalar * v;
    a = w * escalar;

    cout << endl << v << " * " << escalar << " = " << p << "\n\n";
    cout << w << " * " << escalar << " = " << a << "\n\n";


//---------------------- NORMA DE VECTORES ----------------------

    cout<<"----------- Norma de Vectores -----------\n\n";

    cout << "Norma del vector: " << v << "\n" << v.SacarNorma();

    cout << "\n\nNorma del vector: " << w << "\n" << w.SacarNorma() << "\n\n";


    return 0;
}
