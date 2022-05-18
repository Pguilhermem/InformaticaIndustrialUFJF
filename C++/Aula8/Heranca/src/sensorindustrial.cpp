#include "sensorindustrial.h"
#include <iostream>

using namespace std;

SensorIndustrial::SensorIndustrial(string id, string un) : id(id), unidade(un)
{
    dados = vector<Medicao>();
}

SensorIndustrial::~SensorIndustrial()
{
    dados.clear();
    cout << "Destrutor da classe SensorIndustrial invocado" << endl;
}

//funções set
void SensorIndustrial::setId(const std::string& id)
{
    this->id = id;
}
void SensorIndustrial::setUnidade(const std::string& un)
{
    this->unidade = un;
}
void SensorIndustrial::lerDados(const vector<Medicao>& dadosNovos)
{
    dados.resize(dadosNovos.size());
    dados = dadosNovos;

}

//funções get
std::string SensorIndustrial::getId()
{
    return this->id;
}
std::string SensorIndustrial::getUnidade()
{
    return this->unidade;
}
int SensorIndustrial::getNumMed()
{
    return this->dados.size();
}

bool SensorIndustrial::getDado(const std::string& h, Medicao& med)
{
    for(int i=0;i<this->dados.size();i++)
    {
        if(this->dados[i].horario == h)
        {
            med = this->dados[i];
            return true; 
        }           
    }
    return false;
}

void SensorIndustrial::imprimeDados()
{
    cout<<"Dados do sensor "<<this->getId()<<" :"<<endl;
    for(int i=0;i<this->dados.size();i++)
    {
        cout<<"Horario: "<<this->dados[i].horario<<" h | Valor: "<<this->dados[i].valor<<" "<<this->getUnidade()<<endl;
    }
}