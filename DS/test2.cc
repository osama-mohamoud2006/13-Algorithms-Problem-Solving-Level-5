#include "../DS/clsQueue.h"
#include <iostream>
using namespace std;

// void Print(queue<int> Q)
// {
//     while (!Q.empty())
//     {
//         cout << Q.front() << endl;
//         Q.pop();
//     }
// }
int main()
{
    // queue<int> Q;
    // Q.push(10);
    // Q.push(20);
    // Q.push(30);

    // Print(Q);

    // cout << "\nAfter Pop \n";
    // Q.pop();
    // Print(Q);

    // cout << "\nThe Front Element: " << Q.front() << endl;
    // cout << "The Back/Read Element: " << Q.back() << endl;

    // cout<<"Num OF Element: "<<Q.size()<<endl;

    clsQueue<short> Q;
    Q.Push(10);
    Q.Push(20);
    Q.Push(30);
    Q.Push(40);

    cout << "\nthe size is: " << Q.Size() << endl;
    cout << "The Front is: " << Q.Front() << endl;
    cout << "The Back is: " << Q.Back() << endl;

    cout << "\nQueue elements are:\n";
    Q.Print();

    Q.Pop();
    cout << "\nQueue elements After Poping The First Element(FIFO) are:\n";
    Q.Print();
    
};