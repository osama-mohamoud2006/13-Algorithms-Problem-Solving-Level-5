
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

protected:
    int _Length = 0;
    T *TempPtr;

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
    void CopyArr(T *Arr1, int size)
    {
        TempPtr = new T[size]; // temp dynamic array to copy elements to it

        for (int i = 0; i < this->_Length; i++) // according to length of og array fill the new array
        {
            TempPtr[i] = Arr1[i]; // copy element by element
        };
    };

public:
    void Resize(int size) override
    {
        if(this->_Length == size) return ;
        if (size < 0)
            size = 0;
        if (this->_Length > size) // shrinking the array(if the og array is larger than the new array )
        {
            _Length = size;
        };

        CopyArr(this->ArrPtr, size);
        delete[] ArrPtr;
        this->ArrPtr = this->TempPtr; // pointer points to the new array
        this->_Length = size;         // if size > length
    };

    ~clsDynamicArray()
    {
        delete[] ArrPtr;
    };
};