#pragma once
#include "../clsQueueUsingDbLinkedList/clsQueue.h"

template <class T>

// Public is an inheritance visiblity mode which allows to see what this class inherited from the base class for all outsiders

class clsStack : public clsQueue<T> // reuse the queue again and change its behaviour to cope with stack
{
    // LIFO = Last In First Out
    // this class is just adapter
    // linked list is just container
    // so totally it is container adapter

public:
    void Push(T Value) override // redefine the Push method in the queue to cope with LIFO 
    {
        clsQueue<T>::Underlying.InsertAtTheBeginning(Value);
    };

    void Pop() override   // redefine the Pop method in the queue to cope with LIFO 
    { 
        clsQueue<T>::Underlying.DeleteTheFirstNode();
    };

    T Top() // New Method 
    {
        return clsQueue<T>::Front();
    };
};

// Another Solution ///

// template <class T>
// class clsStack : StackInterface<T>
// {
//     // LIFO = Last In First Out
//     // this class is just adapter
//     // linked list is just container
//     // so totally it is container adapter

// private:
//     clsDbLinkedList<T> Underlying;

// public:
//     void Push(T Value) override
//     {
//         Underlying.InsertAtTheBeginning(Value);
//     };

//     void Pop() override
//     {
//         Underlying.DeleteTheFirstNode();
//     };

//     void Print() override
//     {
//         Underlying.PrintList();
//     };

//     int Size() override
//     {
//         return Underlying.Size();
//     };

//     T Top() override
//     {
//         return Underlying.GetItem(0);
//     };

//     bool Empty() override
//     {
//         return Underlying.IsEmpty();
//     };

// };