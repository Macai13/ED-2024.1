#include <iostream>
#include "ATIVIDADE06.hpp"

int main(void)
{                  
    int array[] = { 999, 31, 313, 157, 109, 753, 129, 91, 269 };

    alternativeRadixsort(array, 9, 3);

    for (int i = 0; i < 9; i++)
    {
        std::cout << array[i] << std::endl;
    }

    return 0;
}
