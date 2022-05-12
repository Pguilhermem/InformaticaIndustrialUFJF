#include "horario.h"
#include "iostream"
#include <iomanip>

using namespace std;

Horario::Horario(int h , int m , int s)
{
    setHorario(h,m,s);
}

void Horario::setHora(int h) 
{
    this->hora = (h>=0 && h<24) ? h : 0;
}

void Horario::setMinuto(int m)
{
    this->minuto = (m>=0 && m<60) ? m : 0;
}

void Horario::setSegundo(int s)
{
    this->segundo = (s>=0 && s<60) ? s : 0;
}

void Horario::setHorario(int h, int m, int s)
{
    setHora(h);
    setMinuto(m);
    setSegundo(s);
}

int Horario::getHora() const 
{
    return this->hora;
}

int Horario::getMinuto() const 
{
    return this->minuto;
}

int Horario::getSegundo() const
{
    return this->segundo;
}

void Horario::imprimeHorario() const 
{
    cout<<setfill('0')<<setw(2)<<this->getHora()<<":"<<setw(2)<<this->getMinuto()<<":"<<setw(2)<<this->getSegundo()<<endl;
}