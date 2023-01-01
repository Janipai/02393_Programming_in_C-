#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
GroceryList::GroceryList()
{
    this->items.push_back("Lasagne");
    this->itemsInfo["Lasagne"] = {1, "With eggs if available"};

    this->items.push_back("Salmon");
    this->itemsInfo["Salmon"] = {500, "Smoked if available"};

    this->items.push_back("Spinach");
    this->itemsInfo["Spinach"] = {300, "Fresh"};

    this->items.push_back("Dessert");
    this->itemsInfo["Dessert"] = {8, "Maybe lagkage?"};
}

// Task 3(a).  Implement this method
void GroceryList::add(string name, unsigned int quantity, string notes)
{
    // Write your code here
    if (find(this->items.begin(), this->items.end(), name) != this->items.end())
    {
        this->itemsInfo.at(name).quantity += quantity;
        this->itemsInfo.at(name).notes += ";" + notes;
    }
    else
    {
        this->items.push_back(name);
        Info newIteam;
        newIteam.notes = notes;
        newIteam.quantity = quantity;
        this->itemsInfo.insert({name, newIteam});
    }
}

// Task 3(b).  Implement this method
bool GroceryList::remove(string name, unsigned int quantity){
    // Write your code here
     if(this->itemsInfo.find(name) != this->itemsInfo.end()){
        if(this->itemsInfo.at(name).quantity < quantity){
            return false;
        }
        this->itemsInfo.at(name).quantity -= quantity;
            if(this->itemsInfo.at(name).quantity <= 0){
                for(int i = 0; i < this->items.size(); i++){
                    if(this->items[i].compare(name) == 0){
                        this->items.erase(this->items.begin() + i);
                        break;
                    }
                }
                this->itemsInfo.erase(name);
                return true;
        }
        return true;
    } else
        return false;


}

// Task 3(c).  Implement this method
bool GroceryList::copyEntry(string name, string newName)
{
    // Write your code here

    if (this->itemsInfo.find(newName) != this->itemsInfo.end())
    {
        return false;
    }

    for (auto it = this->items.begin(); it != this->items.end(); it++)
    {
        if (*it == name)
        {
            this->items.push_back(newName);
            this->itemsInfo[newName] = this->itemsInfo[name];
            return true;
        }
    }

    return false;
}

// Do not modify
void GroceryList::display()
{
    // Write your code here
    for (auto it = this->items.begin(); it != this->items.end(); it++)
    {
        Info &item = this->itemsInfo[*it];
        cout << "name='" << *it << "'; ";
        cout << "quantity=" << item.quantity << "; ";
        cout << "notes='" << item.notes << "'" << endl;
    }
}