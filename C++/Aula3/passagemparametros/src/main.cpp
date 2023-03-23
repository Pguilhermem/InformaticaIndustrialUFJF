#include <iostream>
#include "funcs.h"
using namespace std;


int main()
{
	int var = 10;

	//Passagem por valor
	cout<<"Valor de var: "<<var<<endl;//Imprime 10	
	passagemValor(var);//Não altera a variavel
	cout<<"Valor de var: "<<var<<endl; //Imprime 10
	
	//Passagem por ponteiro
	cout << "Valor de var: " << var << endl;//Imprime 10
	passagemPonteiro(&var);//Altera a variavel
	cout << "Valor de var: " << var << endl;//Imprime 11

	//Passagem por referência
	cout << "Valor de var: " << var << endl;//Imprime 10
	passagemReferencia(var);//Altera a variavel
	cout << "Valor de var: " << var << endl;//Imprime 11
}
