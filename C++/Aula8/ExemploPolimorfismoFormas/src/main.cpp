#include <iostream>
#include <string>
#include <vector>
#include "formas.h"

using namespace std;

void foo(vector<FormaBiDimensional*> formas)
{
    for(int i=0;i<formas.size();++i)
    {
        cout <<"Area objeto " << i<<" : " << formas[i]->calculaArea()<<endl;
    }
}

int main()
{

    Circulo c(3);
    Quadrado q(4);
    vector<FormaBiDimensional*> formas;
    formas.push_back(&c);
    formas.push_back(&q);
    foo(formas);

    return 0;
}