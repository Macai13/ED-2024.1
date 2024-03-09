#include "atividade01.hpp"
#include <cstdio>
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    const int n = 5;
    int M[n];

    cout << "mdc: " << mdc(990, 300) << endl;
    loadPrimeVec(M, n);

    for (int i = 0; i < n; i++)
    {
        cout << M[i] << endl;
    }

    return 0;
}