/*
* Name: Andres Valencia Cardenas
* Course: Cpts 223, Fall 2025
* Assignment: PA3
* Description: Array template class, includes the function declaration and function definitions.
* Date: 10/17/2025
*/
#pragma once
#include <iostream> // for cin and cout
#include <stdexcept> //for exceptions

// Vector class definition 
template <typename T>
class Vector {
private:
    //class attributes
    T* data_;
    size_t capacity_;
    size_t length_;

    //private methods 

    /*
    * @param: a new_capacity of the size_t type 
    * returns: none
    * resizes the array by changing the capacity
    */
    void resize(size_t new_capacity) 
    {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < length_; ++i)
            new_data[i] = data_[i];
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

public:

    //Iterator class definition
    class Iterator {

    private:
        //class attributes
        T* ptr_;

    public:
        //constructor
        Iterator(T* p = nullptr) : ptr_(p) {}

        //operators
        T& operator*() const 
        { 
            return *ptr_; 
        }
        T* operator->() const 
        { 
            return ptr_; 
        }
        Iterator& operator++() 
        { 
            ++ptr_; 
            return *this; 
        }
        Iterator operator++(int) 
        { 
            Iterator temp = *this; 
            ++ptr_; 
            return temp; 
        }
        bool operator==(const Iterator& other) const 
        { 
            return ptr_ == other.ptr; 
        }
        bool operator!=(const Iterator& other) const 
        { 
            return ptr_ != other.ptr_; 
        }
    };

    //Constructors
    Vector() : data_(nullptr), capacity_(0), length_(0) {}

    Vector(size_t n, const T& value = T()) : capacity_(n), length_(n) 
    {
        data_ = new T[capacity_];
        for (size_t i = 0; i < n; ++i)
            data_[i] = value;
    }

    Vector(const Vector& other) : capacity_(other.capacity_), length_(other.length_) 
    {
        data_ = new T[capacity_];
        for (size_t i = 0; i < length_; ++i)
            data_[i] = other.data_[i];
    }

    ~Vector() 
    { 
        delete[] data_; 
    }


    //overloaded operators
    Vector& operator=(const Vector& other) 
    {
        if (this != &other) {
            delete[] data_;
            capacity_ = other.capacity_;
            length_ = other.length_;
            data_ = new T[capacity_];
            for (size_t i = 0; i < length_; ++i)
                data_[i] = other.data_[i];
        }
        return *this;
    }

    T& operator[](size_t index) 
    {
        if (index >= length_)
            throw std::out_of_range("Index out of range");
        return data_[index];
    }

    const T& operator[](size_t index) const 
    {
        if (index >= length_)
            throw std::out_of_range("Index out of range");
        return data_[index];
    }


    //class methods

    /*
    * @param: A value of type T to add to the array
    * returns: none
    * Adds a new item to the array, resizes if necessary
    */
    void PushBack(const T& value) 
    {
        if (length_ == capacity_)
            resize(capacity_ == 0 ? 1 : capacity_ * 2);
        data_[length_++] = value;
    }
     
     /*
    * @param: none
    * returns: none
    * removes the last element of the array if the array is not empty
    */
    void PopBack() 
    {
        if (length_ == 0)
        {
            std::cout << "Index out of range " << std::endl;
        }
        else 
        { 
            --length_;
        }
    }
    
    /*
    * @param: none
    * returns: none
    * clears the array
    */
    void Clear() 
    { 
        length_ = 0; 
    }
    
    /*
    * @param: none
    * returns: size_t object that represents the size of the array
    * returns the size of the array
    */
    size_t Size() const 
    { 
        return length_; 
    }

    
    /*
    * @param: none
    * returns: size_t object that represents the capacity of the array
    * returns the capacity of the array
    */
    size_t Capacity() const 
    { 
        return capacity_; 
    }
    
    /*
    * @param: none
    * returns: boolean that is true if the array is empty, false otherwise
    * determines if the array is empty
    */
    bool Empty() const 
    { 
        return length_ == 0; 
    }

    // Iterators
    Iterator begin() 
    { 
        return Iterator(data_); 
    }
    Iterator end() 
    { 
        return Iterator(data_ + length_); 
    }
    Iterator begin() const 
    { 
        return Iterator(data_); 
    }
    Iterator end() const 
    { 
        return Iterator(data_ + length_); 
    }

    //overloaded operators
    bool operator==(const Vector& other) const 
    {
        if (length_ != other.length_)
            return false;
        for (size_t i = 0; i < length_; ++i)
            if (data_[i] != other.data_[i])
                return false;
        return true;
    }

    bool operator!=(const Vector& other) const 
    {
        return !(*this == other);
    }

    bool operator<(const Vector& other) const 
    {
        size_t min_len = (length_ < other.length_) ? length_ : other.length_;
        for (size_t i = 0; i < min_len; ++i) {
            if (data_[i] < other.data_[i]) return true;
            if (data_[i] > other.data_[i]) return false;
        }
        return length_ < other.length_;
    }

    bool operator>(const Vector& other) const 
    {
        return other < *this;
    }

    bool operator<=(const Vector& other) const 
    {
        return !(other < *this);
    }

    bool operator>=(const Vector& other) const 
    {
        return !(*this < other);
    }
};