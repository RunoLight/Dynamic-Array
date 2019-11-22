#include <iostream>
#include <vector>
#include "DynArray.h"
#include "SomeData.h"
#include <stdlib.h>
using namespace std;



int main()
{
    // Задание: 6.1 - функция которая будет искать первое вхождение элемента в массиве
    //          6.2 - класс, хранящий данные, умеющий сортировать и умеющий выводить информацию(info(); )
    int iArr[10] = { 2, 5, 7, 15, 60, 80, 90, 10, 10, 0 };
    float fArr[5] = { 2.4f, 3.14f, 2.0f };
    bool bArr[5];
    Dynarray<int> myVec(5);
    myVec.push_back(1); myVec.push_back(13); myVec.push_back(3);

    cout << find_first(80, iArr, 10) << endl
        << find_first(6, fArr, 5) << endl
        << find_first(true, bArr, 5) << endl
        << find_first<int, Dynarray<int>>(1, myVec, myVec.size()) << endl;

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
    dataVec.info();

    system("pause");
}