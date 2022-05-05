#include <iostream>

using namespace std;

int main()
{
	int var = 10;
	int *pvar;
	pvar = &var;


	cout<<"Acessando o valor de var diretamente: "<<var<<endl;
	*pvar = 30;
	cout<<"Acessando o valor de var atraves de pvar: "<<*pvar<<endl;
	cout<<"Endereco de memoria de var: "<<pvar<<endl;


	int num1=10, num2=20, num3=30;
	int *pnum[3] = {&num1, &num2, &num3};
	
	cout << "Valor de num1: " << *pnum[0]<<endl;
	cout << "Valor de num2: " << *pnum[1]<<endl;
	cout << "Valor de num3: " << *pnum[2]<<endl;

	int vet[] = {1,2,3,4,5};
	int* pvet = vet;
	
	*vet += 1;
	cout << "Valor de vet[0] apos a operacao: " << vet[0] <<endl;
	*(vet+1) *=8;
	cout << "Valor de vet[1] apos a operacao: " << vet[1] <<endl;
	pvet +=8;
	*pvet /= 2;
	cout << "Valor de vet[3] apos a operacao: " << vet[3] <<endl;

	return 0;
}