#include "conta.h"
#include <iostream>

Conta::Conta()
{
    this->numero = 0;
    this->senha = 1111;
    this->titular = "Nenhum";
    this->saldo = 0;
}

Conta::Conta(int senha, int numero, std::string titular, std::string tipo, double saldo)
{
    this->setSenha(senha);
    this->numero = numero;
    this->titular = titular;
    this->tipo = tipo;
    
    if(this->setSaldo(saldo) == OP_INVALIDA){
        this->saldo = 0;
    }
     
}

Conta::~Conta()
{
}

void Conta::exibeDados()
{
    std::cout<< "Titular: "<<this->titular<<std::endl;
    std::cout<< "Numero: "<<this->numero<<std::endl;
    std::cout<< "Tipo: "<<this->tipo<<std::endl;
}

int Conta::getSaldo(int senha, double &saldo)
{
    if(senha==this->senha)
    {
        saldo = this->saldo;
        return OP_SUCEDIDA;
    }
    else
    {
        return OP_CANCELADA;
    }    

}

int Conta::setSaldo(double valor)
{
    if(valor>0){
        this->saldo = valor;
        return OP_SUCEDIDA;
    }
    else{
        return OP_INVALIDA;
    }
}

void Conta::setSenha(int novaSenha)
{
    this->senha = novaSenha;
}

int Conta::deposito(double valor)
{
    if(valor>0)
    {
        this->saldo+=valor;
        return OP_SUCEDIDA;
    }
    else
    {
        return OP_INVALIDA;
    }
    
}

int Conta::saque(int senha, double valor)
{
    if(senha==this->senha)
    {
        if(this->saldo>valor)
        {
            this->saldo-=valor;
            return OP_SUCEDIDA;
        }
        else
        {
            return OP_INVALIDA;
        }    
    }
    else
    {
        return OP_CANCELADA;
    }
    
}

bool Conta::validaSenha(int senha)
{
    return (this->senha == senha);   
}


