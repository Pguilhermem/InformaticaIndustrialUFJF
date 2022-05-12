#ifndef HORARIO_H
#define HORARIO_H

class Horario
{
private:
    int hora;
    int minuto;
    int segundo;
public:
    Horario(int=12, int=0, int=0);

    //funções get
    int getHora() const;
    int getMinuto() const ;
    int getSegundo() const ;

    //funções set
    void setHorario(int,int,int);
    void setHora(int);
    void setMinuto(int);
    void setSegundo(int);

    void imprimeHorario() const ;
};


#endif