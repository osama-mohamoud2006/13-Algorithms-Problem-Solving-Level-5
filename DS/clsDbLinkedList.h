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
    virtual void InsertAtTheEnd(T Value) = 0;
    virtual void DeleteTheLastNode() = 0;
    virtual void DeleteTheFirstNode() = 0;
};

template <class T>
class clsDbLinkedList : public InterfaceDbLinkedList<T>
{

private:
    typename InterfaceDbLinkedList<T>::Node *Head;

public:
    using Node = typename InterfaceDbLinkedList<T>::Node; // to avoid writing unnecessary syntax every time

    clsDbLinkedList()
    {
        this->Head = nullptr;
    };

    void InsertAtTheBeginning(T Value) override // Insert At The Beginning
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
        if (Head == nullptr)
        {
            std::cout << "NULL\n";
            return;
        }
        Node *Temp = this->Head;

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

    void InsertAtTheEnd(T Value) override
    {
        // Create New Node
        Node *NNode = new Node(Value);

        if (Head == nullptr)
        {
            NNode->Prev = nullptr;
            NNode->Next = nullptr;
            Head = NNode;
            return;
        };

        // Traverse until The last Node
        Node *temp = this->Head;
        while (temp->Next != nullptr)
        {
            temp = temp->Next;
        };

        // The Last Element
        NNode->Prev = temp;
        temp->Next = NNode;
        NNode->Next = nullptr;
    };

    void DeleteTheLastNode() override
    {
        if (Head == nullptr)
            return;

        if (Head->Next == nullptr)
        {
            delete Head;
            Head = nullptr;
            return;
        }

        else
        {
            // Traverse to get the last node
            Node *Current = this->Head;
            while (Current->Next->Next != nullptr)
            {
                Current = Current->Next; // move to the next element
            };

            // The Last Node

            Current->Next->Prev = nullptr;
            delete Current->Next;
            Current->Next = nullptr;
        };
    };

    void DeleteTheFirstNode() override
    {
        if (Head == nullptr)
            return;

        // Case 1
        if (this->Head->Next == nullptr) // the first and the last node
        {
            delete Head;
            this->Head = nullptr;
            return;
        };

        // Case 2
        if (this->Head->Next != nullptr)
        {
            Head = Head->Next;
            delete Head->Prev ;
            Head->Prev = nullptr;
        };
    };


    
    ~clsDbLinkedList() // Destructor
    {
        std::cout << "\nDestructor\n";
        while (Head != nullptr)
        {
            DeleteTheLastNode();
        };
    };



};