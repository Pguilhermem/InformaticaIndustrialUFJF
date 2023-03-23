#include "mylib.h"
#include <iostream>

void imprimeDados(Pessoa p)
{
    std::cout << "Nome: "<<p.nome<<" | idade: "<<p.idade<<" anos | altura: "<<p.altura<<" m | peso: "<<p.peso<<" kg\r\n";
}