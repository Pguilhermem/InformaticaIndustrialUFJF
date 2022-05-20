#include "formas.h"

Circulo::Circulo(float r)
{
    if(!this->setraio(r))
    {
        this->raio = 0;
    }
}

double Circulo::calculaArea()
{
    return raio * raio * 3.14;
}

bool Circulo::setraio(float r)
{
    if(r>0)
    {
        this->raio = r;
        return true;
    }
    else
        return false;
}
float Circulo::getraio()
{
    return this->raio;
}

Quadrado::Quadrado(float l) 
{
    if(!this->setlado(l))
    {
        this->lado = 0;
    }
}

bool Quadrado::setlado(float l)
{
    if(l>0)
    {
        this->lado = l;
        return true;
    }
    else
        return false;
}
float Quadrado::getlado()
{
    return this->lado;
}

double Quadrado::calculaArea()
{
    return lado*lado;
}