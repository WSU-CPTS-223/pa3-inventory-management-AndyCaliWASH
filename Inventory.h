/*
* Name: Andres Valencia Cardenas
* Course: Cpts 223, Fall 2025
* Assignment: PA3
* Description: Header file for inventory class, includes class declaration.
* Date: 10/18/2025
*/ 

#include "Map.h"
#include "Array.h"
#include "Product.h"
#include <fstream> 
#include <sstream>

//Inventory class declaration
class Inventory
{
    public: 
        //constructors
        Inventory(); 
        ~Inventory() = default;

        //Class methods
        void Parse(); 
        void Find(const string& inventoryId);
        void ListInventory(const string& category);
    
    private: 
        //class attributes
        Map<Array<string>, Product> items_;
}; 