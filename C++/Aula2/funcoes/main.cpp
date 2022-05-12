// Função expnencial

#include <iostream> //inclui biblioteca de entrada/saída de dados

using namespace std;//inclusão do espaço de nomes std

float potencia(float b, int exp) //Função potencia que recebe a base e o exponencial para a operação
{
	float r = b;
	for(int i=1;i<exp;i++) //o codigo vai multiplicar a base por ela mesma um numero de vezes igual ao exp
	{
		r *=b;
	}
	return r; //retorna o valor da operação potencia
}

int glob = 3;

int main()
{
	float base, resultado;
	int e;
	
	cout << "Digite a base: ";
	cin >> base; 			//recebe o valor da base
	cout << "Digite o expoente (inteiro > 0):";
	cin >> e; 			// recebe o valor do expoente
	resultado = potencia(base, e); // resultado recebe o valor retornao pela função
	cout << "Resultado da operacao: "<<resultado<<endl;

	return 0;
}
