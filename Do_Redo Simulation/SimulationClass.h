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
    std::stack<std::string> _UndoStack;
    std::stack<std::string> _ReDoStack;
    std::string _Value;

public:
    ActiveCallStackSimulation()
    {
        this->_Value = " ";
        _UndoStack.push(" ");
    };

    // Set
    void SetValue(std::string Value)
    {
        if (Value == "")
        {
            return;
        };
        _UndoStack.push(_Value);
        this->_Value = Value;
    };

    // Get

    std::string GetValue() const
    {
        return this->_Value;
    };

    void Undo() override
    {
        if (!_UndoStack.empty())
        {
            _ReDoStack.push(_Value); // push the element to another stack before removing it
            this->_Value = _UndoStack.top();
            _UndoStack.pop();             // remove the last action
            
        };
    };

    void Redo() override
    {
        if (!_ReDoStack.empty())
        {
            _UndoStack.push(_ReDoStack.top());
            _Value = _ReDoStack.top();
            _ReDoStack.pop(); // remove the last element as it returned to another stack
        };
    };
};