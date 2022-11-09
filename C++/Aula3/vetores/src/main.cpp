#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;
#define TAM 5

int main()
{
	//Parte 1: Inicialização explícita
	int vetor1[TAM];
	for (int i = 0; i < TAM ;i++)
	{
		vetor1[i] = i;
	}
	

	// Parte 2: Utilizando inicializadores
	//a) Inicializando todo o vetor
	int vetor2[] = {1,2,3,4,5};
	//b) Inicializando o primeiro elemento e os demais iguais a zero
	int vetor3[5] = {5,3};

	//Parte 3: Utilizando memset (Avisar que o valor a ser preenchido é do tipo char)
	char vetor4[5];
	memset(vetor4, '$', sizeof(vetor4));

	 cout << "Elemento" << setw(13) << "Valor" << endl;

	for (int j = 0; j < 5; j++)
	{
		cout << setw(7) << j << setw(13) << vetor4[j] << endl;
	}

	// Parte 4: Vetores multidimensionais 
	int vetor5[3][2] = { {1,2}, {3,4}, {5,6} };

    for (int i = 0; i < 3;i++)
	{
		for (int j = 0; j < 2;j++)
		{
			cout << vetor5[i][j] << ' ';
		}

		cout << endl;
	}
	   	  
}