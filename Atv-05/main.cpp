#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <cassert>
#include "ATIVIDADE05.hpp"

#define NUMERO_DE_TESTES 6

using std::cout, std::endl;
using std::string, std::stack, std::map, std::vector;

void compare(float&, float&, int&);

int main()
{ 
    string x = "(x+beta)/alfa*y+x/y-1.5^2.0";
    int ok = 0;
    cout << "TESTE 1 =>" << x << "\n-------------" << endl;
    map<string, float> map;
    map.insert(std::pair<string, float>("x", 30.0));
    map.insert(std::pair<string, float>("y", 2.0));
    map.insert(std::pair<string, float>("alfa", 12.5));
    map.insert(std::pair<string, float>("beta", 15.0));
    float cmp = (map["x"] + map["beta"]) / map["alfa"] * map["y"] + map["x"] / map["y"] - pow(1.5, 2);
    float retval = xEval(x, map);
    compare(cmp, retval, ok);
    
    map.clear();



    x = "(x+beta)/alfa*y+x/y-1.5^2.2+x";
    cout << "TESTE 2 =>" << x << "\n-------------" << endl;
    map.insert(std::pair<string, float>("x", 10.0));
    map.insert(std::pair<string, float>("y", 2.15));
    map.insert(std::pair<string, float>("alfa", 12.51));
    map.insert(std::pair<string, float>("beta", 11.0));
    cmp = (map["x"] + map["beta"]) / map["alfa"] * map["y"] + map["x"] / map["y"] - pow(1.5, 2.2) + map["x"];
    retval = xEval(x, map);
    compare(cmp, retval, ok);
    
    map.clear();



    x = "x+x+x+3.0-1";
    cout << "TESTE 3 =>" << x << "\n-------------" << endl;
    map.insert(std::pair<string, float>("x", 2.0));
    map.insert(std::pair<string, float>("y", 0.5));
    map.insert(std::pair<string, float>("alfa", 12.0));
    map.insert(std::pair<string, float>("beta", 11.0));
    cmp = map["x"] * 3 + 3 - 1;
    retval = xEval(x, map);
    compare(cmp, retval, ok);
    
    map.clear();



    x = "x + y + alfa -beta+     3.0-1";
    cout << "TESTE 4 =>" << x << "\n-------------" << endl;
    map.insert(std::pair<string, float>("x", 2.0));
    map.insert(std::pair<string, float>("y", 0.5));
    map.insert(std::pair<string, float>("alfa", 12.0));
    map.insert(std::pair<string, float>("beta", 11.0));
    cmp = map["x"] + map["y"] + map["alfa"] - map["beta"] + 3 - 1;
    retval = xEval(x, map);
    compare(cmp, retval, ok);
    
    map.clear();



    x = "8f343fj38+gama0x";
    cout << "TESTE 5 =>" << x << "\n-------------" << endl;
    map.insert(std::pair<string, float>("x", 2.0));
    map.insert(std::pair<string, float>("y", 0.5));
    map.insert(std::pair<string, float>("alfa", 12.0));
    map.insert(std::pair<string, float>("beta", 11.0));
    cmp = 0;
    retval = xEval(x, map);

    compare(cmp, retval, ok);
    
    map.clear();



    x = "1.0 + 3.2 - 1 * 3.33 + (1)";
    cout << "TESTE 6 =>" << x << "\n-------------" << endl;

    map.insert(std::pair<string, float>("x", 2.0));
    map.insert(std::pair<string, float>("y", 0.5));
    map.insert(std::pair<string, float>("alfa", 12.0));
    map.insert(std::pair<string, float>("beta", 11.0));

    cmp = 1 + 3.2 - 1 * 3.33 + (1);
    retval = xEval(x, map);

    compare(cmp, retval, ok);

    map.clear();    


    if (ok == NUMERO_DE_TESTES) cout << "Tudo certo, chefe!" << endl;

    return 0;
}   

void compare(float& cmp, float& retval, int& ok)
{
    cout << "cmp = " << cmp << endl;
    cout << "retval = " << retval << endl;

    if (!(to_string(cmp) == to_string(retval)))
    {
        cout << "\nTem um erro aqui, chefia!\n" << endl;
        cout << "-------------" << endl;

        return;
    }

    cout << "-------------" << endl;
    ok++;
}