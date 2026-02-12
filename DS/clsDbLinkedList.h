#include <iostream>

template <class T>
class InterfaceDbLinkedList // contract / interface / abstract class
{

public: // i put Node Here Because Of The pure virtual Methods That Return Node(class) value
    class Node
    {
    public:
        Node *Next;
        Node *Prev;
        T Value;

        Node(T Value)
        {
            this->Next = nullptr;
            this->Prev = nullptr;
            this->Value = Value;
        };
    };


    virtual void InsertAtTheBeginning(T Value) = 0;
    virtual void PrintList() = 0;
    virtual Node *Find(T value) = 0; // Find by Value
};

template <class T>
class clsDbLinkedList : public InterfaceDbLinkedList<T>
{
    using node = typename InterfaceDbLinkedList<T>::Node; // to avoid writing unnecessary syntax every time 

private:
    typename InterfaceDbLinkedList<T>::Node *Head;

public:
    clsDbLinkedList()
    {
        this->Head = nullptr;
    };

    // Insert At The Beginning

    void InsertAtTheBeginning(T Value) override
    {

        typename InterfaceDbLinkedList<T>::Node *NNode = new typename InterfaceDbLinkedList<T>::Node(Value); // create new node

        NNode->Prev = nullptr; // as it will be the first node

        if (this->Head != nullptr) // there is next node
        {
            NNode->Next = Head;
            NNode->Next->Prev = NNode;
            this->Head = NNode;
            return;
        };
        NNode->Next = nullptr;

        this->Head = NNode;
    };

    void PrintList() override
    {
        typename InterfaceDbLinkedList<T>::Node *Temp = this->Head;

        while (Temp != nullptr)
        {
            std::cout << Temp->Value << std::endl;
            Temp = Temp->Next; // move to the next node
        }
    };

    // return the address of the found node
    typename InterfaceDbLinkedList<T>::Node *Find(T Value) override
    {
        typename InterfaceDbLinkedList<T>::Node *Temp = Head;
        while (Temp != nullptr)
        {
            if (Temp->Value == Value)
                return Temp;
            Temp = Temp->Next; // move to the next node
        };
        return nullptr;
    };
};