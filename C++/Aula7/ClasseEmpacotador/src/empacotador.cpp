#include "empacotador.h"
#include <iostream>

using namespace std;

int Empacotador::totalEmpacotados = 0 ;

Empacotador::Empacotador(int id): id(id),numEmpacotados(0)
{
}

void Empacotador::empacotar(int numPacotes)
{
    this->numEmpacotados+=numPacotes;
    Empacotador::totalEmpacotados += numPacotes;
}

int Empacotador::getNumEmpacotados()
{
    return this->numEmpacotados;
}

int Empacotador::getTotalEmpacotados()
{
    return Empacotador::totalEmpacotados;
}

void Empacotador::imprimeNumEmpacotados()
{
    cout<<"Numero de pacotes empacotados pelo empacotador "<<this->id<<" : "<<this->getNumEmpacotados()<<endl;
}

void Empacotador::imprimeTotalEmpacotados()
{
    static int numchamadas=0;
    cout<<"Numero total de pacotes empacotados :"<<Empacotador::totalEmpacotados<<endl;
    cout<<"Numero de vezes que o metodo foi invocado : "<<++numchamadas<<endl;
}