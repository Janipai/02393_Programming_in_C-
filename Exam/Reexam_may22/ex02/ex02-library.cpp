#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
void shift(Passenger *q, unsigned int n)
{
    // Write your code here
    while (q != nullptr)
    {
        q->row = q->row + n;
        q = q->next;
    }
}

//  Task 2(b).  Implement this function
Passenger *find(Passenger *q, unsigned int rowMin,
                unsigned int rowMax)
{
    // Replace the following with your code
    if (q == nullptr)
    {
        return nullptr;
    }
    else if ((q->row >= rowMin) && (q->row <= rowMax))
    {
        Passenger *p = new Passenger();
        p->name = q->name;
        p->row = q->row;
        p->seat = q->seat;
        p->ticket = q->ticket;

        p->next = find(q->next, rowMin, rowMax);
        return p;
    }
    else
    {
        return find(q->next, rowMin, rowMax);
    }
}

// Task 2(c).  Implement this function
bool occupied(Passenger *q, unsigned int row, char seat)
{
    // Replace the following with your code

    while (q != nullptr)
    {
        if ((q->row == row) && (q->seat == seat))
        {
            return true;
        }
        if (q->next != nullptr)
        {
            q = q->next;
        }
        else
        {
            return false;
        }
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
    cout << ", seat " << q->row << q->seat << endl;
    displayQueue(q->next);
}
