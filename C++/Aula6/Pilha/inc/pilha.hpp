//Esse arquivo recebe a extensão hpp por possuir um template
#ifndef PILHA_H
#define PILHA_H

template<typename T>//T fica definido como uma "variavel" para os tipos dos atributos e metodos, como por exemplo: int,float,bool...
class Pilha
{
private:
    int tam;
    int top;
    T *pPtr;//pPtr apontara para o tipo de variavel definido no main no momento de sua declaração
public:
    Pilha(int = 10);
    ~Pilha();
    bool insere(const T&);
    bool remove(T&);
    bool estaVazia() const;
    bool estaCheia() const;
};


template<typename T>
Pilha<T>::Pilha(int t)//Cria uma vetor de tamanho variavel do tipo T
{
    this->tam = t > 0 ? t:10;//Essa linha diz: Se t>0, this->tam = t, senão: this->tam=10
    this->top = -1;
    this->pPtr = new T[this->tam];
}

template<typename T>
Pilha<T>::~Pilha()//Deleta o vetor criado no construtor
{
    delete[] this->pPtr;
}

template<typename T>
bool Pilha<T>::insere(const T& valor)//Insere um valor no topo da pilha
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
bool Pilha<T>::remove(T& var)//Remove o ultimo elemento inserido na pilha e atribui a var o valor do dado removido(passagem por referencia)
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
bool Pilha<T>::estaVazia() const//Verifica se a pilha esta vazia
{
    return top == -1;
}

template<typename T>
bool Pilha<T>::estaCheia() const//Verifica se a pilha esta cheia
{
    return top == tam - 1;
}


#endif
