#include <iostream>
#include <vector>
#include "DynArray.h"
#include "SomeData.h"
#include <stdlib.h>
using namespace std;

template <typename TT, class Arr> //6.1
int find_first(TT val, Arr& arr, int size) //returns index of first value "val" in array "array"
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == val)
            return i;
    }
    return -1;
}

int main()
{
    // Задание: 6.1 - функция которая будет искать первое вхождение элемента в массиве
    //          6.2 - класс, хранящий данные, умеющий сортировать и умеющий выводить информацию(info(); )
    //          8.1 - итератор
    //          8.2 - аллокатор
    int iArr[10] = { 2, 5, 7, 15, 60, 80, 90, 10, 10, 0 };
    float fArr[5] = { 2.4f, 3.14f, 2.0f };
    bool bArr[5];
    Dynarray<int> myVec(5);
    myVec.push_back(1); myVec.push_back(13); myVec.push_back(3);

    //работа 6.1
    cout << find_first(80, iArr, 10) << endl
        << find_first(6, fArr, 5) << endl
        << find_first(true, bArr, 5) << endl
        << find_first<int, Dynarray<int>>(1, myVec, myVec.size()) << endl;

    //работа 6.2
    myVec.info();
    myVec.sort();
    myVec.info();

    cout << endl;
    SomeData sd1(4, 5), sd2(3, 3);
    
    Dynarray<SomeData> dataVec(1, sd1);
    dataVec.push_back(sd2);
    dataVec.push_back(SomeData(4,3));

    dataVec.info();
    dataVec.sort();
    
    //работа 8.1
    cout << "\n\n";
    for (Dynarray<SomeData>::iterator it = dataVec.begin(); it != dataVec.end(); it++)
    {
        cout << (*it);
    }

    dataVec.~Dynarray();

    system("pause");
}