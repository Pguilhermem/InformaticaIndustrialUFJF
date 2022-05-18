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
    void lerDados(const vector<Medicao>& dadosNovos);

    //funções get
    string getId();
    string getUnidade();
    int getNumMed();
    bool getDado(const string&, Medicao&);
    void imprimeDados();
};

#endif
