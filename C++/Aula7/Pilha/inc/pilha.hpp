#ifndef PILHA_H
#define PILHA_H

template<typename T>
class Pilha
{
private:
    int tam;
    int top;
    T *pPtr;
public:
    Pilha(int = 10);
    ~Pilha();
    bool insere(const T&);
    bool remove(T&);
    bool estaVazia() const;
    bool estaCheia() const;
};


template<typename T>
Pilha<T>::Pilha(int t)
{
    this->tam = t > 0 ? t:10;
    this->top = -1;
    this->pPtr = new T[this->tam];
}

template<typename T>
Pilha<T>::~Pilha()
{
    delete[] this->pPtr;
}

template<typename T>
bool Pilha<T>::insere(const T& valor)
{
    if(!estaCheia())
    {
        pPtr[++top] = valor;
        return true;
    }
    else
    {
       return false;  
    }    
}

template<typename T>
bool Pilha<T>::remove(T& var)
{
    if(!estaVazia())
    {
        var = pPtr[top--];
        return true;
    }
    else
    {
        return false;
    }
    
}

template<typename T>
bool Pilha<T>::estaVazia() const
{
    return top == -1;
}

template<typename T>
bool Pilha<T>::estaCheia() const
{
    return top == tam - 1;
}


#endif