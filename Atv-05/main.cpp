#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include "ATIVIDADE05.hpp"

using std::cout, std::endl;
using std::string, std::stack, std::map, std::vector;

int main()
{ 
    cout << "TESTE 1 =>\n-------------" << endl;
    string x = "(x+beta)/alfa*y+x/y-1.5^2.0";
    map<string, float> map;
    map.insert(std::pair<string, float>("x", 30.0));
    map.insert(std::pair<string, float>("y", 2.0));
    map.insert(std::pair<string, float>("alfa", 12.5));
    map.insert(std::pair<string, float>("beta", 15.0));
    float cmp = (map["x"] + map["beta"]) / map["alfa"] * map["y"] + map["x"] / map["y"] - pow(1.5, 2);
    float retval = xEval(x, map);
    cout << "cmp = " << cmp << endl;
    cout << "retval = " << retval << endl;
    map.clear();
    cout << "-------------" << endl;



    cout << "TESTE 2 =>\n-------------" << endl;
    x = "(x+beta)/alfa*y+x/y-1.5^2.2+x";
    map.insert(std::pair<string, float>("x", 10.0));
    map.insert(std::pair<string, float>("y", 2.15));
    map.insert(std::pair<string, float>("alfa", 12.51));
    map.insert(std::pair<string, float>("beta", 11.0));
    cmp = (map["x"] + map["beta"]) / map["alfa"] * map["y"] + map["x"] / map["y"] - pow(1.5, 2.2) + map["x"];
    retval = xEval(x, map);
    cout << "cmp = " << cmp << endl;
    cout << "retval = " << retval << endl;
    cout << "-------------" << endl;



    cout << "TESTE 3 =>\n-------------" << endl;
    x = "x+x+x+3.0-1";
    map.insert(std::pair<string, float>("x", 2.0));
    map.insert(std::pair<string, float>("y", 0.5));
    map.insert(std::pair<string, float>("alfa", 12.0));
    map.insert(std::pair<string, float>("beta", 11.0));
    cmp = map["x"] * 3 + 3 - 1;
    retval = xEval(x, map);
    cout << "cmp = " << cmp << endl;
    cout << "retval = " << retval << endl;
    cout << "-------------" << endl;



    cout << "TESTE 4 =>\n-------------" << endl;
    x = "x + y + alfa -beta+     3.0-1";
    map.insert(std::pair<string, float>("x", 2.0));
    map.insert(std::pair<string, float>("y", 0.5));
    map.insert(std::pair<string, float>("alfa", 12.0));
    map.insert(std::pair<string, float>("beta", 11.0));
    cmp = map["x"] + map["y"] + map["alfa"] - map["beta"] + 3 - 1;
    retval = xEval(x, map);
    cout << "cmp = " << cmp << endl;
    cout << "retval = " << retval << endl;
    cout << "-------------" << endl;

    cout << "TESTE 5 =>\n-------------" << endl;
    x = "8f343fj38+gama0x";
    map.insert(std::pair<string, float>("x", 2.0));
    map.insert(std::pair<string, float>("y", 0.5));
    map.insert(std::pair<string, float>("alfa", 12.0));
    map.insert(std::pair<string, float>("beta", 11.0));
    cmp = 0;
    retval = xEval(x, map);
    cout << "cmp = " << cmp << endl;
    cout << "retval = " << retval << endl;
    cout << "-------------" << endl;

    return 0;
}   
