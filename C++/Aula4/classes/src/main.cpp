#include <conta.h>

using namespace std;

int main()
{
	Conta c1,c2;//Cria o objeto c1 que pertence a classe conta
	c1.numero = 2345;//Altera o numero do objeto c1
	c1.titular = "Joao";
	c1.exibeDados();//Usa o metodo exibeDados() da classe Conta para o objeto c1
	c2.numero = 4568;//Altera o numero do objeto c1
	c2.titular = "Maria";
	c2.exibeDados();//Usa o metodo exibeDados() da classe Conta para o objeto c1

}
