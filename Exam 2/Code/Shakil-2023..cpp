
/// Md. Shakil Hossain
/// Roll - 2023
/// Lab Test 2
/// Question 1


#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *l, *r;

    Node(int data)
    {
        this->data = data;
        this->l = this->r = NULL;
    }
};


bool isNodeP(Node* root, Node* node)
{
    if (root == NULL)
    {
        return false;
    }
    if (root == node)
    {
        return true;
    }
    return isNodeP(root->l, node) ||
           isNodeP(root->r, node);
}


int fLevel(Node *root, Node* node, int level)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    if (root == node)
    {
        return level;
    }
    int l = fLevel(root->l, node, level + 1);

    if (l != INT_MIN)
    {
        return l;
    }
    return fLevel(root->r, node, level + 1);
}


Node* fLCA(Node* root, Node* x, Node* y)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root == x || root == y)
    {
        return root;
    }

    Node* l = fLCA(root->l, x, y);
    Node* r = fLCA(root->r, x, y);
    if (l && r)
    {
        return root;
    }
    if (l)
    {
        return l;
    }
    if (r)
    {
        return r;
    }
}


int fDis(Node *root, Node* x, Node* y)
{
    Node *lca = NULL;
    if (isNodeP(root, y) && isNodeP(root, x))
    {
        lca = fLCA(root, x, y);
    }
    else
    {
        return INT_MIN;
    }
    return fLevel(lca, x, 0) + fLevel(lca, y, 0);

}

int main()
{
    Node* root = NULL;

    root = new Node(1);
    root->l = new Node(2);
    root->r = new Node(3);
    root->l->r = new Node(4);
    root->r->l = new Node(5);
    root->r->r = new Node(6);
    root->r->l->l = new Node(7);
    root->r->r->r = new Node(8);

    cout << "Distance : " << fDis(root, root->r->l->l, root->r->r)<<endl;

    return 0;
}
