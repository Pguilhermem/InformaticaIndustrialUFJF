#include "contacorrente.h"
#include "math.h"
#include <iostream>

ContaCorrente::ContaCorrente() : Conta::Conta()//O construtor de ContaCorrente chama o construtor da classe Conta
{
    this->numCartaoCredito = 9999999999999999;
    this->totalFatura = 0;
}

ContaCorrente::ContaCorrente(int senha, int numero, std::string titular, double saldo, long long numCartaoCredito, double totalFatura) : 
Conta::Conta(senha,numero,titular,saldo)//O construtor de ContaCorrente chama o construtor da classe Conta
{
    this->numCartaoCredito = numCartaoCredito;
    this->totalFatura = totalFatura;
}

ContaCorrente::~ContaCorrente()//Destrutor
{
}

bool ContaCorrente::exibeDados(int senha) //Metodo que exibe no terminal informações sobre a conta
{
    if(Conta::exibeDados(senha))
    {
        std::cout<< "Numero do Cartao de Credito: "<<this->numCartaoCredito<<std::endl;
        std::cout<< "Total da Fatura: "<<this->totalFatura<<std::endl;
        return true;
    }
    return false;
}

bool ContaCorrente::insereGastoCartao(double valor)//Soma os gastos a fatura, e retorna true caso a operação tenha tido exito
{
    if(valor>0)
    {
        this->totalFatura += valor;
        return true;
    }
    return false;
}
bool ContaCorrente::estornoCartao(double valor)//Subitrai o pagamento a fatura, e retorna true caso a operação tenha tido exito
{
    if(valor>0)
    {
        this->totalFatura -= valor;
        return true;
    }
    return false;
}
