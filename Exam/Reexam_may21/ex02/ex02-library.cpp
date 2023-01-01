#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
Elem *reverse(Elem *list)
{
    // Write your code here
    Elem *prev = nullptr;
    Elem *temp = nullptr;
    Elem *current = list;

    while (current != nullptr)
    {
        temp = current->next;
        current->next = prev;
        prev = current;

        current = temp;
    }

    return prev;
}

// Task 2(b).  Implement this function
Elem *concatenate(Elem *list1, Elem *list2)
{
    // Write your code here
    if (list1 == nullptr)
        return list2;
    if (list2 == nullptr)
        return list1;

    Elem *last = list1;
    while (last->next != nullptr)
    {
        last = last->next;
    }
    if (last->value == list2->value)
    {
        last->times += list2->times;
        last->next = list2->next;
        
    }else{
        last->next = list2;
    }
    return list1;
}

// Task 2(c).  Implement this function
int sum(Elem *list)
{
    // Write your code here
    int sum = 0;

    while (list != nullptr)
    {
        sum += list->value * list->times;
        list = list->next;
    }
    return sum;    
}

// Do not modify
void displayRLEList(Elem *list)
{
    if (list == nullptr)
    {
        return;
    }
    cout << " " << list->value << " (x" << list->times << ")";
    displayRLEList(list->next);
}
