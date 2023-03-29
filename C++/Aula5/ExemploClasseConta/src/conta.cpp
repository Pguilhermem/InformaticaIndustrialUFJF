#include "conta.h"
#include <iostream>

Conta::Conta() //Construtor da Classe conta, quando nenhum parametro é declarado(Padrão)
{
    this->numero = 0;
    this->senha = 1111;
    this->titular = "Nenhum";
    this->saldo = 0;
    std::cout << "Construtor padrao invocado"<<std::endl;
}

Conta::Conta(int senha, int numero, std::string titular, std::string tipo, double saldo) //Construtor da classe conta que recebe parametros(Personalizado)
{
    this->senha = senha;
    this->numero = numero;
    this->titular = titular;
    this->tipo = tipo;
    if(saldo>0) //Impede que a conta seja iniciada com saldo negativo
    {
        this->saldo = saldo;
    }
    else //Caso ela seja iniciada com saldo negativo o saldo é iniciado como 0
    {
        std::cout<<"Saldo inicial invalido"<<std::endl;
        this->saldo=0;
    }    
}

Conta::~Conta() //Destrutor da Classe conta
{
    std::cout <<"Destrutor da conta "<< this->numero<<" foi invocado"<<std::endl;
}

void Conta::exibeDados() //Metodo que exibe no terminal informações sobre a conta
{
    std::cout<< "Titular: "<<this->titular<<std::endl;
    std::cout<< "Numero: "<<this->numero<<std::endl;
    std::cout<< "Tipo: "<<this->tipo<<std::endl;
}

double Conta::getSaldo(int senha) //Metodo que mediante a inserção de uma senha, retorna o valor do saldo
{
    if(senha==this->senha)
    {
        return this->saldo;
    }
    else
    {
        std::cout<<"Senha inválida"<<std::endl;
        return -1000000;
    }    

}

void Conta::setSaldo(double valor)//Metodo que define um saldo, atravez desse metodo é possivel ter um saldo negativo
{
    if(saldo>0)
        this->saldo = valor;
    else
        std::cout<<"Valor inválido"<<std::endl;
}

void Conta::setSenha(int novaSenha)//Metodo que define o atributo senha
{
    this->senha = novaSenha;
}

void Conta::deposito(double valor)//Metodo que soma um valor no atributo saldo, não necessita de senha
{
    if(valor>0)// Se o valor do deposito for maior que 0 o metodo funciona normalmente
    {
        this->saldo+=valor;
    }
    else // Se o valor do deposito for menor que 0 o metodo imprime uma mensagem de erro no terminal
    {
        std::cout<<"Valor invalido"<<std::endl;
    }
    
}

void Conta::saque(int senha, double valor)// Metodo que retira um valor do atributo saldo, necessita de senha
{
    if(senha==this->senha) //Verifica se a senha digitada é igual a senha do atributo senha dessa classe
    {
        if(this->saldo>valor) //Verifica se o valor que está sendo subitraido é maior que o saldo
        {
            this->saldo-=valor;
            std::cout<<"Saque de R$"<<valor<<" realizado com sucesso."<<std::endl;
        }
        else 
        {
            std::cout<<"Saldo insuficiente"<<std::endl;
        }
        
    }
    else
    {
        std::cout<<"Senha invalida"<<std::endl;
    }
    
}

