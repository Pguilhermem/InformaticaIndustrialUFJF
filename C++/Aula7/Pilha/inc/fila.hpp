#ifndef FILA_H
#define FILA_H
<<<<<<< HEAD

=======
>>>>>>> 51551a395c848c345db6addc43b85c5fb0dd695e
using namespace std;

template <typename T>
class Fila
{
private:
    int tam;
    int top;
    T *pPtr;

public:
    Fila(int = 10);
    ~Fila();
    bool insere(const T &);
    bool remove(T &);
    bool estaVazia() const;
    bool estaCheia() const;
};

template <typename T>
Fila<T>::Fila(int t)
{
    this->tam = t > 0 ? t : 10;
    this->top = this->tam - 1;
    this->pPtr = new T[this->tam];
}

template <typename T>
bool Fila<T>::insere(const T &valor)
{
    if (!estaCheia())
    {
        pPtr[top--] = valor;
        cout << "Dado adicionado a Fila: " << valor << endl;
        return true;
    }
    return false;
}

template <typename T>
bool Fila<T>::remove(T &var)
{
    if (!estaVazia())
    {
        this->top++;
        var = pPtr[this->tam - 1 - this->top];
        cout << "Dado removido da Fila: " << var << endl;
        return true;
    }
    return false;
}
template <typename T>
bool Fila<T>::estaVazia() const
{
    return this->top == this->tam - 1;
}

template <typename T>
bool Fila<T>::estaCheia() const
{
    return this->top == -1;
}

template <typename T>
Fila<T>::~Fila()
{
    delete[] this->pPtr;
}
<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> 51551a395c848c345db6addc43b85c5fb0dd695e
