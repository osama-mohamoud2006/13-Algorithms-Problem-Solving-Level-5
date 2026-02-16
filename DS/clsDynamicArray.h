
template <class T>
class InterfaceclsDynamicArray
{
public:
    virtual void SetItem(int Index, T Value) = 0;
    virtual bool IsEmpty() = 0;
    int ArraySize() = 0;
    void PrintArrayItems() = 0;
};

template <class T>
class clsDynamicArray
{
    T *ArrPtr; // Pointer To Allocate Memory
    int _Length;

public:
    clsDynamicArray(int Length) // Constructor
    {
        _Length = Length;
        ArrPtr = new T[Length]; // Dynamic Array
    };

    void SetItem(int Index, T Value) override
    {
        *(ArrPtr + Index) = Value;
    };

    bool IsEmpty() override
    {
        for (int i = 0; i < this->_Length; i++)
        {
            *(this->ArrPtr + i) ;
        }
    };

    int ArraySize() override
    {
        return this->_Length - 1;
    };

    void PrintArrayItems() override
    {
        for (int i = 0; i < this->_Length; i++)
        {
            cout << *(this->ArrPtr + i) << " ";
        }
    };
};