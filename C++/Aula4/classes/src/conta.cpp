#include "conta.h"
#include <iostream>
using namespace std;

void Conta::exibeDados(int numero)
{
	cout << "Titular: " << this->titular << endl;
	cout << "Numero: " << this->numero << endl;
}
