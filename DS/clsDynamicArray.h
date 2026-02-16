
template <class T>
class InterfaceclsDynamicArray
{
public:
    virtual bool SetItem(int Index, T Value) = 0;
    virtual bool IsEmpty() = 0;
    virtual int ArraySize() = 0;
    virtual void PrintArrayItems() = 0;
    virtual void Resize(int Size) = 0;
};

template <class T>
class clsDynamicArray : public InterfaceclsDynamicArray<T>
{
private:
    T *TempPtr = nullptr;

protected:
    int _Length = 0;

public:
    T *ArrPtr = nullptr;            // Pointer To Allocate Memory
    clsDynamicArray(int Length = 0) // Constructor
    {
        if (0 > Length) // negative nums
            this->_Length = 0;

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
        return (this->_Length == 0);
    };

    int ArraySize() override
    {
        return this->_Length;
    };

    void PrintArrayItems() override
    {
        for (int i = 0; i < this->_Length; i++)
        {
            std::cout << *(this->ArrPtr + i) << " ";
        }
    };

private:
    void CopyArr(T Arr1, int size)
    {
        TempPtr = new T[size]; // temp dynamic array to copy elements to it
        for (int i = 0; i < size; i++)
        {
            TempPtr[i] = Arr1[i]; // copy element by element
        };
    };

    void Resize(int size) override 
    {

    };

    ~clsDynamicArray()
    {
        delete[] ArrPtr;
        delete[] TempPtr ;
    };
};