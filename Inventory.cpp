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
        Vector<string> categories; 
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
        while (getline(sa, cat, '|'))
        {
            trim(cat); 
            categories.PushBack(cat);
        } 
        
        trim(uniqueId); 
        trim(name); 
        Product product(name, uniqueId); 
        items_.Insert(categories, product); 
    }

    file.close(); 
}

void Inventory::Find(const string& inventoryId)
{
    for (auto it : items_)
    {
        const auto& entry = it;
        if (entry.second.GetUniqueId() == inventoryId)
        {
            cout << "Product Found: " << endl; 
            cout << "Name: " << entry.second.GetName() << endl; 
            cout << "Unique ID: " << entry.second.GetUniqueId() << endl;
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

void Inventory::Print()
{
    for (const auto& it : items_)
    {
        cout << it.second.GetName() << " " << it.second.GetUniqueId() << endl; 
                    cout << "Categories: " << endl; 
            for (const auto& category : it.first) 
            {
                cout << "> " << category << endl;  
            }
    }
}

void Inventory::ListInventory(const string& category)
{
    bool found = false; 
    for (auto it : items_)
    {
        for (const auto& cat : it.first)
        {
            if (cat == category)
            {
                cout << "Product ID: " << it.second.GetUniqueId() << ", Name: " << it.second.GetName() << endl; 
                found = true; 
            }
        }
    }
    if (!found)
    {
        cout << "Invalid Category" << endl;
    }
}

void Inventory::ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

void Inventory::rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

void Inventory::trim(std::string& s) {
    ltrim(s);
    rtrim(s);
}
