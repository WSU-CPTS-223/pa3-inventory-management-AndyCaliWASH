/*
* Name: Andres Valencia Cardenas
* Course: Cpts 223, Fall 2025
* Assignment: PA3
* Description: Array template class, includes the function declaration and function definitions.
* Date: 10/17/2025
*/

template <class T> 
class Array
{

private: 
    T* data_; 
    size_t capacity_; 
    size_t length_; 

    void Resize(size_t newCapacity)
    {
        T* newData = new T[newCapacity]; 
        for (size_t i = 0; i < length_; i++)
        {
            newData[i] = data_[i]; 
        }
        delete[] data_; 
        data_ = newData; 
        capacity_ = newCapacity; 
    }
public: 
    Array(size_t initCapacity = 10) : capacity_(initCapacity), length_(0)
    {
        data_ = new T[capacity_]; 
    }

    ~Array()
    {
        delete[] data_; 
    }

    void PushBack(const T& value)
    {
        if (length == capacity)
        {
            Resize(capacity * 2); 
        }
        data_[length_++] = value; 
    }

    void PopBack() 
    {
        if (length_ == 0)
           throw std::out_of_range("Array is empty"); 
           --length_; 
    }

    T& operator[] (size_t index) {
        if (index >= length_)
            throw std::out_of_range("Index out of range");
        return data_[index];
    }

    const T& operator[](size_t index) const {
        if (index >= length_)
            throw std::out_of_range("Index out of range");
        return data_[index];
    }

    size_t Size() const {
        return length_; 
    }

    size_t CapacitySize() const 
    {
        return capacity_; 
    }

    void Clear()
    {
        length_ = 0; 
    }

    T* begin() 
    {
        return data_; 
    }

    T* end() 
    {
        return data_ + length_; 
    }

    const T* begin () const 
    {
        return data_; 
    }

    const T* end() const 
    {
        return data_ + length_; 
    }
};