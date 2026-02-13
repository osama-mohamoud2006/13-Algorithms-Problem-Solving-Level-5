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
    virtual void DeleteNode(Node *TheNodeToDelete) = 0;
    virtual void InsertAfter(Node *TheNodeYouWantToInsertAfter, T Value) = 0;
};

template <class T>
class clsDbLinkedList : public InterfaceDbLinkedList<T>
{
private:
    typename InterfaceDbLinkedList<T>::Node *Head;

protected:
    int _Size; // to track the num of elements in linked list

public:
    using Node = typename InterfaceDbLinkedList<T>::Node; // to avoid writing unnecessary syntax every time (i inherited it)

    clsDbLinkedList()
    {

        this->Head = nullptr;
        this->_Size = 0;
    };

    void InsertAtTheBeginning(T Value) override // Insert At The Beginning
    {
        Node *NNode = new Node(Value); // create new node

        NNode->Prev = nullptr; // as it will be the first node
        NNode->Next = Head;

        if (this->Head != nullptr) // there is node
        {
            Head->Prev = NNode;
        };

        this->Head = NNode;
        this->_Size++;
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
        };
    };

    // return the address of the found node
    Node *Find(T Value) override
    {
        Node *Temp = Head;
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
            Head = NNode;
            this->_Size++;
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
        this->_Size++;
    };

    void DeleteTheLastNode() override
    {
        if (Head == nullptr)
            return;

        if (Head->Next == nullptr) // the real last element
        {
            delete Head;
            Head = nullptr;
            this->_Size--;
            return;
        }

        else
        {
            // Traverse to get the last node
            Node *Current = this->Head;
            while (Current->Next->Next != nullptr) // O(N)
            {
                Current = Current->Next; // move to the next element
            };

            // The Last Node
            Node *Temp = Current->Next;
            Temp->Prev->Next = nullptr;
            Temp->Prev = nullptr;
            delete Temp;
            this->_Size--;
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
            this->_Size--;
            return;
        };

        // Case 2
        if (this->Head->Next != nullptr)
        {
            Head = Head->Next;
            delete Head->Prev;
            Head->Prev = nullptr;
            this->_Size--;
        };
    };

    void DeleteNode(Node *TheNodeToDelete) override
    {
        if (TheNodeToDelete == nullptr || this->Head == nullptr)
            return;

        if (TheNodeToDelete == this->Head)
        {
            Head = Head->Next;
        }

        if (TheNodeToDelete->Next != nullptr)
        {
            TheNodeToDelete->Next->Prev = TheNodeToDelete->Prev;
        }

        if (TheNodeToDelete->Prev != nullptr)
        {
            TheNodeToDelete->Prev->Next = TheNodeToDelete->Next;
        }

        delete TheNodeToDelete;
        this->_Size--;
    };

    void InsertAfter(Node *TheNodeYouWantToInsertAfter, T Value) override
    {
        if (this->Head == nullptr || TheNodeYouWantToInsertAfter == nullptr)
            return;

        Node *NNode = new Node(Value);

        NNode->Next = TheNodeYouWantToInsertAfter->Next;
        NNode->Prev = TheNodeYouWantToInsertAfter;

        if (TheNodeYouWantToInsertAfter->Next != nullptr) // The Next Node Is Here
        {
            TheNodeYouWantToInsertAfter->Next->Prev = NNode;
        };

        TheNodeYouWantToInsertAfter->Next = NNode;
        this->_Size++;
    };

    int Size() const // O(1) Algorithm
    {
        return this->_Size;
    };

    bool IsEmpty() const
    {
        return (this->Head == nullptr && this->_Size == 0);
    };


    void Clear()
    {
         while (!IsEmpty())
        {
           DeleteTheFirstNode(); // O(1) Algorithm's Method
        };
    };

    ~clsDbLinkedList() // Destructor
    {
        while (!IsEmpty())
        {
            DeleteTheFirstNode();
        };
    };


};