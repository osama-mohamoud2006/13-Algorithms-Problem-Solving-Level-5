#include "../Do_Redo Simulation/SimulationClass.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ActiveCallStackSimulation<string> S;
    cout << "First Value: " << S.GetValue() << endl;

    S.SetValue("Hamed");
    cout << "Second Value: " << S.GetValue() << endl;

    S.SetValue("Mai");
    cout << "Third Value: " << S.GetValue() << endl;

    S.SetValue("Lana");
    cout << "Forth Value: " << S.GetValue() << endl;

    S.SetValue("Jana");
    cout << "Fifth Value: " << S.GetValue() << endl;




    cout << "\n\n\nAfter Undoing\n";

    S.Undo();
    cout << "First Value: " << S.GetValue() << endl;

    S.Undo();
    cout << "Second Value: " << S.GetValue() << endl;

    S.Undo();
    cout << "Third Value: " << S.GetValue() << endl;

    S.Undo();
    cout << "Forth Value: " << S.GetValue() << endl;







    cout << "\nRedo\n";
    S.Redo();

    cout << " Value: " << S.GetValue() << endl; // 1

    S.Redo();

    cout << " Value: " << S.GetValue() << endl; // 2

    S.Redo();

    cout << " Value: " << S.GetValue() << endl; // 3

    S.Redo();

    cout << " Value: " << S.GetValue() << endl; // 4

    S.Redo();

    cout << " Value: " << S.GetValue() << endl; // garbage

    
    S.Redo();

    cout << " Value: " << S.GetValue() << endl; // garbage
    
    S.Redo();

    cout << " Value: " << S.GetValue() << endl; // garbage
    S.Redo();

    cout << " Value: " << S.GetValue() << endl; // garbage
};