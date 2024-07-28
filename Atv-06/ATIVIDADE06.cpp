#include <queue>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int f_digit(int n) 
{ 
  while (n >= 10)  
    n /= 10; 
      
  return n; 
} 

void print_vec(vector<int> u)
{
  for (int i = 0; i < u.size(); i++)
  {
    if (i == 0) cout << '[';

    cout << u.at(i);

    if (i == u.size() - 1)
    {
      cout << "]" << endl;

      return;
    }

    cout << ", ";
  }
}

int get_min_ind(vector<int> u)
{
  int min = u.at(0);
  int oloko = 0;

  for (int i = 0; i < u.size(); i++)
  {
    if (min > u.at(i))
    {
      min = u.at(i);
      oloko = i;
    }
  }

  return oloko;
}

void alternativeRadixsort(int u[], int n,int d) {
  queue<int> buckets[2];
  vector<int> output;
  vector<int> temp;

  int exp;

  for (int i = 0; i < d; i++)
  {
    output.clear();
    temp.clear();

    exp = pow(10, i + 1);

    if (i == 0)
    {
      for (int i = 0; i < n; i++)
      {
        output.push_back(u[i]);
      }
    }

    for (int j = 0; j < n; j++)
    {
      if (i == 0) temp.push_back(output.at(j) % exp);
      else
      {
        for (;;)
        {
          if (buckets[0].empty())
          {
            break;
          }

          temp.push_back(buckets[0].front() % exp);
          output.push_back(buckets[0].front());
          buckets[0].pop();
        }

        for (;;)
        {
          if (buckets[1].empty())
          {
            break;
          }

          temp.push_back(buckets[1].front() % exp);
          output.push_back(buckets[1].front());
          buckets[1].pop();
        }

        break;
      }
    }

    for (int j = 0; j < n; j++)
    {
      print_vec(temp);

      int index = get_min_ind(temp);
      int x = output.at(index);

      if (f_digit(x) == 0 || f_digit(x) == 1 || f_digit(x) == 2 || f_digit(x) == 3 || f_digit(x) == 4 || x < exp / 10)
      {
        cout << "I: " <<f_digit(x) << endl;
        buckets[0].push(x);
      }
      else  
      {
        cout << "II: " << f_digit(x) << endl;
        buckets[1].push(x);
      }

      temp.erase(temp.begin()+index);
      output.erase(output.begin()+index);
    }
  }

  output.clear();

  for (;;)
  {
    if (buckets[0].empty())
    {
      break;
    }

    output.push_back(buckets[0].front());
    buckets[0].pop();
  }

  for (;;)
  {
    if (buckets[1].empty())
    {
      break;
    }

    output.push_back(buckets[1].front());
    buckets[1].pop();
  }

  cout << "\nFINAL\n---------\n";

  print_vec(output);
}

/* implementar ordenação por raiz, utilizando apenas dois buckets 

int u[]:vetor de entrada
int n: comprimento de u
int d: numero maximo de digitos
observação: as entradas sao formadas por numeros inteiros positivos  


*/
