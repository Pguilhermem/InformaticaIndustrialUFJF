#include <iostream>

using namespace std;

int main()
{
	float num1,num2;
	char op;

	cout << "Num 1: ";
	cin >> num1;
	cout << "Num 2: ";
	cin >> num2;
	cout << "op: ";
	cin >> op;

	switch(op)
	{
	case '+':
		cout << "Resultado = " <<num1+num2<<endl;
		break;
	case '-':
		cout << "Resultado = " <<num1-num2<<endl;
		break;
	case '*':
		cout << "Resultado = " << num1*num2<<endl;
		break;
	case '/':
		cout << "Resultado = " << num1/num2<<endl;
		break;
	default:
		cout << "Operacao invalida";
		break;
	}

	system("pause");

	return 0;
}