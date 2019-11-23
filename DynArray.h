#pragma once

#include <iostream>
#include <utility>
#include <iterator>
#include <algorithm>

using namespace std;

template < class T >
class MyAllocator
{
public:
    typedef T value_type;
    typedef const value_type* const_pointer;
    typedef size_t size_type;

    MyAllocator()
    {}

    T* allocate(size_type count)
    {
        void* ptr = 0;
        if (count == 0)
            ;
        else if (((size_t)(-1) / sizeof(value_type) < count)
            || (ptr = ::operator new(count * sizeof(value_type))) == 0)
        {
            throw bad_alloc();
        }
        return ((T*)ptr);
    }

    void deallocate(void* ptr, size_type)
    {
        ::operator delete(ptr);
    }

    void construct(T* p, const T& val)
    {
        *p = val;
    }

    void destroy(T* p)
    {
        p->~T();
    }
};

template < class T,
           typename Allocator = MyAllocator<T> >
class Dynarray //6.2
{
private:
    T* dataPtr;
    int capacity; // allocated memory
    int length;   // using memory (formal amount of elements you can use)
    Allocator alloc;
public:
    static const int defaultAlloc = 10;
    static const int allocMult = 5;

    Dynarray() : length(1), capacity(defaultAlloc)
    {
        dataPtr = alloc.allocate(defaultAlloc);
        for (int i = 0; i < capacity; i++)
            dataPtr[i] = 0;
    }

    Dynarray(int size): length(size), capacity(size * allocMult)
    {
        dataPtr = alloc.allocate(size * allocMult);
        for (int i = 0; i < length; i++)
            dataPtr[i] = 0;
    }

    Dynarray(int size, T value) : length(size), capacity(size * allocMult)
    {
        dataPtr = alloc.allocate(size * allocMult);
        for (int i = 0; i < length; i++)
            dataPtr[i] = value;
    }

    ~Dynarray()
    {
        delete[] dataPtr;
    }

    class iterator
    {
    protected:
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
            this->operator--;
        }
        void operator--(int)
        {
            this->operator++;
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
        if (capacity > length)
        {
            dataPtr[length] = val;
            length++;
        }
        else
        {
            capacity *= allocMult;
            T* newDataPtr = alloc.allocate(capacity);
            for (int i = 0; i < length - 1; i++)
                newDataPtr[i] = dataPtr[i];
            newDataPtr[length - 1] = 0;

            //delete[] dataPtr;
            alloc.destroy(dataPtr);

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
        
        length--; //no matter old value still exist

        if (capacity / allocMult > length)
        {
            capacity /= allocMult;
            T* newDataPtr = alloc.allocate(capacity);
            for (int i = 0; i < length - 1; i++)
                newDataPtr[i] = dataPtr[i];

            //delete[] dataPtr;
            alloc.destroy(dataPtr);

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
        cout << "\n\t\t Array contains:\n";
        for (int i = 0; i < length; i++)
            cout << "\t" << dataPtr[i];
    }
};

