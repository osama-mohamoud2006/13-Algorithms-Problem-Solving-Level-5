
template <class T>
class InterfaceclsDynamicArray
{
public:
    virtual bool SetItem(int Index, T Value) = 0;
    virtual bool IsEmpty() = 0;
    virtual int ArraySize() = 0;
    virtual void PrintArrayItems() = 0;
};

template <class T>
class clsDynamicArray : public InterfaceclsDynamicArray<T>
{
protected:
    int _Length = 0;

public:
    T *ArrPtr = nullptr_t;          // Pointer To Allocate Memory
    clsDynamicArray(int Length = 0) // Constructor
    {
        if (0 >= Length)
            return;
        this->_Length = Length;
        ArrPtr = new T[Length]; // Dynamic Array
    };

    bool SetItem(int Index, T Value) override
    {
        if (Index >= this->_Length || 0 > Index)
            return false;
            
        *(ArrPtr + Index) = Value;
        return true; 
    };

    bool IsEmpty() override
    {
        return (this->_Length==0);
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

    ~clsDynamicArray()
    {
        delete ArrPtr[];
    };
};