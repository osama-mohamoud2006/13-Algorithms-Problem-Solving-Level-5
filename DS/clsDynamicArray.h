#include <iostream>
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
    virtual bool DeleteItemAt(int Index) = 0;
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
            std::cout << this->ArrPtr[i] << " ";
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
        if (0 > index || _Length <= index)
        {
            return T();
        }
        else
            return ArrPtr[index];
    };

    void Clear() override
    {
        if (ArrPtr != nullptr)
        {
            delete[] ArrPtr;
            ArrPtr = nullptr;
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

private:
    bool CheckIndex(int Index)
    {
        if (Index < 0 || Index >= _Length)
            return false;
        else
            return true;
    }

public:
    bool DeleteItemAt(int Index) override
    {
        // if (Index >= _Length || 0>Index)
        //     return;
        // int c = 0;
        // T *Temp = new T[c];
        // for (int i = 0; i < _Length; i++)
        // {
        //     if (i != Index)
        //     {

        //         Temp[c] = ArrPtr[i];
        //         c++;
        //     }
        // };
        // delete[] ArrPtr;
        // ArrPtr = Temp;
        // _Length--;

        if (!CheckIndex(Index))
        {
            return false;
        };

        _Length--; // decrement length as we delete an item
        T *Temp = new T[_Length];
        // Copy All Element To New Array Before The Index You Wanna To Delete
        for (int i = 0; i < Index; i++)
        {
            Temp[i] = ArrPtr[i];
        };

        // Fill Elements After That Index
        for (int i = Index + 1; i < _Length + 1; i++)
        {
            Temp[i - 1] = ArrPtr[i];
        };
        delete[] ArrPtr;
        ArrPtr = Temp;
        return true;
    };

    bool DeleteFirstItem()
    {
        return DeleteItemAt(0);
    };

    bool DeleteLastItem()
    {
        return DeleteItemAt(_Length - 1);
    }

    int Find(T Element)
    {
        for (int i = 0; i < _Length; i++)
        {
            if (ArrPtr[i] == Element) // return the index
                return i;
        }
        return -1;
    };

    bool DeleteItem(T Element)
    {
        int Index = Find(Element);
        if (Index == -1)
        {
            return false;
        };

        return DeleteItemAt(Index);
    };

    bool InsertAt(int Index, T Value)
    {
        if (Index < 0 || Index > _Length)
        {
            return false;
        };

        TempPtr = new T[_Length+1];
        // Copy All Elements Before Index
        for (int i = 0; i < Index; i++)
        {
            TempPtr[i] = ArrPtr[i];
        };
        TempPtr[Index] = Value; // assign value in the index that you want to insert at

        for (int i = Index + 1; i < _Length + 1; i++)
        {
            TempPtr[i] = ArrPtr[i - 1];
        };

        delete[] ArrPtr;
        ArrPtr = TempPtr;
        _Length++;
        return true;
    };

    bool InsertAtBeginning(T Value)
    {
        return InsertAt(0, Value);
    };

    bool InsertAtTheEnd(T Value)
    {
        if(_Length<1) 
        {
            return InsertAt(0, Value);
        };
        //bool Res = 
        // if (Res) // if the insertion done
        // {
        //     Swap(ArrPtr[_Length - 1], ArrPtr[_Length - 2]);
        // };
        return InsertAt(_Length , Value);;
    };

    bool InsertBefore(int Index, T Value)
    {
        if (Index < 1) // to avoid inserting at -index
        {
            return InsertAt(0, Value);
        }

        else
        {
            return InsertAt(Index - 1, Value);
        };
    };

    bool InsertAfter(int Index, T Value)
    {
        if (Index >= _Length) // if we inserted element that larger than size then insert at the end instead
            return InsertAt(_Length - 1, Value);

        else
            return InsertAt(Index + 1, Value);
    };

    ~clsDynamicArray()
    {
        delete[] ArrPtr;
        // if(TempPtr!=nullptr)delete[] TempPtr;
    };
};