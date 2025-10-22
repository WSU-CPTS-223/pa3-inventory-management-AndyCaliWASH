/*
* Name: Andres Valencia Cardenas
* Course: Cpts 223, Fall 2025
* Assignment: PA3
* Description: .cpp file for inventory class, includes function definitions.
* Date: 10/18/2025
*/ 

#include "Inventory.h"

Inventory::Inventory()
{
    
}

Inventory::~Inventory()
{

} 

void Inventory::Parse()
{
    ifstream file; 
    string line; 
    //open file
    file.open("Inventory.csv");
    if (!file.is_open())
    {
        cerr << "Error opening file" << endl;
        return; 
    }
    getline(file, line); // skip header line
    
    //parse file
    while(getline(file, line))
    {
        stringstream ss(line); 
        Vector<string> categories; 
        string Id, name, category, cat, buffer;
        getline(ss, Id, ','); 
        getline(ss, name, ','); 
        getline(ss, buffer, ',');
        getline(ss, buffer, ',');
        getline(ss, category, ','); 
     
        if (category == "")
        {
            categories.PushBack("NA"); 
        }
        else 
        {
            stringstream sa(category); 
            while(getline(sa, cat, '|'))
            {
                trim(cat); 
                categories.PushBack(cat); 
            }
        }
        trim(Id); 
        Product product(name); 
        product.setCategories(categories); 
        items_.Insert(Id, product); 
    }

    file.close(); 
}

void Inventory::Find(const string& inventoryId)
{
    auto it = items_.Find(inventoryId);
    const auto& entry = *it; 
    if (it != items_.end())
    {
        cout << "Product Found: " << endl; 
        cout << "Unique ID: " << entry.first<< endl;
        cout << "Name: " << entry.second.GetName() << endl; 
        cout << "Categories: " << endl; 
        for (const auto& category : entry.second.GetCategories()) 
        {
            cout << "> " << category << endl;  
        }
    }
    else 
    {
        cout << "Product not found." << endl; 
    }
}

void Inventory::ListInventory(const string& category)
{
    bool found = false; 
    for (auto it : items_)
    {
        for (const auto& cat : it.second.GetCategories())
        {
            if (cat == category)
            {
                cout << "Product ID: " << it.first << ", Name: " << it.second.GetName() << endl; 
                found = true; 
            }
        }
    }
    if (!found)
    {
        cout << "Invalid Category" << endl;
    }
}

void Inventory::ltrim(string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !isspace(ch);
    }));
}

void Inventory::rtrim(string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base(), s.end());
}

void Inventory::trim(string& s) {
    ltrim(s);
    rtrim(s);
}



