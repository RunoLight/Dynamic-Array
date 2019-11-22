#pragma once
#include <iostream>
#include <utility>
#include <iterator>
#include <algorithm>
using namespace std;

template <class T>
class Dynarray //6.2
{
private:
    T* dataPtr;
    int allocated;
    int length;
public:
    static const int defaultAlloc = 10;
    static const int allocMult = 5;

    Dynarray(): length(1), allocated(defaultAlloc), dataPtr(new T[defaultAlloc])
    {
        for (int i = 0; i < allocated; i++)
            dataPtr[i] = 0;
    }

    Dynarray(int size): length(size), allocated(size * allocMult), dataPtr(new T[size * allocMult])
    {
        for (int i = 0; i < length; i++)
            dataPtr[i] = 0;
    }

    Dynarray(int size, T value) : length(size), allocated(size * allocMult), dataPtr(new T[size * allocMult])
    {
        for (int i = 0; i < length; i++)
            dataPtr[i] = value;
    }

    ~Dynarray()
    {
        delete[] dataPtr;
    }

    class iterator
    {
    private:
        int index;
        Dynarray* pData;
    public:
        iterator() noexcept
        {
            index = 0;
            pData = nullptr;
        }
        iterator(int i, Dynarray* p) noexcept
        {
            index = i;
            pData = p;
        }
        virtual void operator++(int)
        {
            index++;
        }
        virtual void operator--(int)
        {
            index--;
        }
        int operator !=(iterator it)
        {
            if (index != it.index)
                return 1;
            return 0;
        }
        int operator ==(iterator it)
        {
            if (index == it.index)
                return 1;
            return 0;
        }
        T& operator* ()
        {
            if (pData)
            {
                return pData->dataPtr[index];
            }
            else
                throw 0;
        }
    };

    class reverse_iterator: public iterator
    {
    public:
        reverse_iterator(): iterator()
        {}
        reverse_iterator(int i, Dynarray* p): iterator(i, p) //or *p?
        {}
        void operator++(int)
        {
            index--;
        }
        void operator--(int)
        {
            index++;
        }
    };

    iterator begin()
    {
        return iterator(0, this);
    }

    reverse_iterator rbegin()
    {
        return reverse_iterator(length, this);
    }

    iterator end()
    {
        return iterator(length, this);
    }

    reverse_iterator rend()
    {
        return reverse_iterator(0, this);
    }

    T& operator[](int index)
    {
        if (index >= length)
            throw exception("ure doin bad things"); //std::out_of_range
        return *(dataPtr + index);
    }

    void push_back(T val)
    {
        if (allocated > length)
        {
            dataPtr[length] = val;
            length++;
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
            return;
        }
        
        length--; //no matter old value contains (i hope)

        if (allocated / allocMult > length)
        {
            allocated /= allocMult;
            T* newDataPtr = new T[allocated];
            for (int i = 0; i < length - 1; i++)
                newDataPtr[i] = dataPtr[i];
            delete[] dataPtr;
            dataPtr = newDataPtr;
        }
    }

    int size()
    {
        return length;
    }

    void swap(T* a, T* b)
    {
        T temp = *a;
        *a = *b;
        *b = temp;
    }

    void sort()
    {
        for (int i = 0; i < length - 1; i++) 
            for (int j = 0; j < length - i - 1; j++)
                if (dataPtr[j] > dataPtr[j + 1])
                    swap(&dataPtr[j], &dataPtr[j + 1]);
    }

    void info()
    {
        cout << "\n\t\t Array contains:";
        for (int i = 0; i < length; i++)
            cout << "\n\t" << dataPtr[i];
    }
};

template <typename TT, class Arr> //6.1
int find_first(TT val, Arr &arr, int size) //returns index of first value "val" in array "array"
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == val)
            return i;
    }
    return -1;
}