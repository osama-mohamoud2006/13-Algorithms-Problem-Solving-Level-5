#include "../DS/clsDbLinkedList.h"

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
    // FIFO = First in First out
    // This class is just adapter
    // and linked list is the container
    // so totally it is adapter container

protected:
    clsDbLinkedList<T> Underlying; /// Compositation 

public:
    void Push(T Value) override // insert at the end
    {
        Underlying.InsertAtTheEnd(Value);
    };

    void Pop() override // remove from the first
    {
        Underlying.DeleteTheFirstNode();
    };

    int Size() override
    {
        return Underlying.Size();
    };

    T Front() override
    {
        return Underlying.GetItem(0); // return the first element
    };

    T Back() override
    {
        return Underlying.GetItem((Size() - 1)); // return the last element
    };

    bool Empty()
    {
        return (Underlying.IsEmpty());
    };

    void Print() override
    {
       Underlying.PrintList(); 
    };

};