#include <iostream>
#include <vector>
#include "DynArray.h"
#include "SomeData.h"
#include <stdlib.h>
using namespace std;

int main()
{
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
    
    //ðàáîòà 8.1
    cout << "\n\n";
    for (Dynarray<SomeData>::iterator it = dataVec.begin(); it != dataVec.end(); it++)
    {
        cout << (*it);
    }

    dataVec.~Dynarray();

    system("pause");
}
