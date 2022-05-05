#include <iostream>
#include "pessoa.h"
#include "mylib.h"

using namespace std;


int main()
{
    //Declaração
    Pessoa joao = {"Joao", 20, 1.82, 80.5}, jose = {"Jose", 25, 1.75,70.3}, maria = {"Maria", 18, 1.68,63.5};

    //Acesso aos campos
    joao.peso = 82;
    
    //Ponteiros para estruturas
    Pessoa* pjoao = & joao;

    cout << pjoao->nome<<endl;

    //Passagem de estrutras para funções
    imprimeDados(joao);

    //Vetores de estruturas
    Pessoa amigos[] = {joao,jose,maria};

    for(int i=0;i<3;++i)
    {
        imprimeDados(amigos[i]);
    }

    //Vetores de ponteiros para estruturas
    Pessoa* pamigos[] = {&joao,&jose,&maria};

    for(int i=0;i<3;++i)
    {
        imprimeDados(*pamigos[i]);
    }




    return 0;
}