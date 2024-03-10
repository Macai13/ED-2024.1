#include <cmath>

class ponto {
    float x; // abcissa
    float y; // ordenada
public:
    ponto (int _x, int _y)  // constrói ponto
    {  
        x = _x;
        y = _y;
           // cria  ponto dadas coordenadas
    }
    ponto () {
        x = 0;
        y = 0;
         // alternativa de criação de ponto
         // para construir um ponto (0,0) 
     }
     float dist (const ponto& p) {
            // determina a distância do ponto
            // à este passaso como argumeto.
            return sqrt((p.x - x)*(p.x - x) + (p.y - y)*(p.y - y));
        }
        float& X() {
               // retorna referência 
               // da abcissa 
               return x;
        }
        float Y() {
             // Retorna referência para
             // a ordenada
             return y;
         }
         

};

float reta(ponto& p, ponto& q);
float minDist(const ponto& p, ponto kust[], int n);