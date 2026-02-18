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
    std::stack<std::string> S;
    std::string str;

public:
    ActiveCallStackSimulation()
    {
        this->str = "";
    };

    // Set
    void SetStringValue(string Value)
    {
        this->str = Value;
        S.push(Value);
    };

    // Get
    string GetString() const
    {
        return this->str;
    };

    
};