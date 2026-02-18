#pragma once
#include "../clsDynamicArray/clsDynamicArray.h"

template <class T>
class InterfaceQueue
{
public:
    virtual int Size() = 0;
    virtual T Front() = 0;
    virtual T Back() = 0;
    virtual void Print() = 0;
    virtual void Push(T Value) = 0;
    virtual void Pop() = 0;
};

template <class T>
class clsQueue : public InterfaceQueue<T>
{
    //FIFO
    // This Class Is Just Adapter
    // Dynamic Array Is Just Underlying Container
protected:
    clsDynamicArray<T> Underlying =clsDynamicArray<T>(0) ;

public:
    void Push(T Value) override
    {
        Underlying.InsertAtTheEnd(Value);
    };

    void Pop() override
    {
        Underlying.DeleteFirstItem();
    };

    void Print() override
    {
        Underlying.PrintArrayItems();
    };

    T Back() override // Last Element
    {
        int index = Underlying.ArraySize();
        return Underlying.GetItem(index-1 );
    };

    T Front() override // First Element
    {
        return Underlying.GetItem(0);
    };

    int Size() override
    {
        return Underlying.ArraySize();
    };

    bool Empty(){
        return Underlying.IsEmpty() ;
    };


    void Clear()
    {
        Underlying.Clear();
    }
};