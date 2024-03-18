#include "atividade03.hpp"
#include <iostream>

using std::cout, std::endl;

int main()
{
    aluno::frac * fracs = aluno::loadFracs("10 : 4/8 1/2 3/1 4/1 5/1 6/16 7/1 81/1 9/12 100/1");
    aluno::sortFracs(fracs, 10);

    for (int i = 0; i < 10; i++)
    {
        cout << fracs[i].getNum() << " / " << fracs[i].getDen() << endl;
    }

    aluno::frac sum = aluno::sumFracs(fracs, 10);

    cout << "sum: " << sum.getNum() << "/" << sum.getDen() << endl;

    return 0;
}