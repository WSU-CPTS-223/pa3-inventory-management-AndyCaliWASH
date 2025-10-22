/*
* Name: Andres Valencia Cardenas
* Course: Cpts 223, Fall 2025
* Assignment: PA3
* Descsciption: Header file for product class, includes class declaration. 
* Date: 10/16/2025
*/
#pragma once
#include "Vector.h" // for Vector
#include <iostream> // for cout and cin 
#include <string> // for string and string functions
using namespace std; 

//Product class declaration 
class Product 
{
    public: 
        //constructors 
        Product() 
        {
            name_ = ""; 
        }
        Product(const string& name) : name_(name) {} 
        ~Product() {}

        //getters 
        const string& GetName() const 
        { 
            return name_; 
        }
        const Vector<string>& GetCategories() const
        {
            return categories_; 
        }

        //setters
        void SetName(const string& name) { name_ = name; }
        void setCategories(const Vector<string>& categories) { categories_ = categories; }

    private: 
    
        //class attributes
        string name_; 
        Vector<string> categories_; 
};

