#include <stack>
#include <string>

class Interface
{
public:
    virtual void Redo() = 0;
    virtual void Undo() = 0;
};

class ActiveCallStackSimulation : public Interface
{
private:
    std::stack<std::string> Stack;
    std::stack<std::string> ReStack;
    std::string str;

public:
    ActiveCallStackSimulation()
    {
        this->str = " ";
        Stack.push(" ");
    };

    // Set
    void SetValue(std::string Value)
    {
        if (Value == "")
            return;
        this->str = Value;
        Stack.push(Value);
    };

    // Get

    std::string GetValue() const
    {
        return this->str;
    };

    void Undo() override
    {
        if (Stack.empty() || this->str == "")
        {
            this->str = "";
            return;
        };
        ReStack.push(str); // push the element to another stack before removing it
        Stack.pop();       // remove the last action
        this->str = Stack.top();
    };

    void Redo() override
    {
        if (ReStack.empty())
        {
            return;
        };
        
        Stack.push(ReStack.top());
        str = ReStack.top();
        ReStack.pop(); // remove the last element as it returned to another stack
    };
};