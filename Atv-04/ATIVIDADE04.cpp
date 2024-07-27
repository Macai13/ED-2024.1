#include <string>
#include <queue>

// 1

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

   void sort()
   {
      for (int i = 0; i < capacity; i++)
      {
         for (int j = 0; j < capacity; j++)
         {
            if (u[i] < u[j])
            {
               int temp = u[i];
               u[i] = u[j];
               u[j] = temp;
            }
         }
      }
   }

   ~vetor() { delete [] u; }
   int& operator[] (int k) { return u[k]; } 
   int len() { return size; }

};

vetor mergeAll(vetor U[], int n) {
   int len = 0;
   std::queue<int> vetores[n];

   for (int j = 0; j < n; j++)
   {     
      len += U[j].len();
   }

   vetor retval = vetor(len);

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < U[i].len(); j++)
      {
         vetores[i].push(U[i].at(j));
      }
   }

   int x, index;

   for (int i = 0; i < len; i++)
   {
      for (int j = 0; j < n; j++)
      {
         if (j == 0)
         {
            while (vetores[j].empty())
            {
               j++;

               if (j >= n - 1) break;
            }
            x = vetores[j].front();
            index = j;
         }

         if (x > vetores[j].front()) 
         {
            x = vetores[j].front();
            index = j;
         }
      }

      while (!vetores[index].empty())
      {
         retval.push(x);
         vetores[index].pop();

         if (x < vetores[index].front()) break;

         x = vetores[index].front();
      }
   }

   return retval; 
}

/*
Exemplo 1

U = { [6,8,5], [3,2,1], [4,0,9] }

{ [6,8,5], [2,1], [4,0,9] } => {3}
{ [6,8,5], [1], [4,0,9] } => {3,2}
{ [6,8,5], [], [4,0,9] } => {3,2,1}
{ [6,8,5], [], [0,9] } => {3,2,1,4}
{ [6,8,5], [], [9] } => {3,2,1,4,0}
{ [8,5], [], [9] } => {3,2,1,4,0,6}
{ [5], [], [9] } => {3,2,1,4,0,6,8}
{ [], [], [9] } => {3,2,1,4,0,6,8,5}
{ [], [], [] } => {3,2,1,4,0,6,8,5,9}

Exemplo 2

U = { [1,3,5], [2,4,6], [7,8,9] }

{ [3,5], [2,4,6], [7,8,9] } => {1}
{ [3,5], [4,6], [7,8,9] } => {1,2}
{ [5], [4,6], [7,8,9] } => {1,2,3}
{ [5], [6], [7,8,9] } => {1,2,3,4}
{ [], [6], [7,8,9] } => {1,2,3,4,5}
{ [], [], [7,8,9] } => {1,2,3,4,5,6}
{ [], [], [8,9] } => {1,2,3,4,5,6,7}
{ [], [], [9] } => {1,2,3,4,5,6,7,8}
{ [], [], [] } => {1,2,3,4,5,6,7,8,9}

*/