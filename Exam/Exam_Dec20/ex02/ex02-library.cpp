#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
unsigned int length(Elem *list) {
    // Write your code here

    int listLength = 0;
    while (list != nullptr)
    {
        listLength += list->times;
        list = list->next;
    }
    return listLength;
}

// Task 2(b).  Implement this function
Elem* append(Elem *list, int v) {
    // Write your code here
    // Elem *first = list;
    // while (list != nullptr)
    // {
    //     if (list->next == nullptr)
    //     {
    //         if (list->value == v)
    //             list->times++;
    //         else{
    //             Elem *e = new Elem;
    //             e->value = v;
    //             e->times = 1;
    //             e->next = nullptr;
    //             list->next = e;     
    //         }
    //         return first;
    //     }
    //     list = list->next;
    // }

    if (list == nullptr) {
        Elem *e = new Elem;
        e->value = v;
        e->times = 1;
        e->next = nullptr;
        return e;
    }

    Elem *last = list;
    while (last->next != nullptr){
        last = last->next;
    }
    if (last->value == v)
        last->times+=1;
    else{
        Elem *newElement = new Elem;
        newElement->value = v;
        newElement->times = 1;
        newElement->next = nullptr;
        last->next = newElement;
    }
    return list;
}



// Task 2(c).  Implement this function
Elem* buildRLEList(int *data, unsigned int n) {
    // Write your code here
    Elem *result = nullptr; // RLE list that will be returned

    for (unsigned int i = 0; i < n; i++) {
        result = append(result, data[i]);
    }
    return result;
}

// Do not modify
void displayRLEList(Elem *list) {
    if (list == nullptr) {
        return;
    }
    cout << " " << list->value << " (x" << list->times << ")";
    displayRLEList(list->next);
}
