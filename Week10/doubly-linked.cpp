#include "doubly-linked.h"

using namespace std;

List::List()
{
    first = nullptr;
}
List::~List() {}

void List::insert(int n)
{
    Node *newNode = new Node;
    newNode->val = n;

    if (first == nullptr)
    {
        first = newNode;
        newNode->next = first;
        newNode->prev = first;
    }
    else
    {
        // Traverse till end of list
        Node *temp = first->prev;
        first->prev = newNode;
        temp->next = newNode;

        newNode->prev = temp;
        newNode->next = first;
    }
}
void reverseR(Node *current, Node *&first)
{
    if(first == nullptr){
        return;
    } else if(current != first->prev){
        reverseR(current->next, first);
    }

    Node* temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    if (current == first)
    {
        first = current->next;
    }
        
}
void List::reverse(void)
{
    // Initialize current, previous and next pointers
    reverseR(first, first);
}
void List::print(void)
{
    Node *temp = first;

    // Check for empty list.
    if (first == nullptr)
    {
        return;
    }

    // Traverse the list.
    while (temp != first->prev)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << temp->val << endl;
}