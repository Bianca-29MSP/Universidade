#ifndef ESTATISTICA_H
#define ESTATISTICA_H

#include <iostream>
#include <vector>

#include "Estudante.hpp"
#include "Disciplina.hpp"

template <class T, typename V>
int count(vector<T> arr, V value) {
    int count = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if(arr[i] == value) {
            count += 1;
        }
    }

    return count;
}

template <class T>
float sum(vector<T> arr){
    float sum = 0;
    int n = arr.size();
    if(n % 2 == 0) {
        for(int i = 0; i < n - 1; i+=2) 
            sum += (arr[i] + arr[i + 1]);
    } else {
        for(int i = 0; i < n - 1; i+=2)
            sum += (arr[i] + arr[i + 1]);
        sum = arr[n-1] + sum;
    }
    
    return sum;
}

template <class T>
float average(vector<T> arr){
    return sum(arr) / (float)arr.size();
}

#endif