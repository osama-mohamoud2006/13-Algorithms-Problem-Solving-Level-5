#include "../DS/clsDbLinkedList.h"

template <class T>
class StackInterface
{
public:
    virtual bool Empty() = 0;
    virtual T Top() = 0;
    virtual int Size() = 0;
    virtual void Print() = 0;
    virtual void Push(T Value) = 0;
    virtual void Pop() = 0;
};

template <class T>
class clsStack : StackInterface<T>
{
    // LIFO = Last In First Out
    // this class is just adapter
    // linked list is just container
    // so totally it is container adapter

private:
    clsDbLinkedList<T> Underlying;

public:
    void Push(T Value) override
    {
        Underlying.InsertAtTheBeginning(Value);
    };

    void Pop() override
    {
        Underlying.DeleteTheFirstNode();
    };

    void Print() override
    {
        Underlying.PrintList();
    };

    int Size() override
    {
        return Underlying.Size();
    };

    T Top() override
    {
        return Underlying.GetItem(0);
    };

    bool Empty() override
    {
        return Underlying.IsEmpty();
    };


};