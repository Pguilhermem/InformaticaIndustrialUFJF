#include "sensorindustrial.h"
#include "sensorcomajuste.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

SensorComAjuste::SensorComAjuste(string id, string un): SensorIndustrial::SensorIndustrial(id,un)
{
    this->coefs = vector<double>({0,1.0});
    this->dadosAjustados = vector<Medicao>();
}

SensorComAjuste::~SensorComAjuste()
{
    dadosAjustados.clear();
    coefs.clear();
    cout<<"Destrutor classe SensorComAjuste invocado"<<endl;
}

void SensorComAjuste::setCoef(vector<double>& coefs)
{
    this->coefs.resize(coefs.size());
    this->coefs = coefs;
    this->ajustarDados();
}


void SensorComAjuste::getCoef(vector<double>& c)
{
    c = this->coefs;
}

void SensorComAjuste::lerDados(const vector<Medicao>& dadosNovos)//Tem seu proprio ler dados
{
    SensorIndustrial::lerDados(dadosNovos);
    this->ajustarDados();
}

void SensorComAjuste::ajustarDados()
{
    this->dadosAjustados.resize(dados.size());
    if(this->dados.size()!=0)
    {
        for(int i = 0; i<this->dados.size();i++)
        {

            this->dadosAjustados[i].horario = this->dados[i].horario;
            this->dadosAjustados[i].valor = 0;

            for(int coef = 0; coef<this->coefs.size();coef++)
            {
                this->dadosAjustados[i].valor+=this->coefs[coef]*pow(this->dados[i].valor,coef);
            }
        }
    }
}

void SensorComAjuste::imprimeDados()
{
    cout<<"Dados ajustados do sensor "<<this->getId()<<" :"<<endl;
    for(int i=0;i<this->dadosAjustados.size();i++)
    {
        cout<<"Horario: "<<this->dadosAjustados[i].horario<<" h | Valor: "<<this->dadosAjustados[i].valor<<" "<<this->getUnidade()<<endl;
    }
}



