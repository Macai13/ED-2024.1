#include <fstream>

namespace aluno {

/*
Representa uma fração reduzida, ou seja, numerador e denominador são primos entre si.  
*/

class frac {
   int num;
   int den;
   static int mdc(int a, int b) {
        if(a%b == 0)
            return b;
        return mdc(b, a%b);
   }
public:   
frac(int n=0, int d=1) {  
       num = n;
       den = d;
   }
   // Operadores 
   bool operator>(frac& frac) {
        // configura operador >
        if (((float)num / den) > ((float)frac.getNum() / frac.getDen()))
        {
            return true;
        }

        return false;
   }
   bool operator==(frac& frac) {
        // configura operador ==
        if (((float)num / den) == ((float)frac.getNum() / frac.getDen()))
        {
            return true;
        }

        return false;
   }
   frac operator+(frac& fracc) {
        int x = fracc.getNum() * den + fracc.getDen() * num;
        int y = fracc.getDen() * den;

        return frac(x, y);
    }     
   int getNum() { return num; }    
   int getDen() { return den; } 
};

frac* loadFracs(char* fileFracs) {

/* 
Retorna frações num arquivo e as coloca em um vetor alocaso dinamicamente. 

O conteúdo de tais arquivos segue o formato do esquema a seguir,

-----------
4           | -> 4 frações
1   2       | -> fração 1/2
3   5       | -> fração 1/5
2   9       ! -> fração 2/9 
7   11      ! -> fração 7/11
-------------
*/
    std::ofstream file;
    frac * fracs = (frac*)malloc(sizeof(frac) * 16);
    int x,y;
    int fracs_count = 0;

    file.open("fracoes.txt");

    for (int i = 0, count = 0; fileFracs[i] != '\0'; i++)
    {
        if (fileFracs[i] >= 48 && fileFracs[i] <= 57)
        {
            if (count == 0)
            {
                file << fileFracs[i] << std::endl;
                count++;
            }
            else 
            {
                if (count % 2 != 0)
                {
                    file << fileFracs[i];
                    if (fileFracs[i + 1] >= 48 && fileFracs[i + 1] <= 57) { file << fileFracs[i + 1]; x = 10 *(fileFracs[i] - '0') + (fileFracs[i + 1] - '0'); i++; }
                    else x = fileFracs[i] - '0';
                    file << '\t';
                }
                else  
                {
                    file << fileFracs[i];
                    if (fileFracs[i + 1] >= 48 && fileFracs[i + 1] <= 57) { file << fileFracs[i + 1]; y = 10 *(fileFracs[i] - '0') + (fileFracs[i + 1] - '0'); i++; }
                    else y = fileFracs[i] - '0';
                    file << std::endl;
                    *(fracs + fracs_count) =  frac(x, y);
                    fracs_count++;
                }
                count++;
            }
        }
    }

    file.close();

    return fracs; 
}

frac sumFracs(frac fracs[], int n) {
  /* 
   Retorna soma de frações do vetor de entrada. 
*/
    frac sum(0, 1);

    for (int i = 0; i < n; i++)
    {
        sum.operator+(fracs[i]);
    }

    return sum;

}

void swap(frac& a, frac& b)
{
    frac r = a;
    a = b;
    b = r;
}

void sortFracs(frac fracs[], int n) {
    /*
       ordena vetor de drações de entrada. Note que um ponteiro do vetor real é passado como argumento. O tamanho passaso  do vetor é dado por n.   
    */
   //frac x = fracs[0];
   int z = 0;
    loop:

   for (int i = z; i < n; i++)
   {
        //std::cout << z << ": " << "is " << fracs[0 + z].getNum() << "/" << fracs[0 + z].getDen() << " bigger than " << fracs[i].getNum() << "/" << fracs[i].getDen() << "? " << fracs[0 + z].operator>(fracs[i]) << std::endl;

        if (fracs[0 + z].operator>(fracs[i]) && i != 0)
        {
            frac temp = fracs[0 + z];       
            fracs[0 + z] = fracs[i];
            fracs[i] = temp;
        }        
   }

   z++;

   while (z != n)
        goto loop;
}

}
