#include "ATIVIDADE07.hpp"

int main(void)
{
    std::cout << "compiler version: " <<__cplusplus << std::endl;

    std::cout << "1234" << std::endl;
    bigNumber num = bigNumber(1234);
    num.print();

    std::cout << "98732345" << std::endl;
    bigNumber y = bigNumber(98732345);
    y.print();

    std::cout << "12563" << std::endl;
    bigNumber z = bigNumber(12563);
    z.print();

    std::cout << "0" << std::endl;
    bigNumber a = bigNumber();
    a.print();

    std::cout << "1234 + 1434 = " << 1234 + 1434 << std::endl;
    num += 1434;
    num.print();

    std::cout << "12563 + 98732345 = " << 12563 + 98732345 << std::endl;
    z += y;
    z.print();

    std::cout << "12 * 201 = " << 12 * 201 << std::endl;
    bigNumber tw = bigNumber(12);
    bigNumber th = bigNumber(201);
    tw *= th;
    tw.print();

    return 0;
}

//bn class fn
/*void print()
    {
        struct nodo * atual = pt;

        while (atual != NULL) 
        {
            std::cout << atual->digit << " ---> ";
            atual = atual->next;
        }

        std::cout << "NULL" << std::endl;
    }*/