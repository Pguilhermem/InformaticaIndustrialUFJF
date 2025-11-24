#ifndef FORMAS_H
#define FORMAS_H

class FormaBiDimensional
{
    private:
    int id;
    
    public:
    virtual double calculaArea() = 0 ;//Todas as formas possuem area, mas ela e calculada diferente para cada forma
    int getID();  //O metodo virtual nem necessita de ser escrito no formas.cpp
};

class Circulo : public FormaBiDimensional//O circulo e uma forma bidimensional, logo tudo que as formas bidimensionais possuem ela possui tambem
{
    private:
        float raio;
    public:
        Circulo(float r);
        bool setraio(float r);
        float getraio();
        double calculaArea();
};

class Quadrado : public FormaBiDimensional//O quadrado e uma forma bidimensional, logo tudo que as formas bidimensionais possuem ela possui tambem
{
    private:
        float lado;
    public:
        Quadrado(float q);
        bool setlado(float l);
        float getlado();
        double calculaArea();
};

#endif
