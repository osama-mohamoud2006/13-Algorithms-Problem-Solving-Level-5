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

private:
    clsDbLinkedList<T> Underlying;
    int _Size = 0;

public:
    void Push(T Value) override // insert at the end
    {
        Underlying.InsertAtTheEnd(Value);
        _Size++;
    };

    void Pop() override // remove from the first
    {
        if (_Size == 0)
            return; // underflow protection
        Underlying.DeleteTheFirstNode();
        _Size--;
    };

    int Size() override
    {
        return this->_Size;
    };

    T Front() override
    {
        return Underlying.GetItem(0); // return the first element
    };

    T Back() override
    {
        return Underlying.GetItem((this->_Size - 1)); // return the last element
    };

    bool Empty()
    {
        return (this->_Size == 0);
    }

    void Print() override
    {
        clsQueue<T> Temp = *this;
        while (!this->Empty())
        {
            cout <<Temp->Front() <<" ";
            Temp->Pop();
        };
    };
};