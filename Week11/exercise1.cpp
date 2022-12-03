#include <iostream>
#include "exercise1.h"

using namespace std;

Node::Node(int n)
{
    this->left = this->right = NULL;
    if (n <= 1)
    {
        this->data = 1;
    }
    else
    {
        this->left = new Node(n - 1);
        this->right = new Node(n - 2);
        this->data = this->left->data + this->right->data;
    }
}

void preorder(Node *node)
{
    if (node == NULL)
        return;

    /* first print data of node */
    cout << node->data << " ";

    /* then recur on left subtree */
    preorder(node->left);

    /* now recur on right subtree */
    preorder(node->right);
}
int size(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        return (size(node->left) + 1 + size(node->right));
    }
}
int depth(Node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = depth(node->left);
        int rDepth = depth(node->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}
int leaves(Node *node)
{
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL)
        return 1;
    else
        return leaves(node->left) +
               leaves(node->right);
}

int main()
{
    int n;
    cin >> n;

    Node *tree = new Node(n);
    cout << "Call tree in pre-order: " ;
    preorder(tree);
    cout << endl;
    cout << "Call tree size: " << size(tree) << endl;
    cout << "Call tree depth: " << depth(tree) << endl;
    cout << "Call tree leafs: " <<leaves(tree) << endl;
}