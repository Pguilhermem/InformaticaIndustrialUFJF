#ifndef CONTA_H
#define CONTA_H
#include <string>


// Define as constantes usadas para tratamento de resultado de operação
#define OP_SUCEDIDA 1
#define OP_CANCELADA 2
#define OP_INVALIDA 3


class Conta
{
private:
    double saldo;
    int senha;
public:
    Conta();
    Conta(int senha, int numero, std::string titular, double saldo);
    ~Conta();
    int numero;
    std::string titular;
    int exibeDados(int senha);
    int getSaldo(int senha, double &saldo);
    int setSaldo(double valor);
    void setSenha(int novaSenha);
    int deposito(double valor);
    int saque(int senha, double valor);
    bool validaSenha(int senha);

};


#endif