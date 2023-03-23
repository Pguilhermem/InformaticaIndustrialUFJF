#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	int var = 10;
	int *pvar; //Criação do ponteiro de inteiros
	pvar = &var;//O ponteiro passa a apontar para a variavel var
	int k =0;

	cout<<"Acessando o valor de var diretamente: "<<var<<endl;//Acessa o valor da variavel pela propria variavel
	*pvar = 30; //Muda o valor da variavel que o ponteiro está apontando para 30
	cout<<"Acessando o valor de var atraves de pvar: "<<*pvar<<endl; //Acessa o valor da variavel atravez do ponteiro usando(*pvar)
	cout<<"Endereco de memoria de var: "<<pvar<<endl;//Acessa o valor do endereço de memoria


	int num1=10, num2=20, num3=30;
	int *pnum[3] = {&num1, &num2, &num3};//Cria um vetor de ponteiros que apontam para os endereços de num1;num2;num3
	//Imprime os valores da variaves que o ponteiro aponta
	cout << "Valor de num1: " << *pnum[0]<<endl;
	cout << "Valor de num2: " << *pnum[1]<<endl;
	cout << "Valor de num3: " << *pnum[2]<<endl;

	int vet[] = {1,2,3,4,5}; 
	int* pvet = vet;//Cria um ponteiro que aponta para o vetor, o ponteiro sempre aponta para a primeira posição do vetor
	
	*vet += 1; //O vetor Fica:{2,2,3,4,5}; ele está apontando para a posição 0
	cout << "Valor de vet[0] apos a operacao: " << vet[0] <<endl;
	*(vet+1) *=8; //O vetor Fica:{2,16,3,4,5}; ele está apontando para a posição 0, porém a alteração é feita na posição 1 pois a mudança não foi armazenada no ponteiro
	cout << "Valor de vet[1] apos a operacao: " << vet[1] <<endl;
	pvet +=8;//O vetor Fica:{2,16,3,4,5}; ele está apontando para a posição 8, fora do vetor
	*pvet /= 2;//Nessa linha não é possivel prever oque pode acontecer, já que estamos operando fora da memoria do vetor(invadindo outra memoria)
	cout << "Valor de vet[3] apos a operacao: " << vet[3] <<endl;

	return 0;
}
