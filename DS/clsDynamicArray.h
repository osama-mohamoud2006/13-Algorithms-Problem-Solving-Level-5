
template <class T>
class InterfaceclsDynamicArray
{
public:
    virtual void SetItem(int Index, T Value) = 0;
    virtual bool IsEmpty() = 0;
    virtual int ArraySize() = 0;
   virtual void PrintArrayItems() = 0;
};

template <class T>
class clsDynamicArray : public InterfaceclsDynamicArray<T>
{
    T *ArrPtr; // Pointer To Allocate Memory
    int _Length;
    bool _IsEmpty;

public:
    clsDynamicArray(int Length) // Constructor
    {
        _IsEmpty = true;
        _Length = Length;
        ArrPtr = new T[Length]; // Dynamic Array
    };

    void SetItem(int Index, T Value) override
    {
        _IsEmpty = false;
        *(ArrPtr + Index) = Value;
    };

    bool IsEmpty() override
    {
        return this->_IsEmpty;
    };

    int ArraySize() override
    {
        return this->_Length - 1;
    };

    void PrintArrayItems() override
    {
        for (int i = 0; i < this->_Length; i++)
        {
            std::cout << *(this->ArrPtr + i) << " ";
        }
    };
};