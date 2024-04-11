#include <iostream>
#include "ATIVIDADE04.hpp"

int main(void)
{
    int a[] = { 1, 5, 3, 42 };
    int b[] = { 0, 20, 31, 433 };
    int c[] = { 10, 112, 8, 44 };
    int d[] = { 7, 33, 3 };
    int e[] = { 11, 2, 9, 4, 5, 6 };
    vetor vetores[] = { vetor(4, a), vetor(4, b), vetor(4, c), vetor(3, d), vetor(6, e) };

    vetor retvec = mergeAll(vetores, 5);

    std::cout << "[ ";
    for (int i = 0; i < retvec.len(); i++)
    {
        std::cout << retvec.at(i) << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}