#include <iostream>

/*
Seja um BIGnUMBER um inteiro positivo ou zero representado por uma lista encadeada. Cada dígito ocupa um nó da estrutura.
A significância dos algarismos é de menor para maior a partir da raiz. Por exemplo, o número 1234 é armazenado pela lista:

|-> 4 -> 3 -> 2 -> 1  

Onde |-> representa o ponteiro da raiz e -> outras conexões entre nós. Implemente bigNumber no modelo de classe a seguir,
*/

class bigNumber 
{

    struct nodo 
    {
        int digit;
        nodo * next;
    };

    nodo * pt;

private:
    void add(int digit)
    {
        struct nodo * novo_nodo = new struct nodo;

        novo_nodo->digit = digit;
        novo_nodo->next = nullptr;

        if (pt == nullptr)
        {
            pt = novo_nodo;

            return;
        }

        struct nodo * atual = pt;

        while (atual->next != nullptr)
            atual = atual->next;

        atual->next = novo_nodo;
    }

    void add_big_number(int x)
    {
        while (x > 0)
        {
            add(x % 10);
            x /= 10;    
        }
    }
public:
    bigNumber(int x) 
    { 
        /* cria um novo bigNumber distribuindo os dígitos de x na lista encadeada. */ 
        pt = nullptr;

        add_big_number(x);
    }

    bigNumber() 
    { 
        /* inicia um bigNumber com valor zero */
        pt = nullptr;

        add(0);
    }

    void operator+=(int x)
    { 
        /* soma x a um bigNumber */
        int new_big_num = x + to_int();
        pt = nullptr;

        add_big_number(new_big_num);
    }

    void operator*=(int x)
    { 
        /* multiplica x a um bigNumber */ 
        int new_big_num = x * to_int();
        pt = nullptr;

        add_big_number(new_big_num);
    }

    void operator+=(bigNumber& bn)
    { 
        /* soma bigNumber a outro */
        int new_big_num = bn.to_int() + to_int();
        pt = nullptr;

        add_big_number(new_big_num);

    }
    void operator*=(bigNumber& bn) 
    {
        /* multiplica bigNumber a outro */
        int new_big_num = bn.to_int() * to_int();
        pt = nullptr;

        add_big_number(new_big_num);
    }

    bool operator==(bigNumber& bn)
    { 
        /* compara bigNumbers */
        return bn.to_int() == to_int(); 
    }

    int to_int()
    {
        struct nodo * atual = pt;
        char num_str[11];
        int count = 0;

        while (atual != nullptr) 
        {
            num_str[count] = atual->digit + '0';
            atual = atual->next;
            count++;
        }
        num_str[count] = '\0';

        int int_pt = 0, mod, num = 0;

        for (char ch : num_str)
        {
            if (ch - '0' >= 0 && ch - '0' <= 9)
                num = (ch - '0') + num * 10;
            else break;
        }

        while (num > 0)
        {
            mod = num % 10;
            int_pt = int_pt * 10 + mod;
            num /= 10;
        }

        return int_pt;
    }

    void print()
    {
        struct nodo * atual = pt;

        while (atual != nullptr) 
        {
            std::cout << atual->digit << " ---> ";
            atual = atual->next;
        }

        std::cout << "NULL" << std::endl;
    }
};