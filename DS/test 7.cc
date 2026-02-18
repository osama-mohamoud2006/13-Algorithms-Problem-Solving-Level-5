#include "../DS/clsStackUsingDynamicArray.h"
#include <iostream>
using namespace std;

int main()
{
    clsStack<short> S;
    S.Push(1);
    S.Push(2);
    S.Push(3);
    S.Push(4); // The Last Pushed Element

    cout << "\nThe Size Is: " << S.Size() << "\n";
    cout << "\nThe Top Element: " << S.Top() << "\n";
    S.Print();
}