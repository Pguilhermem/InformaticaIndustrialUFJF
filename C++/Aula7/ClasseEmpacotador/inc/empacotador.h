#ifndef EMPACOTADOR_H
#define EMPACOTADOR_H

class Empacotador
{
private:
    int numEmpacotados;
    int id;
    static int totalEmpacotados;
public:
    Empacotador(int);
    void empacotar(int);
    int getNumEmpacotados();
    int getTotalEmpacotados();
    void imprimeNumEmpacotados();
    static void imprimeTotalEmpacotados();
};


#endif