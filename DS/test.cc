#include "../DS/clsDbLinkedList.h"
using namespace std;

int main()
{
    clsDbLinkedList<int> Db1;

    // Db1.InsertAtTheBeginning(10);
    // Db1.InsertAtTheBeginning(20);
    // Db1.InsertAtTheBeginning(30);
    // Db1.InsertAtTheBeginning(40);

    Db1.InsertAtTheEnd(10);
    Db1.InsertAtTheEnd(20);
    Db1.InsertAtTheEnd(30);
    Db1.InsertAtTheEnd(40);
    Db1.InsertAtTheEnd(50);

    Db1.DeleteTheFirstNode();
    Db1.DeleteTheLastNode();

    Db1.PrintList();

    clsDbLinkedList<int>::Node *N1 = Db1.Find(20);

    if (N1 != nullptr)
        cout << "\nN1 Found!\n";
    else
        cout << "\nDidn't Find\n";

    cout << N1->Value << endl;
};