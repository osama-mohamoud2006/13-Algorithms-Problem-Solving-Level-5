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

};