#include "sensorindustrial.h"
#include "sensorcomajuste.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

SensorComAjuste::SensorComAjuste(string id, string un): SensorIndustrial::SensorIndustrial(id,un)//SensorComAjuste é derivado do SensorIndustrial, recebendo tudo que SensorIndustrial possui
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

void SensorComAjuste::setCoef(vector<double>& coefs)//Define os coeficientes
{
    this->coefs.resize(coefs.size());
    this->coefs = coefs;
    this->ajustarDados();
}


void SensorComAjuste::getCoef(vector<double>& c)//Recebe o coeficiente
{
    c = this->coefs;
}

void SensorComAjuste::lerDados(const vector<Medicao>& dadosNovos)
{
    SensorIndustrial::lerDados(dadosNovos);//Utiliza o metodo lerDados() da Classe SensorIndustrial
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



