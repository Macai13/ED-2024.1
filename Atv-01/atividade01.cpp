//AS FUNÇÕES A SEGUIR DEVEM SER 
// IMPLEMENTADAS USANDO RECURSIVIDADE.
// FUNÇÕES AUXILIATES PODEM SER 
// USADAS DESDE QUE SEJAM TAMBÉM RECURSIVAS.

// 1
// calcula o mdc de dois inteiros dados.   
int mdc(int a, int b  ) {
    if (a % b == 0)
    {
        return b;
    }

    return mdc(b, a % b);
}

bool isPrime(int n, int i = 2)
{
    if (n <= 2) 
    { 
        if (n == 2)
        {
            return true;
        }

        return false;
    }
    
    if (n % i == 0) 
    {
         return false;
    }

    if (i * i > n)
    {
        return true;
    }

    return isPrime(n, i + 1);
}

int nextPrime(int x)
{
    if (isPrime(x + 1))
    {
        return x + 1;
    }

    return nextPrime(x + 1);
}

void loadPrimeVec2(int M[], int n, int z)
{    
    if (n == z)
    {
        M[0] = 2;
    }
    else 
    {
        M[z - n] = nextPrime(M[z - n - 1]);
    }

    if (n == 0)
    {
        return;
    }

    loadPrimeVec2(M, n - 1, z);
}

// 2
// Carregar no vetor M de tamanho
// n os n primeiros primos.começando em 2
// Note que o argumento de entrada M é saída neste problema. 
void loadPrimeVec(int M[], int n)  {
    loadPrimeVec2(M, n, n);
}

