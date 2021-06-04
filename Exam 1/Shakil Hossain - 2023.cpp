// Md. Shakil Hossain
// Roll - 2023
// Lab Test 1
// Write a c++ Program to reverse a linked list?

#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* link;
};
struct node* head;

void print()
{
    struct node* temp;
    temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<endl;
        temp = temp ->link;
    }
}
void  rev()
{
    struct node* current = head;
    struct node* pre=NULL;
    struct node* next=NULL;
    while(current !=NULL)
    {
        next=current->link;
        current->link = pre;
        pre= current;
        current = next;
    }
    head=pre;
}
void insert(int value)
{
    struct node* temp= (struct node*)malloc(sizeof(struct node));
    temp ->data = value;
    temp ->link = NULL;
    if(head==NULL)
    {
        head = temp;
    }
    else
    {
        struct node* t;
        t=head;
        while(t -> link != NULL)
        {
            t=t->link;
        }
        t->link = temp;
    }
}
int main()
{
    head=NULL;
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    print();
    rev();
    cout<<endl<<"reverse"<<endl;
    print();
    return 0;
}
