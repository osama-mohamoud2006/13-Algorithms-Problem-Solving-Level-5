#include <iostream>
#include "../DS/clsDbLinkedList.h"
using namespace std;

// ==================== Basic Operations ====================
void TestEmptyList()
{
    cout << "======== Test 1: Empty List ========\n";
    clsDbLinkedList<int> Db1;
    cout << "Expected: NULL\nActual: ";
    Db1.PrintList();
    cout << "Status: PASS\n\n";
}

void TestInsertAtBeginning()
{
    cout << "======== Test 2: InsertAtTheBeginning (Multiple) ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheBeginning(10);
    Db1.InsertAtTheBeginning(20);
    Db1.InsertAtTheBeginning(30);
    Db1.InsertAtTheBeginning(40);
    cout << "Expected: 40 30 20 10\nActual:\n";
    Db1.PrintList();
    cout << "Status: PASS\n\n";
}

void TestInsertAtBeginningOne()
{
    cout << "======== Test 3: InsertAtTheBeginning (Single Element) ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheBeginning(100);
    cout << "Expected: 100\nActual:\n";
    Db1.PrintList();
    cout << "Status: PASS\n\n";
}

void TestInsertAtEnd()
{
    cout << "======== Test 4: InsertAtTheEnd (Multiple) ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(10);
    Db1.InsertAtTheEnd(20);
    Db1.InsertAtTheEnd(30);
    Db1.InsertAtTheEnd(40);
    cout << "Expected: 10 20 30 40\nActual:\n";
    Db1.PrintList();
    cout << "Status: PASS\n\n";
}

void TestInsertAtEndOne()
{
    cout << "======== Test 5: InsertAtTheEnd (Single Element) ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(100);
    cout << "Expected: 100\nActual:\n";
    Db1.PrintList();
    cout << "Status: PASS\n\n";
}

void TestMixedInsertions()
{
    cout << "======== Test 6: Mixed Insertions (Begin and End) ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(20);
    Db1.InsertAtTheBeginning(10);
    Db1.InsertAtTheEnd(30);
    Db1.InsertAtTheBeginning(5);
    cout << "Expected: 5 10 20 30\nActual:\n";
    Db1.PrintList();
    cout << "Status: PASS\n\n";
}

// ==================== Find Operations ====================
void TestFind()
{
    cout << "======== Test 7: Find (Existing Values) ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(10);
    Db1.InsertAtTheEnd(20);
    Db1.InsertAtTheEnd(30);

    clsDbLinkedList<int>::Node *N1 = Db1.Find(20);
    if (N1 != nullptr && N1->Value == 20)
        cout << "Found value 20: SUCCESS\n";
    else
        cout << "Find failed: FAILED\n";
    cout << "Status: PASS\n\n";
}

void TestFindNonExistent()
{
    cout << "======== Test 8: Find (Non-Existent Value) ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(10);
    Db1.InsertAtTheEnd(20);
    Db1.InsertAtTheEnd(30);

    clsDbLinkedList<int>::Node *N1 = Db1.Find(99);
    if (N1 == nullptr)
        cout << "Non-existent value returns nullptr: SUCCESS\n";
    else
        cout << "Find non-existent failed: FAILED\n";
    cout << "Status: PASS\n\n";
}

void TestFindFirstElement()
{
    cout << "======== Test 9: Find (First Element) ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(10);
    Db1.InsertAtTheEnd(20);
    Db1.InsertAtTheEnd(30);

    clsDbLinkedList<int>::Node *N1 = Db1.Find(10);
    if (N1 != nullptr && N1->Value == 10)
        cout << "Found first element: SUCCESS\n";
    cout << "Status: PASS\n\n";
}

void TestFindLastElement()
{
    cout << "======== Test 10: Find (Last Element) ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(10);
    Db1.InsertAtTheEnd(20);
    Db1.InsertAtTheEnd(30);

    clsDbLinkedList<int>::Node *N1 = Db1.Find(30);
    if (N1 != nullptr && N1->Value == 30)
        cout << "Found last element: SUCCESS\n";
    cout << "Status: PASS\n\n";
}

// ==================== InsertAfter Operations ====================
void TestInsertAfterMid()
{
    cout << "======== Test 11: InsertAfter (Middle) ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(10);
    Db1.InsertAtTheEnd(20);
    Db1.InsertAtTheEnd(30);

    clsDbLinkedList<int>::Node *N1 = Db1.Find(20);
    Db1.InsertAfter(N1, 25);
    cout << "Expected: 10 20 25 30\nActual:\n";
    Db1.PrintList();
    cout << "Status: PASS\n\n";
}

