#include "../DS/clsDbLinkedList.h"
using namespace std;

int main()
{
    clsDbLinkedList<int> Db1;
    Db1.InsertAtTheBeginning(10);
    Db1.InsertAtTheBeginning(20);
    Db1.InsertAtTheBeginning(30);
    Db1.InsertAtTheBeginning(40);

    Db1.PrintList();
}