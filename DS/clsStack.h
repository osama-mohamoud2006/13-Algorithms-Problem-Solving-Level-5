#include <../DS/clsDbLinkedList.h>

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