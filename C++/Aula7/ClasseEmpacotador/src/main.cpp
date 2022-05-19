#include <iostream>
#include "empacotador.h"
using namespace std;


void foo() //Chama a função imprimeTotalEmpacotados(), ela não precisa de um objeto
{
    Empacotador::imprimeTotalEmpacotados();
}

int main()
{
    foo();
    
    Empacotador emp1(1), emp2(2);

    emp1.empacotar(10);
    emp2.empacotar(20);
    emp1.empacotar(30);

    emp1.imprimeNumEmpacotados();
    emp2.imprimeNumEmpacotados();

    foo();

    return 0;
}
