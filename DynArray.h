#pragma once
#include <iostream>
#include <utility>
using namespace std;

template <class T>
class Dynarray //6.2
{
private:
    T* dataPtr;
    int allocated;
    int length;
public:
    static int defaultAlloc = 10;
    static int allocMult = 5;

    Dynarray(): length(1), allocated(defaultAlloc), dataPtr(new T[allocated])
    {
        for (int i = 0; i < allocated; i++)
            dataPtr[i] = 0;
    }

    Dynarray(int size): length(size), allocated(size * allocMult), dataPtr(new T[allocated])
    {
        for (int i = 0; i < size; i++)
            dataPtr[i] = 0;
    }

    Dynarray(int size, T value) : length(size), allocated(size * allocMult), dataPtr(new T[allocated])
    {
        for (int i = 0; i < size; i++)
            dataPtr[i] = value;
    }

    ~Dynarray()
    {
        delete[] dataPtr;
    }

    T& operator[](int index)
    {
        if (index >= length)
            throw std::out_of_range;
        return *(dataPtr + index);
    }

    void push_back(int val)
    {
        if (allocated > length)
        {
            dataPtr[length] = val;
            lenght++;
        }
        else
        {
            allocated *= allocMult;
            T* newDataPtr;
            newDataPtr = new T[allocated];
            for (int i = 0; i < length - 1; i++)
                newDataPtr[i] = dataPtr[i];
            newDataPtr[length - 1] = 0;
            delete[] dataPtr;
            dataPtr = newDataPtr;
        }
    }

    void pop()
    {
        if (length == 1)
        {
            dataPtr[0] = 0;
            return nullptr;
        }

        T* pnewa = new T[length-- - 1];
        for (int i = 0; i < length - 1; i++)
            pnewa[i] = dataPtr[i];
        delete[] dataPtr;
        dataPtr = pnewa;
    }

    int size()
    {
        return length;
    }

    void sort()
    {
        
    }

    void info()
    {
        cout << "\n\t\t Array contains:";
        for (int i = 0; i < length; i++)
            cout << "\n\t" << dataPtr[i];
    }
};