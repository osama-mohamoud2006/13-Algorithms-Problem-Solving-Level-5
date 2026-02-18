#include "QueueUsingDynamicArray.h"
#include <iostream>
using namespace std;

int main()
{
    clsQueue<short> Q;
    Q.Push(10);
    Q.Push(20);
    Q.Push(30);
    Q.Push(40);
    Q.Push(50);
    Q.Push(60);

    cout << "The Fist Element: " << Q.Front() << endl;
    cout << "The Last Element: " << Q.Back() << endl;

    Q.Pop();
    cout<<"\nQueue Elements\n";
    Q.Print();
}
