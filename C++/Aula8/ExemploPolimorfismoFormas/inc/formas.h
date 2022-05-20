#ifndef FORMAS_H
#define FORMAS_H

class FormaBiDimensional
{
    public:
    virtual double calculaArea() = 0;

};

class Circulo : public FormaBiDimensional
{
    private:
        float raio;
    public:
        Circulo(float r);
        bool setraio(float r);
        float getraio();
        double calculaArea();
};

class Quadrado : public FormaBiDimensional
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