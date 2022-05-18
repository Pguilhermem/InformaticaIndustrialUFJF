#include <iostream>
#include <iomanip>
#include "mylib.h"
using namespace std;

#define TAMVET 5 //define que a palavra "TAMVET" é equivalente a 5

int main()
{
	
	int vetor[TAMVET] = { 1, 5, 3, 4, 2 }; //inicializa as posições do vetor
	

	cout << "Vetor antes da operacao:"<<endl;
	cout << "Elemento" << setw(13) << "Valor" << endl;//setw() é a função que determina o proximo espaçamento
	for (int j = 0; j < TAMVET; j++)
	{
		cout << setw(7) << j << setw(13) << vetor[j] << endl; // exibe na tela o elemento seguido pelo valor dele no vetor
	}

	elevaQuadradoVetor(vetor, TAMVET); //invoca a função elevaQuadradoVetor
	cout << "Vetor depois da operacao:"<<endl;
	cout << "Elemento" << setw(13) << "Valor" << endl; 
	for (int j = 0; j < TAMVET; j++)
	{
		cout << setw(7) << j << setw(13) << vetor[j] << endl;
	}

	elevaQuadradoElemento(vetor[1]);
	cout << "Valor do elemento apos a funcao elevaQuadradoElemento: " << vetor[1] << endl;

}

