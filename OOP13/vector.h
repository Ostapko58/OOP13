#pragma once
#include <iostream>
#include <math.h>
#include <string>
#include<array>
using namespace std;
template <class T> // T - тип
class vector
{
    T* v; // внутрішній масив
    int size; // кількість елементів
public:
    vector(int newsize); // конструктор ініціалізації
    vector(vector&); // конструктор копіювання
    ~vector(); // деструктор
    friend vector<T> operator - <>(vector<T>& x, vector<T>& y); // віднімання
    double scalar(vector<T>& vector);

    T& operator [] (int index); // індексування
    vector& operator = (const vector&); // присвоєння
    friend ostream& operator << <>(ostream&, vector&); // виведення
    friend istream& operator >> <>(istream&, vector&);
};

template <class T>
vector<T>::vector(int newsize) // конструктор ініціалізації
{
    v = new T[size = newsize]; // новий розмір, виділення пам'яті для
    for (int i = 0; i < size; i++) // присвоєння нульових значень елементам
        v[i] = T();

}
template <class T>
vector<T>::vector(vector<T>& x) // конструктор копіювання
{
    v = new T[size = x.size]; // новий розмір, виділення пам'яті для
    for (int i = 0; i < size; i++) // присвоєння значень елементам
        v[i] = x.v[i];

}
template <class T>
vector<T>::~vector()
{
    delete[] v; // звільнення пам'яті
}

template<class T>
double vector<T>::scalar(vector<T>& vector)
{
    if (vector.size != this->size)
    {
        throw exception("The sizes should be the same!");

    }
    double result = 0;
    for (int i = 0; i < vector.size; i++)
        result += (vector.v[i] * this->v[i]);
    return result;
}

template <class T>
vector<T> operator - (vector<T>& x, vector<T>& y) // відмінювання
{
    if (x.size != y.size)
    {
        throw exception("The sizes should be the same!");

    }
    vector<T> z(x.size);
    for (int i = 0; i < x.size; i++)
        z.v[i] = x.v[i] - y.v[i];
    return z;
}

template <class T>
T& vector<T>::operator [] (int index)
{
    if (index < 0 || index >= size)
    {
        throw exception("Index out of the range");
    }
    return v[index];
}
template <class T>
vector<T>& vector<T>::operator = (const vector<T>& x)
{
    if (this != &x)
    {
        delete[] v;
        v = new T[size = x.size];
        for (int i = 0; i < size; i++)
            v[i] = x.v[i];

    }
    return *this;
}
template <class T>
istream& operator >> (istream& is, vector<T>& x)
{
    cout << "Input " << x.size << " elements of vector" << endl;
    for (int i = 0; i < x.size; i++) {
        cout << "element[" << i << "] = ? ";
        is >> x.v[i];
    }
    return is;
}

template <class T>
ostream& operator << (ostream& os, vector<T>& x)
{
    for (int i = 0; i < x.size; i++)
        os << x.v[i] << ' ';
    os << endl;
    return os;
}



