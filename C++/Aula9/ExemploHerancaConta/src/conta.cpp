#include "conta.h"
#include <iostream>

Conta::Conta()
{
    this->numero = 0;
    this->senha = 1111;
    this->titular = "Nenhum";
    this->saldo = 0;
}

Conta::Conta(int senha, int numero, std::string titular, double saldo)
{
    this->setSenha(senha);
    this->numero = numero;
    this->titular = titular;
    
    if(this->setSaldo(saldo) == OP_INVALIDA){
        this->saldo = 0;
    }
     
}

Conta::~Conta()
{
}

int Conta::exibeDados(int senha)
{
    if(this->validaSenha(senha))
    {
        std::cout<< "Titular: "<<this->titular<<std::endl;
        std::cout<< "Numero: "<<this->numero<<std::endl;
        std::cout<< "Saldo: "<<this->saldo<<std::endl;
        return OP_SUCEDIDA;
    }
    return OP_CANCELADA;

}

int Conta::getSaldo(int senha, double &saldo)
{
    if(this->validaSenha(senha))
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
    if(this->validaSenha(senha))
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


