#include <iostream>

#include "Matriz.hpp"

using namespace std;

int main()
{
    int n, m;
    double escalar;

    cin >> n;
    cin >> m;
    Matriz v(n,m);
    Matriz w(n,m);
    Matriz r(n,m);

    //captura de la matriz
    cin >> v;
    cout << endl;
    cin >> w;

    //suma de la matriz
    r = v + w;
    cout << v << "+" << w << "=" << r;
    cout << endl;

    //resta de la matrz
    r = v - w;
    cout << v << " - " << w << " = " << r;
    cout << endl;

    //matriz por escalar
    cout << "Inserte un escalar:" << endl;
    cin >> escalar;
    r = v * escalar;
    cout << v << "*" << escalar << "=" << r;

    //escalar por matriz(conmutativo)
    cout << endl;
    r = escalar * v;
    cout << v << "*" << escalar << "=" << r;








    return 0;
}
