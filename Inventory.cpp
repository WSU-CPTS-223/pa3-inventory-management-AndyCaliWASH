/*
* Name: Andres Valencia Cardenas
* Course: Cpts 223, Fall 2025
* Assignment: PA3
* Description: .cpp file for inventory class, includes function definitions.
* Date: 10/18/2025
*/ 

#include "Inventory.h"

void Inventory::Parse()
{
    ifstream file; 
    string line; 
    Array<string> categories; 
    file.open("inventory.csv");
    if (!file.is_open())
    {
        cerr << "Error opening file" << endl;
        return; 
    }
    getline(file, line); // skip header line
    while(getline(file, line))
    {
        stringstream ss(line); 
        string name, category, uniqueId, buffer, cat; 
        
        getline(ss, uniqueId, ',');
        getline(ss, name, ','); 
        getline(ss, buffer, ','); 
        getline(ss, buffer, ','); 
        getline(ss, category, ','); 
        if (category == "")
        {
            categories.PushBack("NA"); 
        }

        stringstream sa(category);  
        while(getline(sa, cat, '|')) 
        {
            categories.PushBack(cat);
        }

        Product product(name, uniqueId); 
        items_.Insert(categories, product); 
    }
    file.close(); 

}

void Inventory::Find(const string& inventoryId)
{
    for (auto it = items_.begin(); !(it == items_.end()); ++it)
    {
        const auto& entry = *it;
        if (entry.second.uniqueId_ == inventoryId)
        {
            cout << "Product Found: " << endl; 
            cout << "Name: " << entry.second.name_ << endl; 
            cout << "Unique ID: " << entry.second.uniqueId_ << endl;
            cout << "Categories: " << endl; 
            for (const auto& category : entry.first) 
            {
                cout << "> " << category << endl;  
            }
            return; 
        }
    }
    cout << "Product Not Found" << endl;
}

void Inventory::ListInventory(const string& category)
{

}