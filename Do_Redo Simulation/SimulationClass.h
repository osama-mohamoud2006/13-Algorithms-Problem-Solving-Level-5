#pragma once
#include <stack>

class Interface
{
public:
    virtual void Redo() = 0;
    virtual void Undo() = 0;
};

template <class T>
class ActiveCallStackSimulation : public Interface
{
private:
    std::stack<T> _UndoStack;
    std::stack<T> _ReDoStack;
    T _Value;

public:
    ActiveCallStackSimulation()
    {
        this->_Value = " ";
    };

    // Set
    void SetValue(T Value)
    {
        _UndoStack.push(_Value); // take the old value at first 
        this->_Value = Value;
    };

    // Get

    T GetValue() const
    {
        return this->_Value;
    };

    void Undo() override   
    {
        if (!_UndoStack.empty())
        {
            _ReDoStack.push(_Value); // push the element to another stack before removing it
            this->_Value = _UndoStack.top(); // as stack have the prev value 
            _UndoStack.pop(); // remove the last action
        };
    };

    void Redo() override
    {
        if (!_ReDoStack.empty())
        {
            _UndoStack.push(_ReDoStack.top());
            _Value = _ReDoStack.top();
            _ReDoStack.pop(); // remove the last element as it returned to another stack
        }
        else
        {
            this->_Value = T();
        }
    };
};