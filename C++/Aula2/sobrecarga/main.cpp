#include <iostream>

using namespace std;

int soma(int a, int b)
{
	return a + b;
}

int soma(int a, int b, int c)
{
	return a + b + c;
}

float soma (int a, float b)
{
	return a + b;
}


int main()
{
	
	int a=2, b=5, c=10;
	float d = 4.52;

	cout<<"Resultado: "<< soma(a,b) << endl;

	cout<<"Resultado: "<< soma(a,b,c) << endl;

	cout<<"Resultado: "<< soma(a,d) << endl;

	system("pause");

	return 0;
}