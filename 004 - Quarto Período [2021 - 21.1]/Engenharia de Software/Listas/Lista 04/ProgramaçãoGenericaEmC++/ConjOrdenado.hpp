#ifndef CONJORDENADO_H
#define CONJORDENADO_H

#include <iostream>
#include <vector>

using namespace std;

#include "Estudante.hpp"
#include "Disciplina.hpp"

template <typename Ord, class T>
class ConjOrdenado {
    private:
    vector< pair<Ord,T>> conjunto;

    public:
    ConjOrdenado();
    vector<T> getConjunto() const;
    void add(Ord, T);
    T operator[](int i);
};

template <typename Ord, class T>
ConjOrdenado<Ord,T>::ConjOrdenado(void){}

template <typename Ord, class T>
vector<T> ConjOrdenado<Ord,T>::getConjunto() const {
    size_t n = conjunto.size();
    vector<T> aux(n);
    for(size_t i = 0; i < n; i++)
        aux[i] = conjunto[i].second;

    return aux;
}

template <typename Ord, class T>
void ConjOrdenado<Ord,T>::add(Ord ord, T item){
    conjunto.push_back(make_pair(ord, item));
    sort(conjunto.begin(), 
        conjunto.end(), 
        [](const pair<Ord, T> i1, const pair<Ord, T> i2){ 
            return i1.first < i2.first;
        }
    );
}

template <typename Ord, class T>
T ConjOrdenado<Ord, T>::operator[](int i) {
    return this->conjunto[i].second;
}

#endif
