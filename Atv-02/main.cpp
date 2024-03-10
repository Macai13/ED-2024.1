#include "atividade02.hpp"
#include <cstdio>
#include <iostream>

int main()
{
    ponto a(15, 57), b(5, 20), c(10, 50), d(1, 1);
    ponto p(7, 27);

    ponto kust[] = { a, b, c, d };

    std::cout << minDist(p, kust, 4) << std::endl;

    return 0;
}