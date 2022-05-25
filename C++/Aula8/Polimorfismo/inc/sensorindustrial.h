#ifndef SENSOR_INDUSTRIAL_H
#define SENSOR_INDUSTRIAL_H

#include <string>
#include "medicao.h"
#include <vector>

using namespace std;

class SensorIndustrial
{
protected:
    string id;
    string unidade;
    vector<Medicao> dados;

public:
    SensorIndustrial(string, string);
    ~SensorIndustrial();

    //funções set
    void setId(const string&);
    void setUnidade(const string&);
    void lerDados(const vector<Medicao>& dadosNovos);//Função alvo de polimorfismo

    //funções get
    string getId();
    string getUnidade();
    int getNumMed();
    bool getDado(const string&, Medicao&);
    virtual void imprimeDados();//Função alvo de polimorfismo,Apesar de Sensor com ajuste possuir um Metodo imprimeDados(), um objeto da classe SensorComAjuste ainda sim
};                              //pode acessar esse Metodo da classe "Pai" ao inves de sua propria versão, oque não ocorre com o metodo lerDados(Cada um tem o seu) 

#endif
