#include <iostream>
#include "funcs.h"
using namespace std;


int main()
{
	int var = 10;

	//Passagem por valor
	cout<<"Valor de var: "<<var<<endl;	
	passagemValor(var);
	cout<<"Valor de var: "<<var<<endl;
	
	//Passagem por ponteiro
	cout << "Valor de var: " << var << endl;
	passagemPonteiro(&var);
	cout << "Valor de var: " << var << endl;

	//Passagem por referência
	cout << "Valor de var: " << var << endl;
	passagemReferencia(var);
	cout << "Valor de var: " << var << endl;
}
