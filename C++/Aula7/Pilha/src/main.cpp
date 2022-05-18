#include <iostream>
#include "pilha.hpp"
#include <string>

using namespace std;

template<typename T>
void imprimeVetor(T* p, int tam)
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

    int *pvet = new int[tamVet];

    cout << "--- Vetor Alocado Dinamicamente ---"<<endl;
    for(int i=0;i<tamVet;++i)
    {
        *(pvet+i) = i;
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
    Pilha<int> p1(5);
    Pilha<string> pString(5);

    p1.insere(4);
    p1.insere(10);
    pString.insere("Ola Mundo");
    pString.insere("Hello World");

    int outInt;
    string outStr;


    cout << "--- Primeira Remocao ---"<<endl;
    p1.remove(outInt);
    pString.remove(outStr);

    cout<<"Dado removido da pilha de inteiros: "<<outInt<<endl;
    cout<<"Dado removido da pilha de strings: "<<outStr<<endl;

    cout << "--- Segunda Remocao ---"<<endl;
    p1.remove(outInt);
    pString.remove(outStr);

    cout<<"Dado removido da pilha de inteiros: "<<outInt<<endl;
    cout<<"Dado removido da pilha de strings: "<<outStr<<endl;

    return 0;
}