#ifndef CONTA_CORRENTE_H
#define CONTA_CORRENTE_H
#include "conta.h"

class ContaCorrente : public Conta
{
private:
    long long numCartaoCredito;
    double totalFatura;
public:
    ContaCorrente();
    ContaCorrente(int senha, int numero, std::string titular, double saldo, long long numCartaoCredito, double totalFatura);
    ~ContaCorrente();    
    bool exibeDados(int senha);
    bool insereGastoCartao(double valor);
    bool estornoCartao(double valor);
};

#endif