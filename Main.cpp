#include <iostream>
#include <vector>
#include "DynArray.h"
#include "SomeData.h"
using namespace std;

template <typename T, class Arr> //6.1
int find_first(T val, Arr arr, int size) //returns index of first value "val" in array "array"
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

    int iArr[10] = { 2, 5, 7, 15, 60, 80, 90, 10, 10, 0 };
    float fArr[5] = { 2.4f, 3.14f, 2.0f };
    bool bArr[5];

    Dynarray<int> ilikesex(2);
    ilikesex.push_back(1);

    //Dynarray<int> *SUKA = new Dynarray<int>(0);
    //SUKA->push_back(1);

    cout << find_first(80, iArr, 10) << endl
        << find_first(6, fArr, 5) << endl
        << find_first(false, bArr, 5) << endl;
        //<< find_first(3, mArr, mArr.size()) << endl;

    //SomeData sd1(4, 5), sd2(3, 3);
    //if (sd1 > sd2)
    //    cout << 11111111111;

    int i;
    cin >> i;
}