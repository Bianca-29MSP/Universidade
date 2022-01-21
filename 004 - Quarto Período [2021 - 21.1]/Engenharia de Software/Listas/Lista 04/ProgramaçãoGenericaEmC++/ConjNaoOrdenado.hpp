#ifndef CONJNAOORDENADO_H
#define CONJNAOORDENADO_H

#include <iostream>
#include <vector>

#include "Estudante.hpp"
#include "Disciplina.hpp"

using namespace std;

template <class T>
class ConjNaoOrdenado {
    private:
    vector<T> conjunto;

    public:
    ConjNaoOrdenado(void);

    vector<T> getConjunto();
    T operator[](int i);

    void add(T);
};

template <class T>
ConjNaoOrdenado<T>::ConjNaoOrdenado(void){}

template <class T>
vector<T> ConjNaoOrdenado<T>::getConjunto() {
    return conjunto;
}

template <class T>
void ConjNaoOrdenado<T>::add(T item){
    conjunto.push_back(item);
}

template <class T>
T ConjNaoOrdenado<T>::operator[](int i) {
    return this->conjunto[i];
}

#endif
