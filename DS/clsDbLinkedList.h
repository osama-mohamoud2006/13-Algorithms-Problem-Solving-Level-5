#include <iostream>

template <class T>
class clsDbLinkedList; //template class declration 

template <class T>
class DbLinkedListInterface
{
    virtual void InsertAtTheBeginning(T Value) = 0;
    virtual void PrintList() = 0;
    virtual 
};

template <class T>
class clsDbLinkedList : public DbLinkedListInterface<T>
{

public:
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

private:
    Node *Head;

public:
    clsDbLinkedList()
    {
        this->Head = nullptr;
    };

    // Insert At The Beginning
    void InsertAtTheBeginning(T Value) override
    {
        Node *NNode = new Node(Value); // create new node
        NNode->Prev = nullptr;         // as it will be the first node

        if (this->Head != nullptr) // there is next node
        {
            NNode->Next = Head;
            this->Head = NNode;
            return;
        };
        NNode->Next = nullptr;
        this->Head = NNode;
    };

    void PrintList() override
    {
        Node *Temp = this->Head;

        while (Temp != nullptr)
        {
            std::cout << Temp->Value << std::endl;
            Temp = Temp->Next; // move to the next node
       