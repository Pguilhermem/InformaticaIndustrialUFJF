#include "empacotador.h"
#include <iostream>

using namespace std;

int Empacotador::totalEmpacotados = 0 ;//Essa variavel é compartilhada com todas as classe empacotadores

Empacotador::Empacotador(int id): id(id),numEmpacotados(0)//o atributo id recebe id, e o numEmpacotados recebe 0
{
}

void Empacotador::empacotar(int numPacotes)//Incrementa a as variaveis total numEmpacotados e totalEmpacotados
{
    this->numEmpacotados+=numPacotes;
    Empacotador::totalEmpacotados += numPacotes;
}

int Empacotador::getNumEmpacotados()//Retorna o numero de pacotes empacotados por esse objeto empacotador
{
    return this->numEmpacotados;
}

int Empacotador::getTotalEmpacotados()//Retorna o total de empacotados
{
    return Empacotador::totalEmpacotados;
}

void Empacotador::imprimeNumEmpacotados()//Imprime o numero de pacotes empacotados por esse empacotador
{
    cout<<"Numero de pacotes empacotados pelo empacotador "<<this->id<<" : "<<this->getNumEmpacotados()<<endl;
}

void Empacotador::imprimeTotalEmpacotados()//Imprime o total que foi empacotado e quantas vezes ouve a execução do metodo
{
    static int numchamadas=0;
    cout<<"Numero total de pacotes empacotados :"<<Empacotador::totalEmpacotados<<endl;
    cout<<"Numero de vezes que o metodo foi invocado : "<<++numchamadas<<endl;
}
