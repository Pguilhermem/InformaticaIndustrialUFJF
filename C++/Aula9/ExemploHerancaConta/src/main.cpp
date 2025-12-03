#include <iostream>
#include "conta.h"
#include "contacorrente.h"
#include "contapoupanca.h"

using namespace std;

int main()
{
    Conta c1(1234,1,"Joao",200);//Cria o objeto c1 da classe Conta
    ContaCorrente cc(5687,2,"Manoel",500,8564225635147485,0);//Cria o objeto cc da Classe ContaCorrente,que possui todos os metodos e atributos da classe Conta
    ContaPoupanca cp(8523,3,"Maria",750,0.01);//Cria o objeto cc da Classe ContaPoupanca,que possui todos os metodos e atributos da classe Conta

    c1.saque(1234,50);
    c1.exibeDados(1234);
    cout << endl;
    cc.deposito(200);
    cc.insereGastoCartao(35);
    cc.exibeDados(5687);
    cout << endl;
    cp.exibeDados(8523);
    cout << "Saldo estimado da conta de " << cp.titular << " em 12 meses R$ "<< cp.simulaRendimentos(8523,12)<<endl;

    return 0;
}

