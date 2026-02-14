#include <queue>
#include <iostream>
using namespace std;

void Print(queue<int> Q)
{
    while (!Q.empty())
    {
        cout << Q.front() << endl;
        Q.pop();
    }
}
int main()
{
    queue<int> Q;
    Q.push(10);
    Q.push(20);
    Q.push(30);

    Print(Q);

    cout << "\nAfter Pop \n";
    Q.pop();
    Print(Q);

    cout << "\nThe Front Element: " << Q.front() << endl;
    cout << "The Back/Read Element: " << Q.back() << endl;

    cout<<"Num OF Element: "<<Q.size()<<endl; 
};