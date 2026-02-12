#include "../DS/clsDbLinkedList.h"
#include <iostream>
using namespace std;

void TestInsertAtBeginning()
{
    cout << "======== Test InsertAtTheBeginning ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheBeginning(10);
    Db1.InsertAtTheBeginning(20);
    Db1.InsertAtTheBeginning(30);
    Db1.InsertAtTheBeginning(40);
    cout << "Expected: 40 30 20 10\nActual:\n";
    Db1.PrintList();
    cout << "\n";
}

void TestInsertAtEnd()
{
    cout << "======== Test InsertAtTheEnd ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(10);
    Db1.InsertAtTheEnd(20);
    Db1.InsertAtTheEnd(30);
    Db1.InsertAtTheEnd(40);
    cout << "Expected: 10 20 30 40\nActual:\n";
    Db1.PrintList();
    cout << "\n";
}

void TestFind()
{
    cout << "======== Test Find ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(10);
    Db1.InsertAtTheEnd(20);
    Db1.InsertAtTheEnd(30);

    clsDbLinkedList<int>::Node *N1 = Db1.Find(20);
    if (N1 != nullptr && N1->Value == 20)
        cout << "Found node with value 20: SUCCESS\n";
    else
        cout << "Find failed: FAILED\n";

    clsDbLinkedList<int>::Node *N2 = Db1.Find(99);
    if (N2 == nullptr)
        cout << "Find non-existent value returns nullptr: SUCCESS\n";
    else
        cout << "Find non-existent: FAILED\n";
    cout << "\n";
}

void TestInsertAfter()
{
    cout << "======== Test InsertAfter ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(10);
    Db1.InsertAtTheEnd(20);
    Db1.InsertAtTheEnd(30);

    clsDbLinkedList<int>::Node *N1 = Db1.Find(20);
    Db1.InsertAfter(N1, 25);
    cout << "Expected: 10 20 25 30\nActual:\n";
    Db1.PrintList();
    cout << "\n";
}

void TestDeleteFirstNode()
{
    cout << "======== Test DeleteTheFirstNode ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(10);
    Db1.InsertAtTheEnd(20);
    Db1.InsertAtTheEnd(30);
    Db1.DeleteTheFirstNode();
    cout << "Expected: 20 30\nActual:\n";
    Db1.PrintList();
    cout << "\n";
}

void TestDeleteLastNode()
{
    cout << "======== Test DeleteTheLastNode ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(10);
    Db1.InsertAtTheEnd(20);
    Db1.InsertAtTheEnd(30);
    Db1.DeleteTheLastNode();
    cout << "Expected: 10 20\nActual:\n";
    Db1.PrintList();
    cout << "\n";
}

void TestDeleteNode()
{
    cout << "======== Test DeleteNode ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(10);
    Db1.InsertAtTheEnd(20);
    Db1.InsertAtTheEnd(30);
    clsDbLinkedList<int>::Node *N1 = Db1.Find(20);
    Db1.DeleteNode(N1);
    cout << "Expected: 10 30\nActual:\n";
    Db1.PrintList();
    cout << "\n";
}

void TestEmptyList()
{
    cout << "======== Test Empty List ========\n";
    clsDbLinkedList<int> Db1;
    cout << "Expected: NULL\nActual: ";
    Db1.PrintList();
    cout << "\n";
}

int main()
{
    cout << "\n######## DOUBLY LINKED LIST TEST SUITE ########\n\n";

    TestEmptyList();
    TestInsertAtBeginning();
    TestInsertAtEnd();
    TestFind();
    TestInsertAfter();
    TestDeleteFirstNode();
    TestDeleteLastNode();
    TestDeleteNode();

    cout << "######## ALL TESTS COMPLETED ########\n";
    return 0;
};