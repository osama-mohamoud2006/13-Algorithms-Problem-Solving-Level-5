
template <class T>
class InterfaceclsDynamicArray
{
public:
    virtual bool SetItem(int Index, T Value) = 0;
    virtual bool IsEmpty() = 0;
    virtual int ArraySize() = 0;
    virtual void PrintArrayItems() = 0;
    virtual void Resize(int Size) = 0;
    virtual T GetItem(int index) = 0;
    virtual void Clear() = 0;
    virtual void Reverse() = 0;
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
    void Swap(T &a, T &b)
    {
        T Temp = a;
        a = b;
        b = Temp;
    };

public:
    void Resize(int size) override
    {
        if (this->_Length == size)
        {
            return;
        };
        if (size < 0)
        {
            size = 0;
        };

        if (this->_Length > size) // shrinking the array(if the og array is larger than the new array )
        {
            _Length = size;
        };

        CopyArr(this->ArrPtr, size);
        delete[] ArrPtr;
        this->ArrPtr = this->TempPtr; // pointer points to the new array
        this->_Length = size;         // if size > length
    };

    T GetItem(int index) override
    {
        if (0 > index)
            return T();

        return ArrPtr[index];
    };

    void Clear() override
    {
        if (ArrPtr != nullptr)
        {
            T *Temp = new T[0];
            delete[] ArrPtr;
            ArrPtr = Temp;
        };
        _Length = 0;
    };

    void Reverse() override
    {
        if (_Length == 1 || _Length <= 0)
            return;

        for (int i = 0; i < _Length / 2; i++)
        {
            Swap(ArrPtr[i], ArrPtr[_Length - 1 - i]);
        };
    }

    ~clsDynamicArray()
    {
        delete[] ArrPtr;
        delete[] TempPtr;
    };
};