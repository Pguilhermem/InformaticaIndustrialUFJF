#ifndef CONTA_POUPANCA_H
#define CONTA_POUPANCA_H
#include "conta.h"

class ContaPoupanca : public Conta//ContaPoupanca deriva de Conta, E todos os atributos publicos da Conta continuam publicos para Contacorrente assim como os privados e protegidos
{
private://Todos os atributos privados de Conta existem implicitamente aqui tambem, mas o contrario não e verdade
    float taxa;
public://Todos os atributos publicos de Conta existem implicitamente aqui tambem, mas o contrario não e verdade
    ContaPoupanca();//ContaPoupanca possui um construtor diferente de Conta
    ContaPoupanca(int senha, int numero, std::string titular, double saldo, float taxa = 0);
    ~ContaPoupanca();
    double simulaRendimentos(int senha, int numMeses);
    bool exibeDados(int senha);
};

#endif
