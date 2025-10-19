/*
* Name: Andres Valencia Cardenas
* Course: Cpts 223, Fall 2025
* Assignment: PA3
* Descsciption: Header file for product class, includes class declaration. 
* Date: 10/16/2025
*/
#pragma once
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
            uniqueId_ = ""; 
        }
        Product(const string& name, const string& uniqueId) : name_(name), uniqueId_(uniqueId) {} 
        ~Product() {}

        //getters 
        const string& GetName() const 
        { 
            return name_; 
        }
        const string& GetUniqueId() const { return uniqueId_; }

        //setters
        void SetName(const string& name) { name_ = name; }
        void SetUniqueId(const string& uniqueId) { uniqueId_ = uniqueId; }

    private: 
    
        //class attributes
        string name_; 
        string uniqueId_; 
};

