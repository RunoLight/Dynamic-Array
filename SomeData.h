#pragma once

class SomeData
{
public:
    int data;
    int someMoreData;

    SomeData(int _data, int _someMoreData) : data(_data), someMoreData(_someMoreData)
    {};

    int operator>(SomeData second)
    {
        if (data > second.data)
            return 1;
    }
};

