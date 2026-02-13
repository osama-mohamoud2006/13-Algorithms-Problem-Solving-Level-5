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
public:
    typename InterfaceDbLinkedList<T>::Node *_Head;

protected:
    int _Size; // to track the num of elements in linked list

public:
    using Node = typename InterfaceDbLinkedList<T>::Node; // to avoid writing unnecessary syntax every time (i inherited it)

    clsDbLinkedList()
    {

        this->_Head = nullptr;
        this->_Size = 0;
    };

    void InsertAtTheBeginning(T Value) override // Insert At The Beginning
    {
        Node *NNode = new Node(Value); // create new node

        NNode->Prev = nullptr; // as it will be the first node
        NNode->Next = _Head;

        if (this->_Head != nullptr) // there is node
        {
            _Head->Prev = NNode;
        };

        this->_Head = NNode;
        this->_Size++;
    };

    void PrintList() override
    {
        if (_Head == nullptr)
        {
            std::cout << "NULL\n";
            return;
        }
        Node *Temp = this->_Head;

        while (Temp != nullptr)
        {
            std::cout << Temp->Value << " ";
            Temp = Temp->Next; // move to the next node
        };
    };

    // return the address of the found node
    Node *Find(T Value) override
    {
        Node *Temp = _Head;
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

        if (_Head == nullptr)
        {
            _Head = NNode;
            this->_Size++;
            return;
        };

        // Traverse until The last Node
        Node *temp = this->_Head;
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
        if (_Head == nullptr)
            return;

        if (_Head->Next == nullptr) // the real last element
        {
            delete _Head;
            _Head = nullptr;
            this->_Size--;
            return;
        }

        else
        {
            // Traverse to get the last node
            Node *Current = this->_Head;
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
        if (_Head == nullptr)
            return;

        // Case 1
        if (this->_Head->Next == nullptr) // the first and the last node
        {
            delete _Head;
            this->_Head = nullptr;
            this->_Size--;
            return;
        };

        // Case 2
        if (this->_Head->Next != nullptr)
        {
            _Head = _Head->Next;
            delete _Head->Prev;
            _Head->Prev = nullptr;
            this->_Size--;
        };
    };

    void DeleteNode(Node *TheNodeToDelete) override
    {
        if (TheNodeToDelete == nullptr || this->_Head == nullptr)
            return;

        if (TheNodeToDelete == this->_Head)
        {
            _Head = _Head->Next;
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
        if (this->_Head == nullptr || TheNodeYouWantToInsertAfter == nullptr)
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
        return (this->_Head == nullptr && this->_Size == 0);
    };

    void Clear() // O(n) Algorithm's Method
    {
        Node *Current = this->_Head;
        while (Current != nullptr)
        {
            Node *NextNode = Current->Next; // The Next Node
            delete Current;
            Current = NextNode;
        };
        this->_Size = 0;
        this->_Head = nullptr;
    };

    void Reverse()
    {
        if (this->_Head == nullptr || _Head->Next == nullptr)
            return; // there no need to reverse one node or reverse null

        Node *Current = this->_Head;
        Node *Temp = nullptr;

        while (Current != nullptr)
        {
            Temp = Current->Prev;
            Current->Prev = Current->Next;
            Current->Next = Temp;

            Current = Current->Prev; // move to the next node
        };

        if (Temp != nullptr)
            _Head = Temp->Prev;
    };

private:
    bool IsvalidIndex(int Index)
    {
        return (!(_Head == nullptr || Index >= this->_Size || Index < 0));
    };

public:
    Node *GetNode(int Index)
    {
        if (!IsvalidIndex(Index))
            return nullptr;

        Node *Current = this->_Head;
        // int C = 0;
        // while (Current != nullptr)
        // {
        //     if (C == Index)
        //         return Current;
        //     C++;
        //     Current = Current->Next;
        // };

        for (int i = 0; i < Index; i++)
        {
            Current = Current->Next;
        };
        return Current;
    };

    T GetItem(int Index)
    {
        Node *Val = GetNode(Index);
        return (Val != nullptr) ? Val->Value : throw std::out_of_range("Out Of Range!");
    };

    bool UpdateItem(int Index, T Value)
    {

        Node *Current = GetNode(Index); // Get The Node By Index

        if (Current != nullptr)
        {
            Current->Value = Value;
            return true;
        };

        return false;
    };

    void InsertAfter(int Index, T Value)
    {
        Node *TheNodeToInsertAfter = GetNode(Index);
        if (TheNodeToInsertAfter != nullptr)
        {
             InsertAfter(TheNodeToInsertAfter,Value);
        }
        
    };

    ~clsDbLinkedList() // Destructor
    {
        this->Clear();
    };
};