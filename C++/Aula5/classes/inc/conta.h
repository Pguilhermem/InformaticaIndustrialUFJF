#ifndef CONTA_H
#define CONTA_H

#include <string>

class Conta
{
private:
	double saldo;
	int senha;
public:
	int numero;
	std::string titular;
	void exibeDados();

};

#endif