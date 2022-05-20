#include <iostream>
#include "conta.h"
#include "contacorrente.h"
#include "contapoupanca.h"

using namespace std;

int main()
{
    Conta c1(1234,1,"Joao",200);
    ContaCorrente cc(5687,2,"Manoel",500,8564225635147485,0);
    ContaPoupanca cp(8523,3,"Maria",750,0.01);

    c1.saque(1234,50);
    c1.exibeDados(1234);
    cout << endl;
    cc.insereGastoCartao(35);
    cc.exibeDados(5687);
    cout << endl;
    cp.exibeDados(8523);
    cout << "Saldo estimado da conta de " << cp.titular << " em 12 meses R$ "<< cp.simulaRendimentos(8523,12)<<endl;

    return 0;
}

