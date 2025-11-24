#include "contapoupanca.h"
#include "math.h"
#include <iostream>

ContaPoupanca::ContaPoupanca() : Conta::Conta()//O construtor de ContaPoupanca chama o construtor da classe Conta
{
    this->taxa = 0;
}

ContaPoupanca::ContaPoupanca(int senha, int numero, std::string titular, double saldo, float taxa) : 
Conta::Conta(senha,numero,titular,saldo)//O construtor de ContaPoupanca chama o construtor da classe Conta
{
    this->taxa = taxa;
}

ContaPoupanca::~ContaPoupanca()
{
}

double ContaPoupanca::simulaRendimentos(int senha, int numMeses)//Metodo que simula os rendimentos da Conta em alguns meses
{
    double saldo;
    int retorno = this->getSaldo(senha,saldo);
    
    if(retorno == OP_SUCEDIDA)
        return saldo*pow(1+taxa,numMeses);
    else
        return -1;
}

bool ContaPoupanca::exibeDados(int senha) //Metodo que exibe no terminal informações sobre a conta
{
    if(Conta::exibeDados(senha))
    {
        std::cout<< "Taxa: "<<this->taxa<<std::endl;
        return true;
    }
    return false;
}
