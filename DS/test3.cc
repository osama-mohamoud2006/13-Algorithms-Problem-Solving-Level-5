#include "../DS/clsStack.h"
#include <iostream>
#include <stack>
using namespace std;

void Print(stack<short> S)
{
    while (!S.empty())
    {
        cout << S.top() << " "; // the value of  last pushed element in the stack
        S.pop();
    };
}
int main()
{
    stack<short> S;
    /*


size()	returns the number of elements in the stack

\    */

    S.push(10);
    S.push(20);
    S.push(30);

    cout << "\nThe Element in Stack are: \n";
    Print(S);
    cout << "The SIze Is: " << S.size() << endl;

    S.pop(); // remove the last pushed element
    cout << "\nThe Element in Stack(After Poping) are: \n";
    Print(S);
};
