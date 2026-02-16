#include <iostream>
#include "../DS/clsDynamicArray.h"
using namespace std;

int main()
{
    clsDynamicArray<short> D(5);
    D.SetItem(0, 10);
    D.SetItem(0, 20);
    D.SetItem(0, 30);
    D.SetItem(0, 40);
    D.SetItem(0, 50);

    cout << "is empty? " << D.IsEmpty() << endl;
    cout << "The Array Size Is: " << D.ArraySize() << endl;

    cout<<"\nArray Elements Are: \n";
    D.PrintArrayItems();
}