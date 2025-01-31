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

    cin >> v;

    v.GaussJordan();








    return 0;
}
