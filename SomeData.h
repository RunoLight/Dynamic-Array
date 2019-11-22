#pragma once

#include <iostream>
using namespace std;

class SomeData
{
public:
    int data;
    int someMoreData;

    SomeData() : data(0), someMoreData(0)
    {}

    SomeData(int _data, int _someMoreData) : data(_data), someMoreData(_someMoreData)
    {}

    int operator > (SomeData second)
    {
        if (data > second.data)
            return 1;
        else if ((data == second.data) && (someMoreData > second.someMoreData))
            return 1;
        return 0;
    }

    SomeData& operator = (int val)
    {
        data = val;
        someMoreData = val;
        return *this;
    }

    friend std::ostream& operator<< (std::ostream& out, const SomeData& somedata)
    {
        out << "There's some data: (" << somedata.data << ", " << somedata.someMoreData << ")\n";

        return out;
    }


};

