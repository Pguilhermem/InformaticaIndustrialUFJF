#ifndef EMPACOTADOR_H
#define EMPACOTADOR_H

class Empacotador
{
private:
    int numEmpacotados;
    int id;
    static int totalEmpacotados;
public:
    Empacotador(int);//Construtor da classe Empacotador
    void empacotar(int);
    int getNumEmpacotados();
    static int getTotalEmpacotados();
    void imprimeNumEmpacotados();
    static void imprimeTotalEmpacotados();
};


#endif
