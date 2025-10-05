#ifndef CONTA_H
#define CONTA_H
#include <string>

#define OPERACAO_SUCEDIDA 0

#define VALOR_INVALIDO -1
#define SENHA_INVALIDA -10000

class Conta
{
private:
    double saldo;
    int senha;
public:
    Conta();//Construtor
    Conta(int senha, int numero, std::string titular, std::string tipo, double saldo);//Construtor que recebe parametros
    ~Conta();//Destrutor
    int numero;
    std::string titular;
    std::string tipo;
    void exibeDados();
    double getSaldo(int senha);
    int setSaldo(double valor);
    void setSenha(int novaSenha);
    int deposito(double valor);
    int saque(int senha, double valor);

};


#endif
