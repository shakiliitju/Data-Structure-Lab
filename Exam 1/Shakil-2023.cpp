
// Md. Shakil Hossain
// Roll - 2023
// Lab Test 1
// Write a c++ program to find the third node from the end in a singly linked list?


#include<bits/stdc++.h>
using namespace std;

void insert_first(int);

struct node
{
    int info;
    struct node *next;
}*start, *temp;


int main()
{
    int v;
    cout<<"Enter value : ";
    cin>>v;
    insert_first(v);

}

void insert_first(int v)
{
    temp=(node*)malloc(sizeof(node));
    temp->info=v;
    temp->next=start;
    start=temp;
}
