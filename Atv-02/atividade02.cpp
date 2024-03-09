/*
Seja uma classe que representa um ponto no plano dada por,.  
*/

class ponto {
    float x; // abcissa
    float y; // ordenada
public:
    ponto (int _x, int _y)  // constrói ponto
    {  
           // cria  ponto dadas coordenadas
    }
    ponto () {
         // alternativa de criação de ponto
         // para construir um ponto (0,0) 
     }
     float dist (const ponto& p) {
            // determina a distância do ponto
            // à este passaso como argumeto.
            return 0;
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

/* Implemente as funções a seguir usando a classe anterior */

float reta(ponto& p, ponto& q) {
    // retorna coeficiente angular da reta 
    // que passa por p e 
    return 0;
}

float minDist(const ponto& p, ponto kust[], int n) {
   // retorna a menor distância entre p e os // pontos da lista list dada de 
   // comprimento n.  
   return 0;
}