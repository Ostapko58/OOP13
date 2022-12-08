#include <iostream>
#include"vector.h"
using namespace std;

//--------------------------------------
//Написати функцію-шаблон, яка повертає кількість елементів та обчислює
//середнє значення елементів масиву.
template<class T>
int avarageAndSize(T* array, int size) {
    T avarage = 0;
    for (int i = 0; i < size; i++) {
        avarage += array[i];
    }
    cout << "Avarage = " << double(avarage / size) << endl;
    return size;
}


int main()
{
    int arr[5] = { 1,2,3,4,5 };
    cout << avarageAndSize(arr, 5) << endl;

    double arr2[5] = { 1.3,2.8,3,4,5 };
    cout << avarageAndSize(arr2, 5) << endl;
    try {
        vector<int> v(3);
        cin >> v;
        cout << v;
        vector<int> v2(3);
        cin >> v2;
        cout << v.scalar(v2) << endl;
        vector<int> c(3);
        c = (v - v2);
        cout << c << endl;

        vector<double> v3(3);
        cin >> v3;
        cout << v3;
        vector<double> v4(3);
        cin >> v4;
        cout << v3.scalar(v4) << endl;
        vector<double> c2(3);
        c2 = (v3 - v4);
        cout << c2 << endl;
    }
    catch (exception e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
