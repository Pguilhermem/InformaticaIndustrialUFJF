from contas import Conta, ContaPoupanca

#Utilização da classe Conta
c1 = Conta(1,senha=1234,titular="João",saldoi=500)

c1.deposito(300)
c1.saque(1234, 200)
c1.exibeDados(1234)


#Utilização da classe ContaPoupanca
cp = ContaPoupanca(2,"Maria",1234,saldoi=1200)
cp.exibeDados(1234)
cp.simulaRendimento(12)