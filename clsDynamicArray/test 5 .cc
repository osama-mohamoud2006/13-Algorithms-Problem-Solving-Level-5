#include <iostream>
#include "clsDynamicArray.h"
using namespace std;

int main()
{
    clsDynamicArray<short> D(5);
    D.SetItem(0, 10);
    D.SetItem(1, 20);
    D.SetItem(2, 30);
    D.SetItem(3, 40);
    D.SetItem(4, 50);

    cout << "is empty? " << D.IsEmpty() << endl;
    cout << "The Array Size Is: " << D.ArraySize() << endl;

    cout << "\nArray Elements Are: \n";
    D.PrintArrayItems();

    // cout << "\n\nResizing\n";
    // D.Resize(1);
    // cout << "The Array Size2 Is: " << D.ArraySize() << endl;
    // cout << "\nArray Elements2 Are: \n";
    // D.PrintArrayItems();

    // cout << "\n\nExtension 1\n";
    // cout << "Item in Index[0]: " << D.GetItem(0) << endl;

    // cout << "\nAfter Reversing:\n";
    // D.Reverse();
    // D.PrintArrayItems();

    // cout << "\nAfter Clear:\n";
    // D.Clear();
    // D.PrintArrayItems();

    // D.DeleteItemAt(2);
    // cout << "\n";
    // D.PrintArrayItems();

    // cout << "\nDelete First Item\n";
    // D.DeleteFirstItem();
    // D.PrintArrayItems();

    // cout << "\nDelete Last Item\n";
    // D.DeleteLastItem();
    // D.PrintArrayItems();

    // int Index = D.Find(20);
    // if (Index != -1)
    // {
    //     cout << "\nFound!\n";
    // }

    // cout << "\nAfter Deleting\n";
    // cout<<D.DeleteItem(20)<<endl;
    // D.PrintArrayItems();

    cout << "\nBefore Inserting At Index[2]\n";
    D.PrintArrayItems();

    cout << "\nAfter Inserting At Index[2]\n";
    D.InsertAt(2, -11);
    D.PrintArrayItems();

    cout << "\nInsert At The Start\n";
    D.InsertAtBeginning(-90);
    D.PrintArrayItems();

    cout << "\nInsert At The End\n";
    D.InsertAtTheEnd(1200);
    D.PrintArrayItems();

    cout << "\nInsert Before Index[2]\n";
    D.InsertBefore(2, 18);
    D.PrintArrayItems();

    cout << "\nInsert After[2]\n";
    D.InsertAfter(2, 90);
    D.PrintArrayItems();
}