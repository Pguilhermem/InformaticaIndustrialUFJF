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

    void lerDados(const vector<Medicao>&);//Função alvo de polimorfismo
    void imprimeDados();//Função alvo de polimorfismo,Apesar de Sensor com ajuste possuir um Metodo imprimeDados(), um objeto da classe SensorComAjuste ainda sim
                        //pode acessar esse Metodo da classe "Pai" ao inves de sua propria versão, oque não ocorre com o metodo lerDados(Cada um tem o seu) 

    
};


#endif
