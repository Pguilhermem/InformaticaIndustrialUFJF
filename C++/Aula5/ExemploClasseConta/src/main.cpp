#include <iostream>
#include "conta.h"

using namespace std;

void foo(Conta* vet[], int tam)
{
    for( int i = 0; i < tam; i++)
    {
        vet[i]->exibeDados();
    }
    
}

int main()
{

	Conta contas[4]={{1234,01,"Jose","Corrente",300},{4567,02,"Joao","Poupanca",800},{7890,03,"Maria","Corrente",1000}, {8956,04,"Madalena","Poupanca",2000}};

    Conta cc[2] = {contas[0],contas[2]};
    Conta cp[2] = {contas[1],contas[3]};

    cout<<"Tamanho cc: "<<sizeof(cc)<<" - Tamanho cp: "<<sizeof(cp)<<endl;

    Conta* cc_ponteiros[2] = {&contas[0],&contas[2]};
    Conta* cp_ponteiros[2] = {&contas[1],&contas[3]};

     cout<<"Tamanho cc_ponteiros: "<<sizeof(cc_ponteiros)<<" - Tamanho cp_ponteiros: "<<sizeof(cp_ponteiros)<<endl;

      cout<<"Exibindo informacoes das contas-correntes através de um vetor de objetos"<<endl;

     for(int i= 0;i<sizeof(cc)/sizeof(cc[0]);i++)
     {
         cc[i].exibeDados();
     }

      cout<<"Exibindo informacoes das contas-correntes através de um vetor de ponteiros"<<endl;
      foo(cc_ponteiros,2);
      
    //  for(int i= 0;i<sizeof(cc_ponteiros)/sizeof(cc_ponteiros[0]);i++)
    //  {
    //      cc_ponteiros[i]->exibeDados();
    //  }


    return 0;
}

