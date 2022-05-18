#ifndef SENSOR_COM_AJUSTE_H
#define SENSOR_COM_AJUSTE_H

#include <string>
#include "sensorindustrial.h"
#include "medicao.h"

class SensorComAjuste: public SensorIndustrial
{
private:
    vector<double> coefs;
    vector<Medicao> dadosAjustados;
    void ajustarDados();
public:
    SensorComAjuste(std::string, std::string);
    ~SensorComAjuste();

    void setCoef(vector<double>&);
    void getCoef(vector<double>&);

    void lerDados(const vector<Medicao>&);
    void imprimeDados();

    
};


#endif