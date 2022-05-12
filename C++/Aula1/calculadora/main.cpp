//Calculadora

#include <iostream> //inclui biblioteca de entrada/saída de dados

using namespace std;//inclusão do espaço de nomes std

int main()//a função main inicia a execução do programa
{
	float num1,num2; //cria os numeros que serão operados
	char op; // cria a variavel que recebera os operadores

	cout << "Num 1: "; 
	cin >> num1; //recebe o numero 1
	cout << "Num 2: ";
	cin >> num2; // recebe o numero 2
	cout << "op: ";
	cin >> op; // recebe o operador

	switch(op)// verifica o operador escolhido e escolhe o case baseado nele
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
	default:// esse caso acontece caso o Switch não consiga indentifica um case adequado
		cout << "Operacao invalida";
		break;
	}

	system("pause");

	return 0;
}
