#include <iostream>

using namespace std;

float potencia(float b, int exp)
{
	float r = b;
	for(int i=1;i<exp;i++)
	{
		r *=b;
	}
	return r;
}

int main()
{
	float base, resultado;
	int e;
	
	cout << "Digite a base: ";
	cin >> base;
	cout << "Digite o expoente (inteiro > 0):";
	cin >> e;
	resultado = potencia(base, e);
	cout << "Resultado da operacao: "<<resultado<<endl;

	return 0;
}