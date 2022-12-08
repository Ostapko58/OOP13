#pragma once
#include <iostream>
#include <math.h>
#include <string>
#include<array>
using namespace std;
template <class T> // T - ���
class vector
{
    T* v; // �������� �����
    int size; // ������� ��������
public:
    vector(int newsize); // ����������� �����������
    vector(vector&); // ����������� ���������
    ~vector(); // ����������
    friend vector<T> operator - <>(vector<T>& x, vector<T>& y); // ��������
    double scalar(vector<T>& vector);

    T& operator [] (int index); // ������������
    vector& operator = (const vector&); // ���������
    friend ostream& operator << <>(ostream&, vector&); // ���������
    friend istream& operator >> <>(istream&, vector&);
};

template <class T>
vector<T>::vector(int newsize) // ����������� �����������
{
    v = new T[size = newsize]; // ����� �����, �������� ���'�� ���
    for (int i = 0; i < size; i++) // ��������� �������� ������� ���������
        v[i] = T();

}
template <class T>
vector<T>::vector(vector<T>& x) // ����������� ���������
{
    v = new T[size = x.size]; // ����� �����, �������� ���'�� ���
    for (int i = 0; i < size; i++) // ��������� ������� ���������
        v[i] = x.v[i];

}
template <class T>
vector<T>::~vector()
{
    delete[] v; // ��������� ���'��
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
vector<T> operator - (vector<T>& x, vector<T>& y) // ����������
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



