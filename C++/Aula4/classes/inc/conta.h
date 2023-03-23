#ifndef CONTA_H
#define CONTA_H

#include <string>

class Conta
{
private: //Atributos privados só podem ser acessados pela classe e seus metodos
	double saldo;//Atributo privado
	int senha;
public://Podem ser acessados direto no main
	int numero;//Atributo publico
	std::string titular;
	void exibeDados();//Metodo publico

};

#endif
