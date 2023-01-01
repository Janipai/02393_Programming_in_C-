#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
Locker::Locker() {
    this->lockerIDs.push_back("LYNGBY01");
    this->lockerOccupancy["LYNGBY01"] = {"Alice", "Daisy", 1234};

    this->lockerIDs.push_back("LYNGBY02");
    this->lockerOccupancy["LYNGBY02"] = {"Claire", "Alice", 567};

    this->lockerIDs.push_back("LYNGBY03");
    this->lockerOccupancy["LYNGBY03"] = {"Daisy", "Bob", 890};

    this->lockerIDs.push_back("LYNGBY04");

    this->lockerIDs.push_back("LYNGBY05");
    this->lockerOccupancy["LYNGBY05"] = {"Bob", "Daisy", 159};

    this->lockerIDs.push_back("LYNGBY06");
}

// Task 3(a).  Implement this method
void Locker::putPackage(string lockerID, string sender, string recipient, int unlockCode) {
    // Write your code here
    if(lockerOccupancy.find(lockerID)!=lockerOccupancy.end()){
        return;
    }else{
        Package p;
        p.sender = sender;
        p.recipient = recipient;
        p.unlockCode = unlockCode;
        lockerOccupancy[lockerID] = p;
    }
}

// Task 3(b).  Implement this method
//Segmentation fault???
void Locker::retrievePackage(string lockerID, int unlockCode) {
    // Write your code here
    for (auto x : lockerOccupancy){
        if (x.first == lockerID)
            if( x.second.unlockCode == unlockCode)
                lockerOccupancy.erase(lockerID);
    }
}

// Task 3(c).  Implement this method
void Locker::findPackagesByRecipient(vector<string> recipients) {
    // Write your code here
    
    for( auto x: lockerOccupancy){
        for (int i = 0; i < recipients.size(); i++){
            if (x.second.recipient == recipients[i])
                cout << x.first << endl;
        }
    }    
}

// Do not modify
void Locker::display() {
    for (auto it = this->lockerIDs.begin(); it != this->lockerIDs.end(); it++) {
        cout << "Locker '" << *it << "' ";
        if (this->lockerOccupancy.find(*it) == this->lockerOccupancy.end()) {
            cout << "is empty" << endl;
        } else {
            cout << "contains a package from " << this->lockerOccupancy[*it].sender;
            cout << " to " << this->lockerOccupancy[*it].recipient;
            cout << " (unlock code: " << this->lockerOccupancy[*it].unlockCode << ")" << endl;
        }
    }
}
