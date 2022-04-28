#include <iostream>
#include <iomanip>
#include "mylib.h"
using namespace std;

#define TAMVET 5 

int main()
{
	
	int vetor[TAMVET] = { 1, 5, 3, 4, 2 };
	

	cout << "Vetor antes da operacao:"<<endl;
	cout << "Elemento" << setw(13) << "Valor" << endl;
	for (int j = 0; j < TAMVET; j++)
	{
		cout << setw(7) << j << setw(13) << vetor[j] << endl;
	}

	elevaQuadradoVetor(vetor, TAMVET);
	cout << "Vetor depois da operacao:"<<endl;
	cout << "Elemento" << setw(13) << "Valor" << endl;
	for (int j = 0; j < TAMVET; j++)
	{
		cout << setw(7) << j << setw(13) << vetor[j] << endl;
	}

	elevaQuadradoElemento(vetor[1]);
	cout << "Valor do elemento apos a funcao elevaQuadradoElemento: " << vetor[1] << endl;

}

