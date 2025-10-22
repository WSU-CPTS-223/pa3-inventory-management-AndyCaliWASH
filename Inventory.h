/*
* Name: Andres Valencia Cardenas
* Course: Cpts 223, Fall 2025
* Assignment: PA3
* Description: Header file for inventory class, includes class declaration.
* Date: 10/18/2025
*/ 
#pragma once
#include "Map.h" //for Map class
#include "Product.h" // for Product class
#include <fstream> // for file operations 
#include <sstream> // for stringstream
#include <algorithm> // for findif()

//Inventory class declaration
class Inventory
{
    public: 
        //constructors
        Inventory();
        ~Inventory(); 

        //Class methods

        /*
        * @param: none
        * returns: none
        * parses the input file
        */
        void Parse(); 

        /*
        * @param: a string for searching the inventory
        * returns: none
        * finds the given string in the inventory
        */
        void Find(const string& inventoryId);

        /*
        * @param: a string, which is the category being searched for
        * returns: none
        * searches for the given category and prints every item that falls under that category
        */
        void ListInventory(const string& category);
        
        /*
        * @param: a string 
        * returns: none
        * trims the space characters from the left side of the string
        */
        void ltrim(string& s);

        /*
        * @param: a string
        * returns: none
        * trims the space characters from the right side of the string
        */
        void rtrim(string& s);

        /*
        * @param: a string
        * returns: none
        * trims the space characters from both sides of a string
        */
        void trim(string& s);
    
    private: 
        //class attributes
        MyMap <string, Product> items_;

}; 