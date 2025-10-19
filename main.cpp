/*
* Name: Andres Valencia Cardenas
* Course: Cpts 223, Fall 2025
* Assignment: PA3
* Description: main file for inventory management system, includes REPL implementation.
* Date: 10/18/2025
*/

#include "Inventory.h"
using namespace std;

void printHelp()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
         << endl;
    cout << " Use :quit to quit the REPL" << endl;
}

bool validCommand(string line)
{
    return (line == ":help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0);
}

void evalCommand(string line, Inventory& inventory)
{
    if (line == ":help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        string item = line.substr(5); // extract inventory id
        inventory.Find(item);
    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)
    {
        string category = line.substr(14); 
        inventory.ListInventory(category);
    }
}

void bootStrap(Inventory& inventory)
{
    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    cout << "\n> ";
    inventory.Parse(); 
}

int main(int argc, char const *argv[])
{
    string line;
    Inventory inventory;
    bootStrap(inventory);
    while (getline(cin, line) && line != ":quit")
    {
        if (validCommand(line))
        {
            evalCommand(line, inventory);
        }
        else
        {
            cout << "Command not supported. Enter :help for list of supported commands" << endl;
        }
        cout << "> ";
    }
    return 0;
}
