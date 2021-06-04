
/// Md. Shakil Hossain
/// Roll - 2023
/// Lab Test 2
/// Question 2

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};


Node* newNode(int V)
{
    Node* node = new Node;
    node->data = V;
    node->left = node->right = NULL;

    return node;
}


Node* insert(Node* root, int V)
{

    if (root == NULL)
    {
        return newNode(V);
    }
    if (V < root->data)
    {
        root->left = insert(root->left, V);
    }
    else
    {
        root->right = insert(root->right, V);
    }

    return root;
}


Node* fMin(Node* root)
{
    while (root->left)
    {
        root = root->left;
    }

    return root;
}


void fSuccessor(Node* root, Node*& succ, int V)
{
    if (root == NULL)
    {
        succ = NULL;
        return;
    }
    if (root->data == V)
    {
        if (root->right)
        {
            succ = fMin(root->right);
        }
    }
    else if (V < root->data)
    {
        succ = root;
        fSuccessor(root->left, succ, V);
    }
    else
    {
        fSuccessor(root->right, succ, V);
    }
}


int main()
{
    int Vs[] = {15,10,20,8,12,16,25};

    Node* root = NULL;
    for (int V: Vs)
    {
        root = insert(root, V);
    }
    for (int V: Vs)
    {
        Node* prec = NULL;
        fSuccessor(root, prec, V);

        if (prec != NULL)
        {
            cout << "The successor of node " << V << " is " << prec->data;
        }
        else
        {
            cout << "The successor doesn't exist for " << V;
        }

        cout << '\n';
    }

    return 0;
}
