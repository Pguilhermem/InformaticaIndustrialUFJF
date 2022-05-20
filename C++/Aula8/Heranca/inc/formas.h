#ifndef FORMAS_H
#define FORMAS_H

class FormaBiDimensional
{
    public:
    virtual double calculaArea() = 0;

};

class Circulo : public FormaBiDimensional
{
    public:
        float raio;
        Circulo(float r): raio(r)
        {

        }
        double calculaArea()
        {
            return raio*raio*3.14;
        }
};

class Quadrado : public FormaBiDimensional
{
    public:
        Quadrado(float q): x(q) 
        {

        }
        float x;
        double calculaArea()
        {
            return x*x;
        }
};

#endif