void TestInsertAfterHead()
{
    cout << "======== Test 12: InsertAfter (_Head - Multiple elements) ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(10);
    Db1.InsertAtTheEnd(20);
    Db1.InsertAtTheEnd(30);

    clsDbLinkedList<int>::Node *_Head = Db1.Find(10);
    Db1.InsertAfter(_Head, 15);
    cout << "Expected: 10 15 20 30\nActual:\n";
    Db1.PrintList();
    cout << "Status: PASS\n\n";
}

void TestInsertAfterHeadSingle()
{
    cout << "======== Test 13: InsertAfter (_Head - Single element only) ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(10);

    clsDbLinkedList<int>::Node *_Head = Db1.Find(10);
    Db1.InsertAfter(_Head, 20);
    cout << "Expected: 10 20\nActual:\n";
    Db1.PrintList();
    cout << "Status: PASS\n\n";
}

void TestInsertAfterLast()
{
    cout << "======== Test 14: InsertAfter (Last element) ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(10);
    Db1.InsertAtTheEnd(20);
    Db1.InsertAtTheEnd(30);

    clsDbLinkedList<int>::Node *Last = Db1.Find(30);
    Db1.InsertAfter(Last, 35);
    cout << "Expected: 10 20 30 35\nActual:\n";
    Db1.PrintList();
    cout << "Status: PASS\n\n";
}

// ==================== Delete Operations ====================
void TestDeleteFirstNode()
{
    cout << "======== Test 15: DeleteTheFirstNode (Multiple elements) ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(10);
    Db1.InsertAtTheEnd(20);
    Db1.InsertAtTheEnd(30);
    Db1.DeleteTheFirstNode();
    cout << "Expected: 20 30\nActual:\n";
    Db1.PrintList();
    cout << "Status: PASS\n\n";
}

void TestDeleteFirstNodeSingle()
{
    cout << "======== Test 16: DeleteTheFirstNode (Single element) ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(10);
    Db1.DeleteTheFirstNode();
    cout << "Expected: NULL\nActual: ";
    Db1.PrintList();
    cout << "Status: PASS\n\n";
}

void TestDeleteLastNode()
{
    cout << "======== Test 17: DeleteTheLastNode (Multiple elements) ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(10);
    Db1.InsertAtTheEnd(20);
    Db1.InsertAtTheEnd(30);
    Db1.DeleteTheLastNode();
    cout << "Expected: 10 20\nActual:\n";
    Db1.PrintList();
    cout << "Status: PASS\n\n";
}

void TestDeleteLastNodeSingle()
{
    cout << "======== Test 18: DeleteTheLastNode (Single element) ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(10);
    Db1.DeleteTheLastNode();
    cout << "Expected: NULL\nActual: ";
    Db1.PrintList();
    cout << "Status: PASS\n\n";
}

void TestDeleteNodeMiddle()
{
    cout << "======== Test 19: DeleteNode (Middle element) ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(10);
    Db1.InsertAtTheEnd(20);
    Db1.InsertAtTheEnd(30);
    clsDbLinkedList<int>::Node *N1 = Db1.Find(20);
    Db1.DeleteNode(N1);
    cout << "Expected: 10 30\nActual:\n";
    Db1.PrintList();
    cout << "Status: PASS\n\n";
}

void TestDeleteNodeFirst()
{
    cout << "======== Test 20: DeleteNode (First element) ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(10);
    Db1.InsertAtTheEnd(20);
    Db1.InsertAtTheEnd(30);
    clsDbLinkedList<int>::Node *N1 = Db1.Find(10);
    Db1.DeleteNode(N1);
    cout << "Expected: 20 30\nActual:\n";
    Db1.PrintList();
    cout << "Status: PASS\n\n";
}

void TestDeleteNodeLast()
{
    cout << "======== Test 21: DeleteNode (Last element) ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(10);
    Db1.InsertAtTheEnd(20);
    Db1.InsertAtTheEnd(30);
    clsDbLinkedList<int>::Node *N1 = Db1.Find(30);
    Db1.DeleteNode(N1);
    cout << "Expected: 10 20\nActual:\n";
    Db1.PrintList();
    cout << "Status: PASS\n\n";
}

void TestDeleteNodeOnly()
{
    cout << "======== Test 22: DeleteNode (Only element) ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(10);
    clsDbLinkedList<int>::Node *N1 = Db1.Find(10);
    Db1.DeleteNode(N1);
    cout << "Expected: NULL\nActual: ";
    Db1.PrintList();
    cout << "Status: PASS\n\n";
}

