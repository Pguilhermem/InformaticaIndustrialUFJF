#include <iostream>
#include "pilha.hpp"
#include <string>

using namespace std;

template<typename T>
void imprimeVetor(T* p, int tam) //Essa função pode receber qualquer tipo de vetor para imprimir
{
    for(int i=0; i<tam;i++)
    {
        cout<<"Posicao "<<i<<" ->  Valor:"<<*(p+i)<<endl;
    }
}

int main()
{
    //Alocação Dinâmica
    int tamVet;
    cout << "Digite o tamanho do vetor:";
    cin>>tamVet;

    int *pvet = new int[tamVet];//Cria um vetor de inteiros de tamanho tamVet e faz pvet apontar para a primeira posição desse

    cout << "--- Vetor Alocado Dinamicamente ---"<<endl;
    for(int i=0;i<tamVet;++i)
    {
        *(pvet+i) = i; //Atribui o valor 0 para posição 0, 1 para a 1 e assim por diante
        cout << "pvet["<<i<<"] = " << pvet[i]<<endl;
    }    
    delete[] pvet;
    //Exemplo Templates
    cout << "--- Exemplo Templates ---"<<endl;
    int vetInt[] = {1,2,3,4};
    char charVet[] = "Teste";

    imprimeVetor(vetInt, 4);
    imprimeVetor(charVet, 5);


    //Classe Pilha (Alocação Dinâmica + Templates)

    cout << "--- Classe Pilha ---"<<endl;
    Pilha<int> p1(5); //T dentro da classe pilha vai assumir o valor de int para o objeto p1
    Pilha<string> pString(5);//T dentro da classe pilha vai assumir o valor de string para o objeto pString

    p1.insere(4);
    p1.insere(10);
    pString.insere("Ola Mundo");
    pString.insere("Hello World");

    int outInt;
    string outStr;


    cout << "--- Primeira Remocao ---"<<endl;
    p1.remove(outInt);
    pString.remove(outStr);

    cout<<"Dado removido da pilha de inteiros: "<<outInt<<endl; //Removeu o 10
    cout<<"Dado removido da pilha de strings: "<<outStr<<endl;//Removeu o "Hello World"

    cout << "--- Segunda Remocao ---"<<endl;
    p1.remove(outInt);
    pString.remove(outStr);

    cout<<"Dado removido da pilha de inteiros: "<<outInt<<endl; //Removeu o 4
    cout<<"Dado removido da pilha de strings: "<<outStr<<endl;//Removeu o "Ola Mundo"

    return 0;
}
