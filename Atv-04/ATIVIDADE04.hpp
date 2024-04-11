#include <string>
#include <iostream>

class vetor {
   int *u;  // ponteiro para vetoe
   int size; // tamanho do vetor
   int capacity;
public:
   vetor(int n = 0)
   {
      u=new int[n];
      size = n;
      capacity = 0;
   }

   vetor(int n, int value): vetor(n)
   {
      for (int i = 0; i < n; i++)
      {
         u[i] = value;
      }

      capacity = n;
   }

   vetor(int n, int * arr_value): vetor(n)
   {
      for (int i = 0; i < n; i++)
      {
         u[i] = arr_value[i];
      }

      capacity = n;
   }

   int& at(int index)
   {
      if (index >= size)
      {
         throw std::string("invalid index");
      }

      return u[index];
   }

   void push(int x)
   {
      if (capacity < size)
      {
         u[capacity] = x;
         capacity++;
      }
   }

   void sort();

   ~vetor() { delete [] u; }
   int& operator[] (int k) { return u[k]; } 
   int len() { return size; }

};

vetor mergeAll(vetor[], int);