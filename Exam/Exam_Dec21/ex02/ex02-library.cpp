#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
Passenger *find(Passenger *q, unsigned int ticket)
{
    // Replace the following with your code
    if (q == nullptr)
    {
        return nullptr;
    }else if (q->ticket == ticket) {
        return q;
    } else {
        return find(q->next, ticket);
    }

    // while (q != nullptr)
    // {
    //     if (q->ticket == ticket)
    //     {
    //         return q;
    //     }

    //     q = q->next;
    // }
    // return nullptr;
}

// Task 2(b).  Implement this function
Passenger *remove(Passenger *q, unsigned int ticket)
{
    // Replace the following with your code

    if (q == nullptr){
        return nullptr;
    }else if (q->ticket == ticket) {
        return q->next;
    } else {
         Passenger *p = new Passenger;
        p->name = q->name;
        p->ticket = q->ticket;
        p->priority = q->priority;
        p->next = remove(q->next, ticket);
        return p;
    }
}

// Task 2(c).  Implement this function
Passenger *priority(Passenger *q)
{
    // Replace the following with your code
    if (q == nullptr)
    {
        return nullptr;
    }else if (!q->priority) {
        // We skip the passenger
        return priority(q->next);
    } else {
        Passenger *p = new Passenger();
        p->name = q->name;
        p->priority = q->priority;
        p->ticket = q->ticket;

        p->next = priority(q->next);
        return p;
    }
}

// Do not modify
void displayQueue(Passenger *q)
{
    if (q == nullptr)
    {
        return;
    }
    cout << q->name << " - ticket: " << q->ticket;
    if (q->priority)
    {
        cout << " (priority)";
    }
    cout << endl;
    displayQueue(q->next);
}
