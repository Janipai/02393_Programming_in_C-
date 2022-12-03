#ifndef __dll__
#define __dll__

#include <iostream>

using namespace std;


class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data);
};

#endif