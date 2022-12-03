#include <iostream>
#include "ex03-library.h"

using namespace std;

// Do not modify
Hotel::Hotel()
{
    this->roomNames.push_back("Daisy");
    this->roomOccupancy["Daisy"] = {"Alan Smithee", "xyz890"};

    this->roomNames.push_back("Geranium");

    this->roomNames.push_back("Lotus");
    this->roomOccupancy["Lotus"] = {"Kathryn Bigelow", "456abc"};

    this->roomNames.push_back("Orchid");
    this->roomOccupancy["Orchid"] = {"Alan Smithee", "abc123"};

    this->roomNames.push_back("Tulip");
    this->roomOccupancy["Tulip"] = {"Denis Villeneuve", "123xyz"};
}

// Task 3(a).  Implement this method
void Hotel::renameRoom(string oldName, string newName)
{
    // Write your code here
    for (int i = 0; i < this->roomNames.size(); i++)
    {
        if (this->roomNames.at(i) == oldName)
        {
            this->roomNames.at(i) = newName;

            auto nodeHandler = this->roomOccupancy.extract(oldName);
            nodeHandler.key() = newName;
            this->roomOccupancy.insert(move(nodeHandler));
            return;
        }
    }
}

// Task 3(b).  Implement this method
void Hotel::removeGuest(string roomName, string guestName, string guestId)
{
    // Write your code here
    for (int i = 0; i < this->roomOccupancy.size(); i++)
    {
        if (this->roomOccupancy.find(roomName) != this->roomOccupancy.end())
        {
            this->roomOccupancy.erase(roomName);
        }
    }
}

// Task 3(c).  Implement this method
void Hotel::findRoomByGuestId(vector<string> guestIds)
{
    // Write your code here
    vector<string> rguestIds;

    for (auto p : this->roomOccupancy)
    {
        if (find(guestIds.begin(), guestIds.end(), p.second.id) != guestIds.end())
        {
            rguestIds.push_back(p.first);
        }
    }

    for (int i = rguestIds.size() - 1; i >= 0 ; i--)
    {
        cout << rguestIds.at(i) << endl;
    }
    
}

// Do not modify
void Hotel::display()
{
    for (auto it = this->roomNames.begin(); it != this->roomNames.end(); it++)
    {
        cout << "Room '" << *it << "' is ";
        if (this->roomOccupancy.find(*it) == this->roomOccupancy.end())
        {
            cout << "empty" << endl;
        }
        else
        {
            cout << "occupied by " << this->roomOccupancy[*it].name;
            cout << " (id: " << this->roomOccupancy[*it].id << ")" << endl;
        }
    }
}
