#include <iostream>
#include "medicao.h"
#include "sensorindustrial.h"
#include "sensorcomajuste.h"
#include <string>
#include <vector>

using namespace std;

void foo(vector<SensorIndustrial*> sensores)
{
    for(int i=0;i<sensores.size();++i)
    {
        sensores[i]->imprimeDados();
    }
}

int main()
{
    vector<Medicao> meds= {{"10:00:00",10},{"10:00:01",11},{"10:00:02",12},{"10:00:03",13},{"10:00:04",14},
    {"10:00:05",15},{"10:00:06",16},{"10:00:07",17},{"10:00:08",18},{"10:00:09",19}};
    

    SensorIndustrial si("S01V","L/s");
    si.lerDados(meds);
    SensorComAjuste sa("S02AJ","L/S");
    sa.lerDados(meds);
    vector <double> coefs({0.5,1.2});
    sa.setCoef(coefs);

    vector<SensorIndustrial*> sensores;
    sensores.push_back(&si);
    sensores.push_back(&sa);
    foo(sensores);
   

    return 0;
}