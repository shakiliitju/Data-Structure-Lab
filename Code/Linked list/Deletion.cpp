#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
   int data;
   struct Node* next;
   };

//delete first node in the linked list
Node* deleteFirstNode(struct Node* head)
{
   if (head == NULL)
   return NULL;

   // Move the head pointer to the next node
   Node* tempNode = head;
   head = head->next;
   delete tempNode;

   return head;
}
//delete last node from linked list
Node* removeLastNode(struct Node* head)
{
   if (head == NULL)
   return NULL;

   if (head->next == NULL) {
      delete head;
      return NULL;
   }

// first find second last node
Node* second_last = head;
while (second_last->next->next != NULL)
second_last = second_last->next;

// Delete the last node
delete (second_last->next);

// set next of second_last to null
second_last->next = NULL;

return head;
}

// create linked list by adding nodes at head
void push(struct Node** head, int new_data)
{
   struct Node* newNode = new Node;
   newNode->data = new_data;
   newNode->next = (*head);
   (*head) = newNode;
}

// main function
int main()
{
   /* Start with the empty list */
   Node* head = NULL;

   // create linked list
   push(&head, 2);
   push(&head, 4);
   push(&head, 6);
   push(&head, 8);
   push(&head, 10);

         Node* temp;

   cout<<"Linked list created "<<endl; for (temp = head; temp != NULL; temp = temp->next)
   cout << temp->data << "-->";
   if(temp == NULL)
   cout<<"NULL"<<endl;

       //delete first node
   head = deleteFirstNode(head);
   cout<<"Linked list after deleting head node"<<endl; for (temp = head; temp != NULL; temp = temp->next)
   cout << temp->data << "-->";
   if(temp == NULL)
   cout<<"NULL"<<endl;

      //delete last node
   head = removeLastNode(head);
   cout<<"Linked list after deleting last node"<<endl; for (temp = head; temp != NULL; temp = temp->next)
   cout << temp->data << "-->";
   if(temp == NULL)
   cout<<"NULL";

   return 0;
}