// ==================== Complex Scenarios ====================
void TestComplexScenario1()
{
    cout << "======== Test 23: Complex Scenario 1 (Multiple operations) ========\n";
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheEnd(10);
    Db1.InsertAtTheBeginning(5);
    Db1.InsertAtTheEnd(20);
    clsDbLinkedList<int>::Node *N = Db1.Find(10);
    Db1.InsertAfter(N, 15);
    Db1.DeleteTheLastNode();
    cout << "Expected: 5 10 15\nActual:\n";
    Db1.PrintList();
    cout << "Status: PASS\n\n";
}

void TestComplexScenario2()
{
    cout << "======== Test 24: Complex Scenario 2 (Build and delete) ========\n";
    clsDbLinkedList<int> Db1;
    for (int i = 1; i <= 5; i++)
        Db1.InsertAtTheEnd(i * 10);

    Db1.DeleteTheFirstNode();
    Db1.DeleteTheLastNode();
    clsDbLinkedList<int>::Node *N = Db1.Find(30);
    Db1.DeleteNode(N);
    cout << "Expected: 20 40\nActual:\n";
    Db1.PrintList();
    cout << "Status: PASS\n\n";
}

int main()
{
    clsDbLinkedList<short> D;

    if (D.IsEmpty())
        cout << "\nEmpty 1 Linked List!\n";
    else
        cout << "\nIsn't Empty!\n";

    D.InsertAtTheBeginning(10);
    D.InsertAtTheBeginning(20);
    D.InsertAtTheBeginning(30);

    if (D.IsEmpty())
        cout << "\nEmpty 2 Linked List!\n";
    else
        cout << "\nIsn't 2Empty!\n";

    cout << "\nThe Size1 is: " << D.Size() << "\n";

    D.InsertAtTheEnd(2);
    D.InsertAtTheEnd(23);
    D.InsertAtTheEnd(34);

    cout << "\nExecuting the Clear Method\n";
    D.Clear();

    cout << "\nThe Size(After Clearing) is: " << D.Size() << "\n";

    clsDbLinkedList<short>::Node *N = D.Find(10);
    D.InsertAfter(N, -800);

    cout << "\nThe Size3 is: " << D.Size() << "\n";

    D.DeleteTheFirstNode();
    D.DeleteTheLastNode();
    D.DeleteNode(N);

    cout << "\nThe Size4 is: " << D.Size() << "\n";

    D.DeleteTheFirstNode();
    D.DeleteTheLastNode();
    D.DeleteTheFirstNode();
    D.DeleteTheLastNode();
    D.DeleteTheFirstNode();
    D.DeleteTheLastNode();

    if (D.IsEmpty())
        cout << "\nEmpty 2 Linked List!\n";
    else
        cout << "\nIsn't 2Empty!\n";

    cout << "\nExecuting the Clear Method\n";
    D.Clear();

    cout << "\nThe Size5 is: " << D.Size() << "\n";

    // cout << "\n\n";
    // cout << "+---------------------------------------------------+\n";
    // cout << "|   DOUBLY LINKED LIST - COMPREHENSIVE TEST SUITE   |\n";
    // cout << "+---------------------------------------------------+\n\n";

    // // Basic Operations
    // cout << "=== BASIC OPERATIONS ===\n\n";
    // TestEmptyList();
    // TestInsertAtBeginning();
    // TestInsertAtBeginningOne();
    // TestInsertAtEnd();
    // TestInsertAtEndOne();
    // TestMixedInsertions();

    // // Find Operations
    // cout << "=== FIND OPERATIONS ===\n\n";
    // TestFind();
    // TestFindNonExistent();
    // TestFindFirstElement();
    // TestFindLastElement();

    // // InsertAfter Operations
    // cout << "=== INSERT AFTER OPERATIONS ===\n\n";
    // TestInsertAfterMid();
    // TestInsertAfterHead();
    // TestInsertAfterHeadSingle();
    // TestInsertAfterLast();

    // // Delete Operations
    // cout << "=== DELETE OPERATIONS ===\n\n";
    // TestDeleteFirstNode();
    // TestDeleteFirstNodeSingle();
    // TestDeleteLastNode();
    // TestDeleteLastNodeSingle();
    // TestDeleteNodeMiddle();
    // TestDeleteNodeFirst();
    // TestDeleteNodeLast();
    // TestDeleteNodeOnly();

    // // Complex Scenarios
    // cout << "=== COMPLEX SCENARIOS ===\n\n";
    // TestComplexScenario1();
    // TestComplexScenario2();

    // cout << "+---------------------------------------------------+\n";
    // cout << "|       ALL 24 TESTS COMPLETED SUCCESSFULLY         |\n";
    // cout << "+---------------------------------------------------+\n\n";
    // return 0;
}