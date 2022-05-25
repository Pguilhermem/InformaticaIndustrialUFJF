#ifndef CONTA_CORRENTE_H
#define CONTA_CORRENTE_H
#include "conta.h"

class ContaCorrente : public Conta //ContaCorrente deriva de Conta, E todos os atributos publicos da Conta continuam publicos para Contacorrente assim como os privados e protegidos
{
private://Todos os atributos privados de Conta existem implicitamente aqui tambem, mas o contrario não e verdade
    long long numCartaoCredito;
    double totalFatura;
public://Todos os atributos publicos de Conta existem implicitamente aqui tambem, mas o contrario não e verdade
    ContaCorrente();//ContaCorrente possui um construtor diferente de Conta
    ContaCorrente(int senha, int numero, std::string titular, double saldo, long long numCartaoCredito, double totalFatura);
    ~ContaCorrente();    
    bool exibeDados(int senha);
    bool insereGastoCartao(double valor);
    bool estornoCartao(double valor);
};

#endif
