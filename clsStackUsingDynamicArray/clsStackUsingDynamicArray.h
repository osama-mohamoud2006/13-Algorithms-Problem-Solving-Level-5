#pragma once
#include "../clsQueueUsingDynamicArray/QueueUsingDynamicArray.h"

template <class T>
class clsStack : public clsQueue<T>
{
    // LIFO
    // I Inherited The Queue As It Is Very Similar To Stack And I Will Override Main Methods
    // To Be LIFO paradigm
    // This Class Is Adapter
    // Dynamic Array Is The Underlying Container

public:
    void Push(T Value) override
    {
        clsQueue<T>::Underlying.InsertAtBeginning(Value);
    };

    void Pop() override
    {
        clsQueue<T>::Underlying.DeleteFirstItem();
    };

    T Top()
    {
        return  clsQueue<T>::Front();
    };
};