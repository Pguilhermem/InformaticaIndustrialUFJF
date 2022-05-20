#ifndef CONTA_POUPANCA_H
#define CONTA_POUPANCA_H
#include "conta.h"

class ContaPoupanca : public Conta
{
private:
    float taxa;
public:
    ContaPoupanca();
    ContaPoupanca(int senha, int numero, std::string titular, double saldo, float taxa = 0);
    ~ContaPoupanca();
    double simulaRendimentos(int senha, int numMeses);
    bool exibeDados(int senha);
};

#endif